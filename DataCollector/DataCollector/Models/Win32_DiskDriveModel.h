#pragma once
#ifndef SYSTEMRAT_MODELS_WIN32_DISKDRIVEMODEL_H
#define SYSTEMRAT_MODELS_WIN32_DISKDRIVEMODEL_H

#include "IModel.h"

namespace SystemRat
{
	namespace Models
	{
		class Win32_DiskDriveModel final : public IModel
		{
		public:
			explicit Win32_DiskDriveModel() = default;
			virtual ~Win32_DiskDriveModel() = default;

			std::string& availability();
			std::string& bytesPerSector();
			std::string& compressionMethod();
			std::string& description();
			std::string& deviceId();
			std::string& errorDescription();
			std::string& index();
			std::string& lastErrorCode();
			std::string& manufacturer();
			std::string& maxBlockSize();
			bool& mediaLoaded();
			std::string& mediaType();
			std::string& model();
			std::string& name();
			bool& needsCleaning();
			std::string& serialNumber();
			std::string& signature();
			std::string& size();
			std::string& totalCylinders();
			std::string& totalHeads();
			std::string& totalSectors();

		private:
			std::string m_availability;
			std::string m_bytesPerSector;
			std::string m_compressionMethod;
			std::string m_description;
			std::string m_deviceId;
			std::string m_errorDescription;
			std::string m_index;
			std::string m_lastErrorCode;
			std::string m_manufacturer;
			std::string m_maxBlockSize;
			bool        m_mediaLoaded;
			std::string m_mediaType;
			std::string m_model;
			std::string m_name;
			bool        m_needsCleaning;
			std::string m_serialNumber;
			std::string m_signature;
			std::string m_size;
			std::string m_totalCylinders;
			std::string m_totalHeads;
			std::string m_totalSectors;
		};
	}
}

#endif