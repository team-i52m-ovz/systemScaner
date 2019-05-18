#include "../HttpServer.h"

#include <iostream>
// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

using namespace JPC::Network::Http;

HttpServer::HttpServer()
	: m_socket{ INVALID_SOCKET }
	, m_listenSocket{ INVALID_SOCKET }
	, m_endpoint{ nullptr }
	, m_isCOnnectionOpened{ false }
{}

bool HttpServer::initialize()
{
	int iResult = WSAStartup(MAKEWORD(2, 2), &m_wsaData);
	if (iResult != 0)
	{
		std::cout << "WSAStartup failed with error:" << iResult << std::endl;
		return false;
	}

	ZeroMemory(&m_emptyEndpoint, sizeof(m_emptyEndpoint));
	m_emptyEndpoint.ai_family = AF_UNSPEC;
	m_emptyEndpoint.ai_socktype = SOCK_STREAM;
	m_emptyEndpoint.ai_protocol = IPPROTO_TCP;

	return true;
}

bool HttpServer::acceptConnections()
{
	// Resolve the server address and port
	int iResult = getaddrinfo(NULL, DEFAULT_PORT, &m_emptyEndpoint, &m_endpoint);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return false;
	}

	// Create a SOCKET for connecting to server
	m_listenSocket = socket(m_endpoint->ai_family, m_endpoint->ai_socktype, m_endpoint->ai_protocol);
	if (m_listenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(m_endpoint);
		WSACleanup();
		return false;
	}

	// Setup the TCP listening socket
	iResult = bind(m_listenSocket, m_endpoint->ai_addr, (int)m_endpoint->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(m_endpoint);
		closesocket(m_listenSocket);
		WSACleanup();
		return false;
	}

	freeaddrinfo(m_endpoint);

	iResult = listen(m_listenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(m_listenSocket);
		WSACleanup();
		return false;
	}

	// Accept a client socket
	m_socket = accept(m_listenSocket, NULL, NULL);
	if (m_socket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(m_listenSocket);
		WSACleanup();
		return false;
	}

	// No longer need server socket
	closesocket(m_listenSocket);
	m_isCOnnectionOpened = true;
	return true;
}

bool HttpServer::closeConnection()
{
	if (!m_isCOnnectionOpened)
	{
		return false;
	}
	// shutdown the connection since no more data will be sent
	int iResult = shutdown(m_socket, SD_SEND);
	if (iResult == SOCKET_ERROR)
	{
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(m_socket);
		WSACleanup();
		return false;
	}
	m_isCOnnectionOpened = false;
	return true;
}

bool HttpServer::isConnectionOpened()
{
	return m_isCOnnectionOpened;
}

std::string HttpServer::readRequest()
{
	std::string retVal;
	int iResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;
	//do {
		std::memset(recvbuf, '\0', recvbuflen);
		iResult = recv(m_socket, recvbuf, recvbuflen, 0);
		if (iResult > 0)
		{
			printf("Bytes received: %d\n", iResult);
		}
		else
		{
			printf("recv failed with error: %d\n", WSAGetLastError());
			closesocket(m_socket);
			WSACleanup();
			m_isCOnnectionOpened = false;
			return "";
		}
		retVal.append(recvbuf);
	//} while (iResult > 0);

	return retVal;
}

void HttpServer::sendRequest(std::string request)
{
	if (m_socket == INVALID_SOCKET)
	{
		std::cout << "connection is not established\n";
		m_isCOnnectionOpened = false;
		return;
	}

	std::cout << "Sending...\n";
	int iResult = send(m_socket, request.data(), request.size(), 0);

	if (iResult == SOCKET_ERROR)
	{
		std::cout << "send failed with error: " << WSAGetLastError() << std::endl;
		finalize();
		m_isCOnnectionOpened = false;
		return ;
	}
}

void HttpServer::finalize()
{
	closesocket(m_socket);
	WSACleanup();
}