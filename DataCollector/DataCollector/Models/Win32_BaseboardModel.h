#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_BASEBOARDMODEL_H
#define SYSTEMRAT_MODELS_WIN32_BASEBOARDMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_BaseboardModel : public IModel
		{
		public:
			explicit Win32_BaseboardModel() = default;
			virtual ~Win32_BaseboardModel() = default;

			std::string& depth();
			std::string& description();
			std::string& height();
			bool& hostingBoard();
			std::string& installDate();
			std::string& manufacturer();
			std::string& model();
			std::string& name();
			std::string& partNUmber();
			bool& poweredOn();
			std::string& product();
			bool& removable();
			bool& repleacable();
			std::string& requirementsDescription();
			bool& requiresDaughterBoard();
			std::string& serialNumber();
			std::string& slotLayout();
			std::string& specialRequirements();
			std::string& status();
			std::string& weight();
			std::string& width();

		private:
			std::string m_depth;
			std::string m_descriotion;
			std::string m_height;
			bool        m_hostingBoard;
			std::string m_installDate;
			std::string m_manufacturer;
			std::string m_model;
			std::string m_name;
			std::string m_partNumber;
			bool        m_poweredOn;
			std::string m_product;
			bool        m_removable;
			bool        m_replaceable;
			std::string m_requirementDescription;
			bool        m_requiresDaughterBoard;
			std::string m_serialNumber;
			std::string m_slotLayout;
			std::string m_specialRequirements;
			std::string m_status;
			std::string m_weight;
			std::string m_width;
		};
	}
}

#endif