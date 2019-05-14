#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_KEYBOARDMODEL_H
#define SYSTEMRAT_MODELS_WIN32_KEYBOARDMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_KeyboardModel final : public IModel
		{
		public:
			explicit Win32_KeyboardModel() = default;
			virtual ~Win32_KeyboardModel() = default;

			std::string& availability();
			std::string& description();
			std::string& deviceId();
			std::string& errorDecription();
			std::string& installDate();
			bool& isLocked();
			std::string& lastErrorCode();
			std::string& name();
			std::string& numberOfFunctionKeys();
			std::string& password();
			bool& powerManagementSupported();

		private:
			std::string m_availability;
			std::string m_description;
			std::string m_deviceId;
			std::string m_errorDescription;
			std::string m_installDate;
			bool        m_isLocked;
			std::string m_lastErrorCode;
			std::string m_name;
			std::string m_numberOfFunctionKeys;
			std::string m_password;
			bool        m_powerManagementSupported;
		};
	}
}

#endif