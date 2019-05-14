#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_SOUNDDEVICEMODEL_H
#define SYSTEMRAT_MODELS_WIN32_SOUNDDEVICEMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_SoundDeviceModel final : public IModel
		{
		public:
			explicit Win32_SoundDeviceModel() = default;
			virtual ~Win32_SoundDeviceModel() = default;

			std::string& availibility();
			std::string& dmaBufferSIze();
			std::string& deviceId();
			std::string& installDate();
			std::string& mpu401Address();
			std::string& manufacturer();
			std::string& name();
			bool&        powerManagementSupported();
			std::string& productName();

		private:
			std::string m_availibility;
			std::string m_dmaBufferSize;
			std::string m_deviceId;
			std::string m_installDate;
			std::string m_mpu401Address;
			std::string m_manufacturer;
			std::string m_name;
			bool        m_powerManagementSupported;
			std::string m_productName;
		};
	}
}


#endif