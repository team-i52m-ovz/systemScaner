#pragma once
#ifndef SYSTEMRAT_WIN32_COMPUTERSYSTEMMODEL_H
#define SYSTEMRAT_WIN32_COMPUTERSYSTEMMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_ComputerSystemModel final : public IModel
		{
		public:
			explicit Win32_ComputerSystemModel() = default;
			virtual ~Win32_ComputerSystemModel() = default;

			std::string& adminPasswordStatus();
			std::string& bootupState();
			std::string& caption();
			std::string& creationClassName();
			std::string& dnsHostName();
			std::string& domain();
			std::string& lastLoadInfo();
			std::string& manufacturer();
			std::string& model();
			std::string& name();
			bool&        powerManagementSupported();
			std::string& numberOfLogicalProcessors();
			std::string& numberOfProcessors();
			bool&        networkServerModelEnabled();
			std::string& primaryOwnerName();
			std::string& systemFamily();
			std::string& username();
			std::string& wakeUpType();
			std::string& workgroup();

		private:
			std::string m_adminPasswordStatus;
			std::string m_bootupState;
			std::string m_caption;
			std::string m_creationClassName;
			std::string m_dnsHostName;
			std::string m_domain;
			std::string m_lastLoadInfo;
			std::string m_manufacturer;
			std::string m_model;
			std::string m_name;
			bool        m_networkServerModeEnabled;
			std::string m_numberOfLogicalProcessors;
			std::string m_numberOfProcessors;
			bool        m_powerManagementSupported;
			std::string m_primaryOwnerName;
			std::string m_systemFamily;
			std::string m_username;
			std::string m_wakeUpType;
			std::string m_workgroup;
		};
	}
}

#endif