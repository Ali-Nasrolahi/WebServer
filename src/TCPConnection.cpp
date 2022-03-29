#include "../include/TCPConnection.hpp"

// Variables' Definition
int TCPConnection::SocketFD, TCPConnection::AcceptedSocket;
struct sockaddr_in TCPConnection::ServerAddress, TCPConnection::ClientAddress;
char TCPConnection::Buffer[_Buffer_Size];

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
TCPConnection::TCPConnection(const Server &server) : server(server)
{
    this->PortNumber = server.getPortnum();
}
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
    const int Status = listen(SocketFD, _requests);
    if (Status < 0)
        checkError(Status, "Listening Error");
    else
        return;
}
void TCPConnection::Accept() const
{
    socklen_t SocketLength = sizeof(ClientAddress);
    while (1)
    {
        AcceptedSocket = accept(SocketFD, (sockaddr *)&ClientAddress, &SocketLength);
        if (checkError(AcceptedSocket, "Socket Acception Error") < 0)
            return;
        else
            break;
    }
    PrintConnectedSocket();
}
void TCPConnection::PrintConnectedSocket() const
{
    std::string MSG = "Successful Connection.\n Client Addr\t" + std::string(inet_ntoa(ClientAddress.sin_addr)) + "\nPort\t" + std::to_string(ntohs(ClientAddress.sin_port));

    std::cout << MSG << std::endl;
}

void TCPConnection::SendOnTCP() const
{
    memset(Buffer, 0, sizeof(Buffer));
    std::cout << "Enter your message:\n";
    fgets(Buffer, sizeof(Buffer), stdin);
    const int Status = send(AcceptedSocket, Buffer, sizeof(Buffer), 0);
    if (checkError(Status, "Sending Error") < 0)
        return;
    ReceiveOnTCP();
}

void TCPConnection::ReceiveOnTCP() const
{
    memset(Buffer, 0, sizeof(Buffer));
    const int Status = read(AcceptedSocket, Buffer, sizeof(Buffer));
    if (checkError(Status, "Reading Error") < 0)
        return;
    std::cout << "The Message From Client:\t" << Buffer << std::endl;
    close(SocketFD);
    close(AcceptedSocket);
}