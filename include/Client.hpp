#ifndef __Client_H__
#define __Client_H__

#include "Server.hpp"
#include "TCPConnection.hpp"

constexpr int16_t Client_Buffer = 1024;
class Client : public Server
{
public:
  explicit Client();
  explicit Client(const int &, const char *);
  void CreateASocket(const int & = AF_INET, const int & = SOCK_STREAM, const int & = 0) const;
  void setHost(const int & = AF_INET) const;
  void Connect() const;
  void Send() const;
  void Receive() const;

private:
  const int Port;
  static int SockFD;
  const char *Hostname;
  static sockaddr_in ServerAddress;
  static struct hostent *Server;
  static char Buffer[Client_Buffer];
};

#endif