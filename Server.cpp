#include "Server.hpp"

Server::Server(int ac, char **av)
{
    if (ac != 3)
        throw Error("Wrong args : ./ircserv <port> <password>");

    _portStr = av[1];
    _password = av[2];

    inputCheck();
}

Server::~Server()
{

}

Server::Error::Error(std::string const &msg): _msg(msg)
{

}

const char* Server::Error::what() const throw()
{
	return (_msg.c_str());
}

void Server::inputCheck()
{
    char* end = NULL;
    long port = std::strtol(_portStr.c_str(), &end, 10);

    if (*end != '\0')
        throw Error("Port must be a valid number (digits only)");

    if (port < 1024 || port > 65535)
        throw Error("Port must be between 1024 and 65535");

    _port = static_cast<int>(port);
}