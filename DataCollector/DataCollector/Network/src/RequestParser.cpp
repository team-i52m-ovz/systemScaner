#include "../RequestParser.h"

#include <algorithm>
#include <vector>

using namespace SystemRat::Network;

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}

RequestParser::RequestParser(std::string request)
	:m_request{ request }
{}

Action RequestParser::parse()
{
	std::transform(m_request.begin(), m_request.end(), m_request.begin(), ::tolower);
	std::vector<std::string> params;
	int paramCount = split(m_request, params, ' ');
	if (paramCount != 1)
	{
		return Action::NONE;
	}

	if (params[0] == "baseboard")
	{
		return Action::BASEBOARD;
	}
	else if (params[0] == "bios")
	{
		return Action::BIOS;
	}
	else if (params[0] == "computersystem")
	{
		return Action::COMPUTERSYSTEM;
	}
	else if (params[0] == "desktopmonitor")
	{
		return Action::DESKTOPMONITOR;
	}
	else if (params[0] == "diskdrive")
	{
		return Action::DISKDRIVE;
	}
	else if (params[0] == "keyboard")
	{
		return Action::KEYBOARD;
	}
	else if (params[0] == "networkclient")
	{
		return Action::NETWORKCLIENT;
	}
	else if (params[0] == "operatingsystem")
	{
		return Action::OPERATINGSYSTEM;
	}
	else if (params[0] == "pointingdevice")
	{
		return Action::POINTINGDEVICE;
	}
	else if (params[0] == "processor")
	{
		return Action::PROCESSOR;
	}
	else if (params[0] == "registry")
	{
		return Action::REGISTRY;
	}
	else if (params[0] == "sounddevice")
	{
		return Action::SOUNDDEVICE;
	}
	else if (params[0] == "usbcontroller")
	{
		return Action::USBCONTROLLER;
	}
	else if (params[0] == "useraccount")
	{
		return Action::USERACCOUNT;
	}
	else
	{
		return Action::NONE;
	}
}