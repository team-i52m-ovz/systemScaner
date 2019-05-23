#include "../DataManager.h"

#include <single_include/nlohmann/json.hpp>
#include <fstream>
#include "../../JSONModelsConverter/JSONModelsConverter.h"

using namespace SystemRat::DataManager;
using namespace SystemRat::Models;
using json = nlohmann::json;

void DataManager::init()
{
	std::ifstream i("report.json");
	json j;
	i >> j;
	auto curObj = j["Hardware"]["Win32_BaseBoard"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("baseBoard", JSONModelsConverter::JSONModelsConverter::createBaseboardModel(curObj[i][0]));
		}
	}
	curObj = j["Hardware"]["Win32_BIOS"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("BIOS", JSONModelsConverter::JSONModelsConverter::createBIOSModel(curObj[i][0]));
		}
	}
	curObj = j["Hardware"]["Win32_DesktopMonitor"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("DesktopMonitor", JSONModelsConverter::JSONModelsConverter::createDesktopMonitorModel(curObj[i][0]));
		}
	}
	curObj = j["Hardware"]["Win32_DiskDrive"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("DiskDrive", JSONModelsConverter::JSONModelsConverter::createDiskDriveModel(curObj[i][0]));
		}
	}
	curObj = j["Hardware"]["Win32_Keyboard"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("Keyboard", JSONModelsConverter::JSONModelsConverter::createKeyboardModel(curObj[i][0]));
		}
	}
	curObj = j["Hardware"]["Win32_PointingDevice"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("PointingDevice", JSONModelsConverter::JSONModelsConverter::createPointingDeviceModel(curObj[i][0]));
		}
	}
	curObj = j["Hardware"]["Win32_Processor"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("Processor", JSONModelsConverter::JSONModelsConverter::createProcessorModel(curObj[i][0]));
		}
	}
	curObj = j["Hardware"]["Win32_SoundDevice"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("SoundDevice", JSONModelsConverter::JSONModelsConverter::createSundDeviceModel(curObj[i][0]));
		}
	}
	curObj = j["Hardware"]["Win32_USBController"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("USBController", JSONModelsConverter::JSONModelsConverter::createUSBControllerModel(curObj[i][0]));
		}
	}
	curObj = j["Operating System"]["Win32_ComputerSystem"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("ComputerSystem", JSONModelsConverter::JSONModelsConverter::createComputerSystemModel(curObj[i][0]));
		}
	}
	curObj = j["Operating System"]["Win32_NetworkClient"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("NetworkClient", JSONModelsConverter::JSONModelsConverter::createNetworkCLientModel(curObj[i][0]));
		}
	}
	curObj = j["Operating System"]["Win32_OperatingSystem"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("OperatingSystem", JSONModelsConverter::JSONModelsConverter::createOperatingSystemModel(curObj[i][0]));
		}
	}
	curObj = j["Operating System"]["Win32_Registry"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("Registry", JSONModelsConverter::JSONModelsConverter::createRegistryModel(curObj[i][0]));
		}
	}
	curObj = j["Operating System"]["Win32_UserAccount"];
	if (!curObj.empty())
	{
		for (int i = 0; i < curObj.size(); ++i)
		{
			add("UserAccount", JSONModelsConverter::JSONModelsConverter::createUserAccountModel(curObj[i][0]));
		}
	}
}

void DataManager::add(std::string name, std::shared_ptr<SystemRat::Models::IModel> val)
{
	m_models[name].push_back(val);
}

std::vector<std::shared_ptr<SystemRat::Models::IModel>>* DataManager::get(std::string key)
{
	auto retVal = m_models.find(key);
	if (retVal != m_models.end())
	{
		return &retVal->second;
	}
	return nullptr;
}

bool DataManager::contains(std::string key)
{
	return m_models.find(key) != m_models.end();
}