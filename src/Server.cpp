#include "../include/Server.hpp"

// Server-Class's Constructors and Methods Definitons
Server::Server() : PortNumber(DEFAULT_PORT) {}
Server::Server(const uint16_t &PortNumber) : PortNumber(PortNumber) {}
Server::Server(const char *&PortNumber) : PortNumber((int)atoi(PortNumber)) {}
Server::Server(const Server *&Server) : PortNumber(Server->getPortnum()) {}
Server::Server(const std::string &PortNumber) : PortNumber(atoi(PortNumber.c_str())) {}

// Getters' Defintions
const uint16_t Server::getPortnum() const { return PortNumber; }

const char *Server::getHostname()
{
    gethostname(hostName, sizeof(hostName));
    return hostName;
}

// Setters' Defintions
const int Server::setHostname(const char *&Hostname)
{ // Not Permitted
    const int Status = sethostname(Hostname, sizeof(Hostname));
    const char *msg = "Hostname setting Error";
    checkError(Status, msg);
    return Status;
}

void Server::checkError(const int &Status, const char *&msg) const
{
    if (Status < 0)
        perror(msg);
}
