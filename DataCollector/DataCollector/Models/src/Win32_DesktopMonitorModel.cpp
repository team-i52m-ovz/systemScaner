#include "../Win32_DesktopMonitorModel.h"

using namespace SystemRat::Models;

std::string& Win32_DesktopMonitorModel::availability()
{
	return m_availability;
}

std::string& Win32_DesktopMonitorModel::description()
{
	return m_description;
}

std::string& Win32_DesktopMonitorModel::deviceId()
{
	return m_deviceId;
}

bool& Win32_DesktopMonitorModel::isLocked()
{
	return m_isLocked;
}

std::string& Win32_DesktopMonitorModel::monitorManufacturer()
{
	return m_monitorManufacturer;
}

std::string& Win32_DesktopMonitorModel::name()
{
	return m_name;
}

std::string& Win32_DesktopMonitorModel::pixelsPerXLogicalInch()
{
	return m_pixelsPerXLogicalInch;
}

std::string& Win32_DesktopMonitorModel::pixelsPerYLogicalInch()
{
	return m_pixelsPerYLogicalInch;
}

bool& Win32_DesktopMonitorModel::powerManagementSupported()
{
	return m_powerManagementSupported;
}

std::string& Win32_DesktopMonitorModel::screenHeight()
{
	return m_screenHeight;
}

std::string& Win32_DesktopMonitorModel::screenWidth()
{
	return m_screenWidth;
}