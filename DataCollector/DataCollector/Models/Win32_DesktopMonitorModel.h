#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_DESKTOPMONITORMODEL_H
#define SYSTEMRAT_MODELS_WIN32_DESKTOPMONITORMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_DesktopMonitorModel : public IModel
		{
		public:
			explicit Win32_DesktopMonitorModel() = default;
			virtual ~Win32_DesktopMonitorModel() = default;

			std::string& availability();
			std::string& description();
			std::string& deviceId();
			bool& isLocked();
			std::string& monitorManufacturer();
			std::string& name();
			std::string& pixelsPerXLogicalInch();
			std::string& pixelsPerYLogicalInch();
			bool& powerManagementSupported();
			std::string& screenHeight();
			std::string& screenWidth();

		private:
			std::string m_availability;
			std::string m_description;
			std::string m_deviceId;
			bool        m_isLocked;
			std::string m_monitorManufacturer;
			std::string m_name;
			std::string m_pixelsPerXLogicalInch;
			std::string m_pixelsPerYLogicalInch;
			bool        m_powerManagementSupported;
			std::string m_screenHeight;
			std::string m_screenWidth;
		};
	}
}

#endif