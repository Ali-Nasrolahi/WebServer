#ifndef __TCP_SERVER_H__
#define __TCP_SERVER_H__

/* Making a simple http server using tcp connection */
#include "Server.hpp"

constexpr int16_t _Buffer_Size = 1024;

class TCPConnection : public Server 
{
public:
     // Constructors
     explicit TCPConnection();
     explicit TCPConnection(const Server &);

     // Manipulative Methods
     static void checkError(const int &, const std::string &);

     // Connection Methods
     static void CreateASocket(const int &, const int&, const int&); // args respectively: Domain, Type, Protocol

private:
     const Server server;
     static int SocketFD, AcceptedSocket;
     static struct sockaddr_in ServerAddress, ClientAddress;
     static char Buffer[_Buffer_Size];
};
#endif
