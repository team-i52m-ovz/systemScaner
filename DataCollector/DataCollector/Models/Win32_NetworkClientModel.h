#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_NETWORKCLIENTMODEL_H
#define SYSTEMRAT_MODELS_WIN32_NETWORKCLIENTMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_NetworkClientModel final : public IModel
		{
		public:
			explicit Win32_NetworkClientModel() = default;
			virtual ~Win32_NetworkClientModel() = default;

			std::string& caption();
			std::string& description();
			std::string& installDate();
			std::string& manufacturer();
			std::string& name();
			std::string& status();
		private:
			std::string m_caption;
			std::string m_description;
			std::string m_installDate;
			std::string m_manufacturer;
			std::string m_name;
			std::string m_status;
		};
	}
}

#endif