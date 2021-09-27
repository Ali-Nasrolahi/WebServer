#include "../include/Server.hpp"

Server::Server(uint16_t PrtNum): PortNumber(PrtNum){}
Server::Server(const char* PrtNum): PortNumber((int) atoi(PrtNum)){}

const uint16_t Server::getPortnum() const {return PortNumber;}

const char* Server::getHostname(){
    Server::hostName;
    gethostname(hostName, sizeof(hostName));
    return hostName;
}
const int Server::setHostname(const char* Hname){ // Not Permitted
    const int Status = sethostname(Hname, sizeof(Hname));
    checkError(Status ,(char*) "Hostname setting Error");
    return Status;
}

void Server::checkError(const int Status, const char* msg) const {
    if(Status < 0)
        perror(msg); 
}
