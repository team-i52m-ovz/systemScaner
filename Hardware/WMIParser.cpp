#include "WMIParser.h"

#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>

using namespace SystemRat;

std::string ws2s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}

WMIParser::WMIParser(std::unordered_map<std::string, std::unordered_map<std::string, std::list<std::string>>>& dataToBeQueried)
	:m_dataToBeQueried{ dataToBeQueried }
	,m_pSvc{nullptr}
	, m_pLoc{nullptr}
{}

int WMIParser::init()
{
	HRESULT hres;

	// Step 1: --------------------------------------------------
	// Initialize COM. ------------------------------------------

	hres = CoInitializeEx(0, COINIT_MULTITHREADED);
	if (FAILED(hres))
	{
		std::cout << "Failed to initialize COM library. Error code = 0x"
			<< std::hex << hres << std::endl;
		return 1;                  // Program has failed.
	}

	// Step 2: --------------------------------------------------
	// Set general COM security levels --------------------------

	hres = CoInitializeSecurity(
		NULL,
		-1,                          // COM authentication
		NULL,                        // Authentication services
		NULL,                        // Reserved
		RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication 
		RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation  
		NULL,                        // Authentication info
		EOAC_NONE,                   // Additional capabilities 
		NULL                         // Reserved
	);


	if (FAILED(hres))
	{
		std::cout << "Failed to initialize security. Error code = 0x"
			<< std::hex << hres << std::endl;
		CoUninitialize();
		return 1;                    // Program has failed.
	}

	// Step 3: ---------------------------------------------------
	// Obtain the initial locator to WMI -------------------------

	hres = CoCreateInstance(
		CLSID_WbemLocator,
		0,
		CLSCTX_INPROC_SERVER,
		IID_IWbemLocator, (LPVOID *)&m_pLoc);

	if (FAILED(hres))
	{
		std::cout << "Failed to create IWbemLocator object."
			<< " Err code = 0x"
			<< std::hex << hres << std::endl;
		CoUninitialize();
		return 1;                 // Program has failed.
	}

	// Step 4: -----------------------------------------------------
	// Connect to WMI through the IWbemLocator::ConnectServer method

	// Connect to the root\cimv2 namespace with
	// the current user and obtain pointer pSvc
	// to make IWbemServices calls.
	hres = m_pLoc->ConnectServer(
		_bstr_t(L"ROOT\\CIMV2"), // Object path of WMI namespace
		NULL,                    // User name. NULL = current user
		NULL,                    // User password. NULL = current
		0,                       // Locale. NULL indicates current
		NULL,                    // Security flags.
		0,                       // Authority (for example, Kerberos)
		0,                       // Context object 
		&m_pSvc                    // pointer to IWbemServices proxy
	);

	if (FAILED(hres))
	{
		std::cout << "Could not connect. Error code = 0x"
			<< std::hex << hres << std::endl;
		m_pLoc->Release();
		CoUninitialize();
		return 1;                // Program has failed.
	}

	// Step 5: --------------------------------------------------
	// Set security levels on the proxy -------------------------

	hres = CoSetProxyBlanket(
		m_pSvc,                        // Indicates the proxy to set
		RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
		RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
		NULL,                        // Server principal name 
		RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx 
		RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
		NULL,                        // client identity
		EOAC_NONE                    // proxy capabilities 
	);

	if (FAILED(hres))
	{
		std::cout << "Could not set proxy blanket. Error code = 0x"
			<< std::hex << hres << std::endl;
		m_pSvc->Release();
		m_pLoc->Release();
		CoUninitialize();
		return 1;               // Program has failed.
	}
	return 0;
}

int WMIParser::queryData()
{
	for (auto &it : m_dataToBeQueried)
	{
			for (auto &iter : it.second)
			{
				std::string queryString = "SELECT * FROM ";
				std::string wmiClassName = iter.first;
				queryString.append(wmiClassName);
				IEnumWbemClassObject* pEnumerator = NULL;
				HRESULT hres = m_pSvc->ExecQuery(
					bstr_t("WQL"),
					bstr_t(queryString.data()),
					WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
					NULL,
					&pEnumerator);

				if (FAILED(hres))
				{
					std::cout << "Query for operating system name failed."
						<< " Error code = 0x"
						<< std::hex << hres << std::endl;
					m_pSvc->Release();
					m_pLoc->Release();
					CoUninitialize();
					return 1;               // Program has failed.
				}
				
				IWbemClassObject *pclsObj = NULL;
				ULONG uReturn = 0;
				int counter = 0;
				m_jsonParser[it.first][iter.first] = {};
				while (pEnumerator && counter < 100)
				{
					std::unordered_map<std::string, std::string> toFill;
					++counter;
					HRESULT hr = pEnumerator->Next(30000, 1, &pclsObj, &uReturn);

					if (0 == uReturn)
					{
						break;
					}

					for (auto &item : iter.second)
					{
						VARIANT vtProp;
						std::wstring q{ item.begin(), item.end() };
						// Get the value of the Name property
						hr = pclsObj->Get(q.data(), 0, &vtProp, 0, 0);
						std::wstring outData;
						getDataFromVariant(vtProp, outData);
						std::wcout << outData << std::endl;
						VariantClear(&vtProp);

						//pEnumerator->Release();
						toFill.emplace(item, ws2s(outData));
					}
					m_jsonParser[it.first][iter.first].push_back(json{toFill});
					toFill.clear();
				}
				if (pEnumerator)
				{
					pEnumerator->Release();
				}
				if (pclsObj)
				{
					pclsObj->Release();
				}
			}
	}
	m_pSvc->Release();
	m_pLoc->Release();
	CoUninitialize();
	return 0;
}

void WMIParser::getDataFromVariant(VARIANT variant, std::wstring& outData)
{
	switch (variant.vt)
	{
	case VT_EMPTY:
	case VT_NULL:
	case VT_UNKNOWN:
	case VT_ERROR:
	{
		return;
	}
	case VT_I1:
	case VT_I2:
	case VT_I4:
	case VT_I8:
		outData = std::to_wstring(variant.iVal);
		break;
	case VT_R4:
	case VT_R8:
		outData = std::to_wstring(variant.fltVal);
		break;
	case VT_DATE:
		outData = std::to_wstring(variant.date);
		break;
	case VT_BSTR:
		outData = variant.bstrVal;
		break;
	case VT_BOOL:
	{
		if (variant.boolVal)
		{
			outData = L"true";
			break;
		}
		outData = L"false";
		break;
	}
	case VT_UI1:
	case VT_UI2:
	case VT_UI4:
	case VT_UI8:
		outData = std::to_wstring(variant.uiVal);
		break;
	case VT_INT:
		outData = std::to_wstring(variant.intVal);
		break;
	case VT_UINT:
		outData = std::to_wstring(variant.uintVal);
		break;
	default: return;
	}
}


std::string WMIParser::generateJson()
{
	return m_jsonParser.dump();
}