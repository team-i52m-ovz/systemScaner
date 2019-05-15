#include "../Win32_UserAccountModel.h"

using namespace SystemRat::Models;

std::string& Win32_UserAccountModel::accountType()
{
	return m_accountType;
}

std::string& Win32_UserAccountModel::description()
{
	return m_description;
}

std::string& Win32_UserAccountModel::fullName()
{
	return m_fullName;
}

std::string& Win32_UserAccountModel::installDate()
{
	return m_installDate;
}

bool& Win32_UserAccountModel::localAccount()
{
	return m_localAccount;
}

bool& Win32_UserAccountModel::lockout()
{
	return m_lockout;
}

std::string& Win32_UserAccountModel::name()
{
	return m_name;
}

bool& Win32_UserAccountModel::passwordChangeable()
{
	return m_passwordChangeable;
}

bool& Win32_UserAccountModel::passwordExpires()
{
	return m_passwordExpires;
}

bool& Win32_UserAccountModel::passwordRequired()
{
	return m_passwordRequired;
}

std::string& Win32_UserAccountModel::SID()
{
	return m_SID;
}

std::string& Win32_UserAccountModel::status()
{
	return m_status;
}