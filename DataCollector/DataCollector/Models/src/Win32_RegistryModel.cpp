#include "../Win32_RegistryModel.h"

using namespace SystemRat::Models;

std::string& Win32_RegistryModel::currentSize()
{
	return m_currentSize;
}

std::string& Win32_RegistryModel::description()
{
	return m_description;
}

std::string& Win32_RegistryModel::installDate()
{
	return m_installDate;
}

std::string& Win32_RegistryModel::maximumSize()
{
	return m_maximumSize;
}

std::string& Win32_RegistryModel::name()
{
	return m_name;
}

std::string& Win32_RegistryModel::status()
{
	return m_status;
}