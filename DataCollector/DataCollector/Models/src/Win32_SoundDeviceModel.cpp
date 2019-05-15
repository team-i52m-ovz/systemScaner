#include "../Win32_SoundDeviceModel.h"

using namespace SystemRat::Models;

std::string& Win32_SoundDeviceModel::availibility()
{
	return m_availibility;
}

std::string& Win32_SoundDeviceModel::dmaBufferSIze()
{
	return m_dmaBufferSize;
}

std::string& Win32_SoundDeviceModel::deviceId()
{
	return m_deviceId;
}

std::string& Win32_SoundDeviceModel::installDate()
{
	return m_installDate;
}

std::string& Win32_SoundDeviceModel::mpu401Address()
{
	return m_mpu401Address;
}

std::string& Win32_SoundDeviceModel::manufacturer()
{
	return m_manufacturer;
}

std::string& Win32_SoundDeviceModel::name()
{
	return m_name;
}

bool& Win32_SoundDeviceModel::powerManagementSupported()
{
	return m_powerManagementSupported;
}

std::string& Win32_SoundDeviceModel::productName()
{
	return m_productName;
}