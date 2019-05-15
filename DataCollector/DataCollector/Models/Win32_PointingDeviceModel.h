#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_POINTINGDEVICEMODEL_H
#define SYSTEMRAT_MODELS_WIN32_POINTINGDEVICEMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_PointingDeviceModel final : public IModel
		{
		public:
			explicit Win32_PointingDeviceModel() = default;
			virtual ~Win32_PointingDeviceModel() = default;

			std::string& availability();
			std::string& configManagerErrorCode();
			std::string& deviceId();
			std::string& errorDescription();
			std::string& handedness();
			std::string& hardwareType();
			std::string& installDate();
			bool&        isLocked();
			std::string& manufacturer();
			std::string& name();
			std::string& numberOfButtons();
			bool&        powerManagementSupported();
			std::string& resolution();

		private:
			std::string m_availability;
			std::string m_configManagerErrorCode;
			std::string m_deviceId;
			std::string m_errorDescription;
			std::string m_handedness;
			std::string m_hardwareType;
			std::string m_installDate;
			bool        m_isLocked;
			std::string m_manufacturer;
			std::string m_name;
			std::string m_numberOfButtons;
			bool        m_powerManagementSupported;
			std::string m_resolution;
		};
	}
}

#endif