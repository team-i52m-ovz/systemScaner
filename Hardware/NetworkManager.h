#pragma once
#ifndef JPC_NETWORK_NETWORKMANAGER_H
#define JPC_NETWORK_NETWORKMANAGER_H
#define WIN32_LEAN_AND_MEAN


#include <functional>
#include <memory>
#include <list>

namespace JPC
{
	namespace Network
	{
		class NetworkManager final
		{
		public:
			static NetworkManager& getInstance();
			virtual ~NetworkManager();

			bool initialize(std::string host);
			bool setToken(std::string token);
			bool sendFile(std::string content);
			bool getToken(std::function<void(std::string)> callback);
			void finalize();

		private:
			explicit NetworkManager();

		private:
			bool                                                m_isInitialized;
			std::string                                         m_cookie;
			std::string                                         m_host;
		};
	}
}

#endif