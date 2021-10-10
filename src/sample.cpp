#include "../include/Server.hpp"
#include "../include/TCPConnection.hpp"

int main()
{
  TCPConnection *tcp = new TCPConnection;
  tcp->CreateASocket();
  tcp->Bind();
  tcp->Listen();
  tcp->Accept();
  delete tcp;
  return 0;
}