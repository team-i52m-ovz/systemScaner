#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_REGISTRYMODEL_H
#define SYSTEMRAT_MODELS_WIN32_REGISTRYMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_RegistryModel final : public IModel
		{
		public:
			explicit Win32_RegistryModel() = default;
			virtual ~Win32_RegistryModel() = default;

			std::string& currentSize();
			std::string& description();
			std::string& installDate();
			std::string& maximumSize();
			std::string& name();
			std::string& status();
		private:
			std::string m_currentSize;
			std::string m_description;
			std::string m_installDate;
			std::string m_maximumSize;
			std::string m_name;
			std::string m_status;
		};
	}
}

#endif