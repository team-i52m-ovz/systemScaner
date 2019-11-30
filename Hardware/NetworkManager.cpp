#include "NetworkManager.h"
#include "WinHttpClient.h"

#include <iostream>

using namespace JPC::Network;

static const int defaultPort = 27045;

NetworkManager::NetworkManager()
{
	m_isInitialized = false;
}

NetworkManager::~NetworkManager()
{
	/*auto& threadPool = JPC::ThreadPool::ThreadPool::getInstance();
	threadPool.finalize();*/
}

NetworkManager& NetworkManager::getInstance()
{
	static NetworkManager m_instance;
	return m_instance;
}

bool NetworkManager::initialize(std::string host)
{
	if (!m_isInitialized)
	{
		m_host = host;
		//m_httpClient->initialize();
		//m_httpClient->connect("75ea9f71.ngrok.io", defaultPort);
		m_isInitialized = true;
	}
	
	return true;
}

void NetworkManager::finalize()
{

}

bool NetworkManager::sendFile(std::string content)
{
	std::string response;
	std::wstring host{ m_host.begin(), m_host.end() };
	host.append(L"/api/v1/scanner/report");
	WinHttpClient client(host);
	std::wstring headers{ m_cookie.begin(), m_cookie.end() };
	headers.append(L"\r\nContent-Type: application/json\r\n");
	client.SetAdditionalRequestHeaders(headers);
	client.SetAdditionalDataToSend((BYTE *)content.data(), content.size());
	client.SendHttpRequest(L"POST");

	return true;
}

bool NetworkManager::getToken(std::function<void(std::string)> callback)
{
	std::string response;
	std::wstring host{ m_host.begin(), m_host.end() };
	host.append(L"/api/v1/scanner");
	WinHttpClient client(host);
	std::wstring headers{ m_cookie.begin(), m_cookie.end() };
	client.SetAdditionalRequestHeaders(headers);
	client.SendHttpRequest(L"POST");
	std::wstring httpResponseHeader = client.GetResponseHeader();
	std::wstring lookingFor{ L"X-Scanner: " };
	size_t tokenPos = httpResponseHeader.find(lookingFor);
	size_t nextHeaderPos = httpResponseHeader.find(L"\r\n", tokenPos);
	if (tokenPos == std::wstring::npos)
	{
		return false;
	}
	std::wstring wtoken = httpResponseHeader.substr(tokenPos + lookingFor.size(), nextHeaderPos - tokenPos - lookingFor.size());
	callback(std::string{wtoken.begin(), wtoken.end()});

	return true;
}

bool NetworkManager::setToken(std::string token)
{
	if (token.empty())
	{
		m_cookie = "X-Secret: MSeCb8EVEx5SMZnT89BL";
	}
	else
	{
		m_cookie = std::string{ "X-Scanner: " }.append(token);
	}
	
	return true;
}