#include "../Application.h"

#include "../../Network/RequestParser.h"

using namespace SystemRat::Main;

void Application::initialize()
{
	m_reactor.init();
	m_httpServer.initialize();
}

void Application::run()
{
	do
	{
		if (m_httpServer.acceptConnections())
		{
			do
			{
				std::string request = m_httpServer.readRequest();
				if (m_httpServer.isConnectionOpened())
				{
					SystemRat::Network::RequestParser parser{ request };
					Action action = parser.parse();
					std::string reaction = m_reactor.react(action);
					m_httpServer.sendRequest(reaction);
					if (!m_httpServer.isConnectionOpened())
					{
						break;
					}
				}
			} while (m_httpServer.isConnectionOpened());
		}
		m_httpServer.closeConnection();
		m_httpServer.finalize();
		m_httpServer.initialize();
	} while (true);
}