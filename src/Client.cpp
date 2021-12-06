#include "../include/Client.hpp"

int Client::SockFD;
struct hostent *Client::Server;
sockaddr_in Client::ServerAddress;
char Client::Buffer[Client_Buffer];

Client::Client() : Port(8080), Hostname("localhost") {}
Client::Client(const int &Portnumber, const char *Hostname) : Port(Portnumber), Hostname(Hostname){};

void Client::CreateASocket(const int &Domain, const int &Type, const int &Protocol) const
{
  SockFD = socket(Domain, Type, Protocol);
  const char *msg = "Socket Creation Error";
  checkError(SockFD, msg);
}

void Client::setHost(const int &Domain) const
{
  Server = gethostbyname(Hostname);
  const char *msg = "Such host unavailable";
  if (!Server)
    checkError(-1, msg);
  memset(&ServerAddress, 0, sizeof(ServerAddress));
  ServerAddress.sin_family = Domain;
  memcpy((char *)Server->h_addr, (char *)&ServerAddress.sin_addr.s_addr, Server->h_length);
  std::cout << "Port:\t" << Port << std::endl;
  ServerAddress.sin_port = htons(Port);
}
void Client::Connect() const
{
  const int Status = connect(SockFD, (sockaddr *)&ServerAddress, sizeof(ServerAddress));
  const char *msg = "Connection Error";
  checkError(Status, msg);
  if (Status < 0)
    return;
  Send();
}
void Client::Send() const
{
  memset(Buffer, 0, sizeof(Buffer));
  std::cout << "Enter your message for server:\n";
  fgets(Buffer, sizeof(Buffer), stdin);
  const int Status = write(SockFD, Buffer, sizeof(Buffer));
  if (Status < 0)
  {
    const char *msg = "Writing Error";
    checkError(Status, msg);
    return;
  }
  Receive();
}
void Client::Receive() const
{
  const int Status = read(SockFD, Buffer, sizeof(Buffer) - 1);
  if (Status < 0)
  {
    const char *msg = "Reading Error";
    checkError(Status, msg);
    return;
  }
  std::cout << "Message from Server:\t" << Buffer << std::endl;
  close(SockFD);
}