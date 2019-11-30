#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include "NetworkManager.h"

class Manager final
{
public:
	explicit Manager();
	~Manager() = default;

	void exec();

private:
	JPC::Network::NetworkManager& m_networkManager;
};

#endif