#include "../include/TCPConnection.hpp"

// Variables' Definition
int TCPConnection::SocketFD, TCPConnection::AcceptedSocket;
struct sockaddr_in TCPConnection::ServerAddress, TCPConnection::ClientAddress;

// Manipulative Methods
int TCPConnection::checkError(const int &Status, const std::string &msg)
{
    if (Status < 0)
    {
        perror(("TCP Error, " + msg).c_str());
        return -1;
    }
    return 0;
}

// Constructors
TCPConnection::TCPConnection() : server() {}
TCPConnection::TCPConnection(const Server &server) : server(server) {}

// Connection Methods
void TCPConnection::CreateASocket(const int &Domain, const int &Type, const int &Protocol) const
{
    SocketFD = socket(Domain, Type, Protocol);
    checkError(SocketFD, "Socket Creation Error");

    memset(&ServerAddress, 0, sizeof(ServerAddress)); // configure Server Address for connetion

    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_addr.s_addr = INADDR_ANY;
    ServerAddress.sin_port = htons(PortNumber);
}
void TCPConnection::Bind() const
{
    const int Status = bind(SocketFD, (sockaddr *)&ServerAddress, sizeof(ServerAddress));
    checkError(Status, "Binding Error");
}
void TCPConnection::Listen(const int &_requests) const
{
    std::cout << "Listening on Port:\t" << PortNumber << std::endl;
    while (true)
    {
        const int Status = listen(SocketFD, _requests);
        if (Status < 0)
            checkError(Status, "Listening Error");
        else
            return;
    }
}
void TCPConnection::Accept() const
{
    socklen_t SocketLength = sizeof(ClientAddress);
    AcceptedSocket = accept(SocketFD, (sockaddr *)&ClientAddress, &SocketLength);
    if (checkError(AcceptedSocket, "Socket Acception Error") < 0)
        return;
    PrintConnectedSocket();
}
void TCPConnection::PrintConnectedSocket() const
{
    std::string MSG = "Successful Connection.\n Client Addr\t" + std::string(inet_ntoa(ClientAddress.sin_addr)) + "\nPort\t" + std::to_string(ntohs(ClientAddress.sin_port));

    std::cout << MSG << std::endl;
}
