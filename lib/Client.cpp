#include "../include/Client.hpp"

Client::Client(const int &Portnumber, const char *&Hostname) : Port(Portnumber), Hostname(Hostname){};
void Client::CreateASocket(const int &Domain = AF_INET,
                           const int &Type = SOCK_STREAM, const int &Protocol = 0) const
{
  SockFD = socket(Domain, Type, Protocol);
}
void Client::setHost(const char *&) const {}
void Client::connect() const {}