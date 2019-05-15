#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_OPERATINGSYSTEMMODEL_H
#define SYSTEMRAT_MODELS_WIN32_OPERATINGSYSTEMMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_OperatingSystemModel final : public IModel
		{
		public:
			explicit Win32_OperatingSystemModel() = default;
			virtual ~Win32_OperatingSystemModel() = default;

			std::string& nuildNumber();
			std::string& buildType();
			std::string& countryCode();
			std::string& currentTimezone();
			std::string& description();
			std::string& freePhysicalMemory();
			std::string& freeSpaceInPagingFiles();
			std::string& freeVirtualMemory();
			std::string& installDate();
			std::string& manufacturer();
			std::string& maxNumberOfProcesses();
			std::string& maxProcessesMemorySize();
			std::string& name();
			std::string& numberOfLicensedUsers();
			std::string& numberOfProcesses();
			std::string& numberOfUsers();
			std::string& organization();
			std::string& serialNumber();
			std::string& servicePackMajorVersion();
			std::string& servicePackMinorVersion();
			std::string& status();
			std::string& systemDevice();
			std::string& systemDrive();
			std::string& totalVirtualMemorySize();
			std::string& totalVisibleMemorySize();
			std::string& version();
			std::string& windowsDirectory();

		private:
			std::string m_buildNumber;
			std::string m_buildType;
			std::string m_countryCode;
			std::string m_currentTimeZone;
			std::string m_description;
			std::string m_freePhysicalMemory;
			std::string m_freeSpaceInPagingFiles;
			std::string m_freeVirtualMemory;
			std::string m_installDate;
			std::string m_manufacturer;
			std::string m_maxNumberOfProcesses;
			std::string m_maxProcessMemorySize;
			std::string m_name;
			std::string m_numberOfLicensedUsers;
			std::string m_numberOfProcesses;
			std::string m_numberOfUsers;
			std::string m_organization;
			std::string m_serialNumber;
			std::string m_servicePackMajorVersion;
			std::string m_servicePackMinorVersion;
			std::string m_status;
			std::string m_systemDevice;
			std::string m_systemDirectory;
			std::string m_systemDrive;
			std::string m_totalVirtualMemorySize;
			std::string m_totalVisibleMemorySize;
			std::string m_version;
			std::string m_windowsDirectory;
		};
	}
}

#endif