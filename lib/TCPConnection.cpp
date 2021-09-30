#include "../include/TCPConnection.hpp"

// Variables' Definition
int TCPConnection::SocketFD;

// Manipulative Methods
void TCPConnection::checkError(const int &Status, const std::string &msg){
    if(Status < 0)
        perror(("TCP Error, " + msg).c_str());
}

// Constructors
TCPConnection::TCPConnection(): server(){}
TCPConnection::TCPConnection(const Server &server): server(server){}

// Connection Methods
void TCPConnection::CreateASocket(const int &Domain = AF_INET, 
const int &Type = SOCK_STREAM, const int &Protocol = 0){
    SocketFD = socket(Domain, Type, Protocol);
    checkError(SocketFD, "Socket Creation Error");
}
