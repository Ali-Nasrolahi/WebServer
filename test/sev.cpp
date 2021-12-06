#include "../include/Server.hpp"
#include "../include/TCPConnection.hpp"
int main()
{
  Server svr;
  TCPConnection tcp(svr);
  std::cout << tcp.getHostname() << std::endl;
  tcp.CreateASocket();
  tcp.Bind();
  tcp.Listen();
  tcp.Accept();
  tcp.SendOnTCP();
  return 0;
}