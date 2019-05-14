#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_PROCESSORMODEL_H
#define SYSTEMRAT_MODELS_WIN32_PROCESSORMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_ProcessorModel final : public IModel
		{
		public:
			explicit Win32_ProcessorModel() = default;
			virtual ~Win32_ProcessorModel() = default;

			std::string& addressWidth();
			std::string& architecture();
			std::string& cpuStatus();
			std::string& currentVoltage();
			std::string& errorDescription();
			std::string& family();
			std::string& installDate();
			std::string& level();
			std::string& loadPercentage();
			std::string& manufacturer();
			std::string& maxClockSpeed();
			std::string& name();
			std::string& numberOfCores();
			std::string& numberOfEnabledCore();
			std::string& numberOfLogicalProcessors();
			std::string& partNumber();
			bool&        powerManagementSupported();
			std::string& processorId();
			std::string& processorType();
			std::string& serialNumber();
			std::string& socketDesignation();
			std::string& threadCount();

		private:
			std::string m_addressWidth;
			std::string m_architecture;
			std::string m_cpuStatus;
			std::string m_currentVoltage;
			std::string m_errorDescription;
			std::string m_family;
			std::string m_installDate;
			std::string m_level;
			std::string m_loadPercentage;
			std::string m_manufacturer;
			std::string m_maxClockSpeed;
			std::string m_name;
			std::string m_numberOfCores;
			std::string m_numberOfEnabledCore;
			std::string m_numberOfLogicalProcessors;
			std::string m_partNumber;
			bool        m_powerManagementSupported;
			std::string m_processorId;
			std::string m_processorType;
			std::string m_serialNumber;
			std::string m_socketDesignation;
			std::string m_threadCount;
		};
	}
}

#endif