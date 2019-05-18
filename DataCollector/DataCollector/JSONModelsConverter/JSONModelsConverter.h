#pragma once
#ifndef SYSTEMRAT_JSONMODELSCONVERTER_JSONMODELSCONVERTER_H
#define SYSTEMRAT_JSONMODELSCONVERTER_JSONMODELSCONVERTER_H

#include "../Models/Win32_BaseboardModel.h"
#include "../Models/Win32_BIOSModel.h"
#include "../Models/Win32_ComputerSystemModel.h"
#include "../Models/Win32_DesktopMonitorModel.h"
#include "../Models/Win32_DiskDriveModel.h"
#include "../Models/Win32_KeyboardModel.h"
#include "../Models/Win32_NetworkClientModel.h"
#include "../Models/Win32_OperatingSystemModel.h"
#include "../Models/Win32_PointingDeviceModel.h"
#include "../Models/Win32_ProcessorModel.h"
#include "../Models/Win32_RegistryModel.h"
#include "../Models/Win32_SoundDeviceModel.h"
#include "../Models/Win32_USBControllerModelh.h"
#include "../Models/Win32_UserAccountModel.h"

#include <single_include/nlohmann/json.hpp>

using json = nlohmann::json;

namespace SystemRat
{
	namespace JSONModelsConverter
	{
		class JSONModelsConverter final
		{
		public:
			//JSON to Models
			static std::shared_ptr<SystemRat::Models::Win32_BaseboardModel> createBaseboardModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_BIOSModel> createBIOSModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_ComputerSystemModel> createComputerSystemModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_DesktopMonitorModel> createDesktopMonitorModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_DiskDriveModel> createDiskDriveModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_KeyboardModel> createKeyboardModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_NetworkClientModel> createNetworkCLientModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_OperatingSystemModel> createOperatingSystemModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_PointingDeviceModel> createPointingDeviceModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_ProcessorModel> createProcessorModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_RegistryModel> createRegistryModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_SoundDeviceModel> createSundDeviceModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_USBControllerModel> createUSBControllerModel(json object);
			static std::shared_ptr<SystemRat::Models::Win32_UserAccountModel> createUserAccountModel(json object);

			//Models to JSON
			static std::string createBaseboardModel(std::shared_ptr<SystemRat::Models::Win32_BaseboardModel>);
			static std::string createBIOSModel(std::shared_ptr<SystemRat::Models::Win32_BIOSModel>);
			static std::string createComputerSystemModel(std::shared_ptr<SystemRat::Models::Win32_ComputerSystemModel>);
			static std::string createDesktopMonitorModel(std::shared_ptr<SystemRat::Models::Win32_DesktopMonitorModel>);
			static std::string createDiskDriveModel(std::shared_ptr<SystemRat::Models::Win32_DiskDriveModel>);
			static std::string createKeyboardModel(std::shared_ptr<SystemRat::Models::Win32_KeyboardModel>);
			static std::string createNetworkCLientModel(std::shared_ptr<SystemRat::Models::Win32_NetworkClientModel>);
			static std::string createOperatingSystemModel(std::shared_ptr<SystemRat::Models::Win32_OperatingSystemModel>);
			static std::string createPointingDeviceModel(std::shared_ptr<SystemRat::Models::Win32_PointingDeviceModel>);
			static std::string createProcessorModel(std::shared_ptr<SystemRat::Models::Win32_ProcessorModel>);
			static std::string createRegistryModel(std::shared_ptr<SystemRat::Models::Win32_RegistryModel>);
			static std::string createSundDeviceModel(std::shared_ptr<SystemRat::Models::Win32_SoundDeviceModel>);
			static std::string createUSBControllerModel(std::shared_ptr<SystemRat::Models::Win32_USBControllerModel>);
			static std::string createUserAccountModel(std::shared_ptr<SystemRat::Models::Win32_UserAccountModel>);
		};
	}
}

#endif