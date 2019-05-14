#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_USERACCOUNTMODEL_H
#define SYSTEMRAT_MODELS_WIN32_USERACCOUNTMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_UserAccountModel final : public IModel
		{
		public:
			explicit Win32_UserAccountModel() = default;
			virtual ~Win32_UserAccountModel() = default;

			std::string& accountType();
			std::string& description();
			std::string& fullName();
			std::string& installDate();
			bool&        localAccount();
			bool&        lockout();
			std::string& name();
			bool&        passwordChangeable();
			bool&        passwordExpires();
			bool&        passwordRequired();
			std::string& SID();
			std::string& status();

		private:
			std::string m_accountType;
			std::string m_description;
			std::string m_fullName;
			std::string m_installDate;
			bool        m_localAccount;
			bool        m_lockout;
			std::string m_name;
			bool        m_passwordChangeable;
			bool        m_passwordExpires;
			bool        m_passwordRequired;
			std::string m_SID;
			std::string m_status;
		};
	}
}

#endif