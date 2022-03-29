#include "../include/Client.hpp"

int main()
{
  Client *client = new Client();
  std::cout << client->getHostname() << std::endl;
  client->CreateASocket();
  client->setHost();
  client->Connect();
  delete client;
  return 0;
}