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
     static int checkError(const int &, const std::string &); // return 0 for Successful operation.

     // Connection Methods
     void CreateASocket(const int & = AF_INET, const int & = SOCK_STREAM, const int & = 0) const;
     void Bind() const;
     void Listen(const int & = 4) const;
     void Accept() const;
     void PrintConnectedSocket() const;

private:
     const Server server;
     static int SocketFD, AcceptedSocket;
     static struct sockaddr_in ServerAddress, ClientAddress;
     static char Buffer[_Buffer_Size];
};
#endif
