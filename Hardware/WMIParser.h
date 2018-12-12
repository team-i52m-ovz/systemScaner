#pragma once
#ifndef WMIPARSER_H
#define WMIPARSER_H

#define _WIN32_DCOM
#include <list>
#include <string>
#include <unordered_map>
#include <single_include/nlohmann/json.hpp>

#include <comdef.h>
#include <Wbemidl.h>

#pragma comment(lib, "wbemuuid.lib")

namespace SystemRat
{
	using json = nlohmann::json;

	class WMIParser final
	{
	public:
		explicit WMIParser(std::unordered_map<std::string,std::unordered_map<std::string, std::list<std::string>>>& dataToBeQueried);
		~WMIParser() = default;

		int init();
		int queryData();
		void generateFile(std::string fileName);
	private:
		void getDataFromVariant(VARIANT variant, std::wstring& outData);

	private:
		json m_jsonParser;
		std::unordered_map<std::string, std::unordered_map<std::string, std::list<std::string>>>& m_dataToBeQueried;
		IWbemServices* m_pSvc;
		IWbemLocator* m_pLoc;
	};
}

#endif