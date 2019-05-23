#pragma once
#ifndef SYSTEMRAT_MAIN_APPLICATION_H
#define SYSTEMRAT_MAIN_APPLICATION_H

#include "Reactor.h"
#include "../Network/HttpServer.h"

namespace SystemRat
{
	namespace Main
	{
		class Application final
		{
		public:
			explicit Application() = default;
			~Application() = default;

			void initialize();
			void run();

		private:
			SystemRat::Main::Reactor            m_reactor;
			JPC::Network::Http::HttpServer      m_httpServer;
		};
	}
}

#endif