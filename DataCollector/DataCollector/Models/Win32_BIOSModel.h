#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_BIOS_H
#define SYSTEMRAT_MODELS_WIN32_BIOS_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_BIOSModel : public IModel
		{
		public:
			explicit Win32_BIOSModel() = default;
			virtual ~Win32_BIOSModel() = default;

			std::string& buildNUmber();
			std::string& codeSet();
			std::string& currentLangudge();
			std::string& description();
			std::string& embeddedControllerMajorVersion();
			std::string& embeddedControllerMinorVersion();
			std::string& installDate();
			std::string& manufacturer();
			std::string& name();
			bool&        primaryBios();
			std::string& serialNumber();
			std::string& softwareElementId();
			std::string& systemBiosMajorVersion();
			std::string& systemBiosMinorVersion();
			std::string& targetOperatingSystem();
			std::string& version();
		private:
			std::string m_buildNumber;
			std::string m_codeSet;
			std::string m_currentLanguage;
			std::string m_description;
			std::string m_embeddedControllerMajorVersion;
			std::string m_embeddedControllerMinorVersion;
			std::string m_installDate;
			std::string m_manufacturer;
			std::string m_name;
			bool        m_primaryBios;
			std::string m_serialNumber;
			std::string m_softwareElementId;
			std::string m_systemBiosMajorVersion;
			std::string m_systemBiosMinorVersion;
			std::string m_targetOperatingSystem;
			std::string m_version;
		};
	}
}

#endif