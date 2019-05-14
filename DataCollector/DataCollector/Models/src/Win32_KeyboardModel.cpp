#include "../Win32_KeyboardModel.h"

using namespace SystemRat::Models;

std::string& Win32_KeyboardModel::availability()
{
	return m_availability;
}

std::string& Win32_KeyboardModel::description()
{
	return m_description;
}

std::string& Win32_KeyboardModel::deviceId()
{
	return m_deviceId;
}

std::string& Win32_KeyboardModel::errorDecription()
{
	return m_errorDescription;
}

std::string& Win32_KeyboardModel::installDate()
{
	return m_installDate;
}

bool& Win32_KeyboardModel::isLocked()
{
	return m_isLocked;
}

std::string& Win32_KeyboardModel::lastErrorCode()
{
	return m_lastErrorCode;
}

std::string& Win32_KeyboardModel::name()
{
	return m_name;
}

std::string& Win32_KeyboardModel::numberOfFunctionKeys()
{
	return m_numberOfFunctionKeys;
}

std::string& Win32_KeyboardModel::password()
{
	return m_password;
}

bool& Win32_KeyboardModel::powerManagementSupported()
{
	return m_powerManagementSupported;
}