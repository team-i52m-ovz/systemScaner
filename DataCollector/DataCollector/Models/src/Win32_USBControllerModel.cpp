#include "../Win32_USBControllerModelh.h"

using namespace SystemRat::Models;

std::string& Win32_USBControllerModel::description()
{
	return m_description;
}

std::string& Win32_USBControllerModel::deviceId()
{
	return m_deviceId;
}

std::string& Win32_USBControllerModel::errorDescription()
{
	return m_errorDescription;
}

std::string& Win32_USBControllerModel::installDate()
{
	return m_installDate;
}

std::string& Win32_USBControllerModel::manufacturer()
{
	return m_manufacturer;
}

std::string& Win32_USBControllerModel::maxNumberControlled()
{
	return m_maxNumberControlled;
}

std::string& Win32_USBControllerModel::name()
{
	return m_name;
}

bool& Win32_USBControllerModel::powerManagementSupported()
{
	return m_powerManagementSupported;
}

std::string& Win32_USBControllerModel::protocolSupported()
{
	return m_protocolSupported;
}

std::string& Win32_USBControllerModel::status()
{
	return m_status;
}