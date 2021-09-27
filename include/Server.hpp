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
#include <stdlib.h>
#include <iostream>

constexpr uint16_t MAX_PACKET_SIZE {16384}; // range: 0 -> 65,535 bytes 
constexpr uint16_t MAX_HOST_NAME {256}; // 256 characters accepted


class Server
{
public:
    //Constructors
    explicit Server(uint16_t);
    explicit Server(const char*);

    //Getters
    const uint16_t getPortnum() const;
    const char* getHostname();

    //Setters
    const int setHostname(const char*); //Not Permitted


    void checkError(const int, const char*) const; //Simple Error displayer


private:
    const uint16_t PortNumber;
    struct sockaddr_in ServerAddress, ClientAddress;
    char hostName[MAX_HOST_NAME];

};


#endif