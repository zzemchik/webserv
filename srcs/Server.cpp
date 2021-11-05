#include "Server.hpp"

Server::Server(const ServerConfig &config) :
_config(&config)
{
	for (size_t i = 0; i < _config->getListens().size(); i++)
		_ports.insert(_config->getListens()[i].port);
}

Server::~Server()
{}

bool	Server::isListen(unsigned int port) const
{
	for (size_t i = 0; i < _config->getListens().size(); ++i)
		if (_config->getListens()[i].port == port)
			return true;
	return false;
}

const std::set<int>		&Server::getPorts() const
{
	return _ports;
}
