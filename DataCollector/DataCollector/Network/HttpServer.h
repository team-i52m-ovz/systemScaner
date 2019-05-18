#pragma once
#define WIN32_LEAN_AND_MEAN
#ifndef JPC_HTTP_NETWORK_HTTPSERVER_H
#define JPC_HTTP_NETWORK_HTTPSERVER_H

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

namespace JPC
{
	namespace Network
	{
		namespace Http
		{
			class HttpServer final 
			{
			public:
				explicit HttpServer(/*std::string domain, unsigned int portNumber*/);
				virtual ~HttpServer() = default;

				virtual bool initialize();
				virtual bool acceptConnections();
				virtual std::string readRequest();
				virtual void sendRequest(std::string request);
				virtual void finalize();
				virtual bool isConnectionOpened();
				virtual bool closeConnection();

			private:
				bool              m_isCOnnectionOpened;
				WSADATA           m_wsaData;
				SOCKET            m_socket;
				SOCKET            m_listenSocket;
				struct addrinfo * m_endpoint;
				struct addrinfo   m_emptyEndpoint;
				/*std::string       m_host;
				int               m_port;*/
			};
		}
	}
}
#endif