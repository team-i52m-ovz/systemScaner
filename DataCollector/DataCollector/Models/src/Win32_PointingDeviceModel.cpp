#include "../Win32_PointingDeviceModel.h"

using namespace SystemRat::Models;

std::string& Win32_PointingDeviceModel::availability()
{
	return m_availability;
}

std::string& Win32_PointingDeviceModel::configManagerErrorCode()
{
	return m_configManagerErrorCode;
}

std::string& Win32_PointingDeviceModel::deviceId()
{
	return m_deviceId;
}

std::string& Win32_PointingDeviceModel::errorDescription()
{
	return m_errorDescription;
}

std::string& Win32_PointingDeviceModel::handedness()
{
	return m_handedness;
}

std::string& Win32_PointingDeviceModel::hardwareType()
{
	return m_hardwareType;
}

std::string& Win32_PointingDeviceModel::installDate()
{
	return m_installDate;
}

bool&        Win32_PointingDeviceModel::isLocked()
{
	return m_isLocked;
}

std::string& Win32_PointingDeviceModel::manufacturer()
{
	return m_manufacturer;
}

std::string& Win32_PointingDeviceModel::name()
{
	return m_name;
}

std::string& Win32_PointingDeviceModel::numberOfButtons()
{
	return m_numberOfButtons;
}

bool&        Win32_PointingDeviceModel::powerManagementSupported()
{
	return m_powerManagementSupported;
}

std::string& Win32_PointingDeviceModel::resolution()
{
	return m_resolution;
}