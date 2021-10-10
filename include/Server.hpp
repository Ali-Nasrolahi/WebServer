#ifndef __Server_H__
#define __Server_H__

// Including needed socket headers
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// C-libs & IO
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>


constexpr uint16_t MAX_PACKET_SIZE {16384}; // range: 0 -> 65,535 bytes 
constexpr uint16_t MAX_HOST_NAME_LEN {256}; // 256 characters accepted
constexpr uint16_t DEFAULT_PORT {8080};


class Server
{
public:
    // Constructors
    explicit Server();
    explicit Server(const uint16_t &);
    explicit Server(const char* &);
    explicit Server(const Server* &);
    explicit Server(const std::string &);
    


    // Getters
    const uint16_t getPortnum() const;
    const char* getHostname();

    // Setters
    const int setHostname(const char* &); // Not Permitted


    virtual void checkError(const int &, const char* &) const; // Simple Error displayer


protected:
    const uint16_t PortNumber;
    char hostName[MAX_HOST_NAME_LEN];
};

#endif