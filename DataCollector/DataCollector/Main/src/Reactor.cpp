#include "../Reactor.h"

#include "../../JSONModelsConverter/JSONModelsConverter.h"

using namespace SystemRat::Main;
using json = nlohmann::json;

void Reactor::init()
{
	m_dataManager.init();
}

std::string Reactor::react(Action action)
{
	if (action == Action::NONE)
	{
		return "Bad request";
	}

	switch (action)
	{
	case Action::BASEBOARD:
	{
		return baseboard();
	}
	case Action::BIOS:
	{
		return bios();
	}
	case Action::COMPUTERSYSTEM:
	{
		return coputerSystem();
	}
	case Action::DESKTOPMONITOR:
	{
		return desktopMonitor();
	}
	case Action::DISKDRIVE:
	{
		return diskDrive();
	}
	case Action::KEYBOARD:
	{
		return keyboard();
	}
	case Action::NETWORKCLIENT:
	{
		return networkClient();
	}
	case Action::OPERATINGSYSTEM:
	{
		return operatingSystem();
	}
	case Action::POINTINGDEVICE:
	{
		return pointingDevice();
	}
	case Action::PROCESSOR:
	{
		return processor();
	}
	case Action::REGISTRY:
	{
		return registry();
	}
	case Action::SOUNDDEVICE:
	{
		return soundDevice();
	}
	case Action::USBCONTROLLER:
	{
		return usbController();
	}
	case Action::USERACCOUNT:
	{
		return userAccount();
	}
	default:
	{
		return "";
	}
	}
}

std::string Reactor::baseboard()
{
	json str;
	auto arr = m_dataManager.get("baseBoard");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createBaseboardModel(std::static_pointer_cast<SystemRat::Models::Win32_BaseboardModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::bios()
{
	json str;
	auto arr = m_dataManager.get("BIOS");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createBIOSModel(std::static_pointer_cast<SystemRat::Models::Win32_BIOSModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}
std::string Reactor::coputerSystem()
{
	json str;
	auto arr = m_dataManager.get("ComputerSystem");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createComputerSystemModel(std::static_pointer_cast<SystemRat::Models::Win32_ComputerSystemModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}
std::string Reactor::desktopMonitor()
{
	json str;
	auto arr = m_dataManager.get("DesktopMonitor");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createDesktopMonitorModel(std::static_pointer_cast<SystemRat::Models::Win32_DesktopMonitorModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::diskDrive()
{
	json str;
	auto arr = m_dataManager.get("DiskDrive");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createDiskDriveModel(std::static_pointer_cast<SystemRat::Models::Win32_DiskDriveModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::keyboard()
{
	json str;
	auto arr = m_dataManager.get("Keyboard");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createKeyboardModel(std::static_pointer_cast<SystemRat::Models::Win32_KeyboardModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::networkClient()
{
	json str;
	auto arr = m_dataManager.get("NetworkClient");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createNetworkCLientModel(std::static_pointer_cast<SystemRat::Models::Win32_NetworkClientModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::operatingSystem()
{
	json str;
	auto arr = m_dataManager.get("OperatingSystem");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createOperatingSystemModel(std::static_pointer_cast<SystemRat::Models::Win32_OperatingSystemModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::pointingDevice()
{
	json str;
	auto arr = m_dataManager.get("PointingDevice");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createPointingDeviceModel(std::static_pointer_cast<SystemRat::Models::Win32_PointingDeviceModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::processor()
{
	json str;
	auto arr = m_dataManager.get("Processor");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createProcessorModel(std::static_pointer_cast<SystemRat::Models::Win32_ProcessorModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::registry()
{
	json str;
	auto arr = m_dataManager.get("Registry");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createRegistryModel(std::static_pointer_cast<SystemRat::Models::Win32_RegistryModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::soundDevice()
{
	json str;
	auto arr = m_dataManager.get("SoundDevice");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createSundDeviceModel(std::static_pointer_cast<SystemRat::Models::Win32_SoundDeviceModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::usbController()
{
	json str;
	auto arr = m_dataManager.get("USBController");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createUSBControllerModel(std::static_pointer_cast<SystemRat::Models::Win32_USBControllerModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}

std::string Reactor::userAccount()
{
	json str;
	auto arr = m_dataManager.get("UserAccount");
	if (arr)
	{
		for (int i = 0; i < arr->size(); ++i)
		{
			std::string curStr = JSONModelsConverter::JSONModelsConverter::createUserAccountModel(std::static_pointer_cast<SystemRat::Models::Win32_UserAccountModel>((*arr)[i]));
			auto curJSON = json::parse(curStr);
			str.push_back(curJSON);
		}
	}
	return str.dump();
}