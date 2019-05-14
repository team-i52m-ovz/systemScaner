#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_USBCONTROLLERMODEL_H
#define SYSTEMRAT_MODELS_WIN32_USBCONTROLLERMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_USBControllerModel final : public IModel
		{
		public:
			explicit Win32_USBControllerModel() = default;
			virtual ~Win32_USBControllerModel() = default;

			std::string& description();
			std::string& deviceId();
			std::string& errorDescription();
			std::string& installDate();
			std::string& manufacturer();
			std::string& maxNumberControlled();
			std::string& name();
			bool&        powerManagementSupported();
			std::string& protocolSupported();
			std::string& status();

		private:
			std::string m_description;
			std::string m_deviceId;
			std::string m_errorDescription;
			std::string m_installDate;
			std::string m_manufacturer;
			std::string m_maxNumberControlled;
			std::string m_name;
			bool        m_powerManagementSupported;
			std::string m_protocolSupported;
			std::string m_status;
		};
	}
}


#endif