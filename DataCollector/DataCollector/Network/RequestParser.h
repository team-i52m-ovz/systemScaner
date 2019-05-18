#pragma once
#ifndef SYSTEMRAT_NETWORK_REQUESTPARSER_H
#define SYSTEMRAT_NETWORK_REQUESTPARSER_H

#include <string>
#include "../Common/Common.h"

namespace SystemRat
{
	namespace Network
	{
		class RequestParser final
		{
		public:
			explicit RequestParser(std::string request);
			~RequestParser() = default;

			Action parse();
		private:
			std::string m_request;
		};
	}
}

#endif