#ifndef __TCP_SERVER_H__
#define __TCP_SERVER_H__

/* Making a simple http server using tcp connection */
#include "Server.hpp"

class TCPConnection : public Server 
{
public:
     TCPConnection();
};
#endif
