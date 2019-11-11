//
// Created by slowbroshka on 11/11/19.
//

#ifndef TESTPROM_SERVERSOCKET_H
#define TESTPROM_SERVERSOCKET_H

#include "Socket.h"

namespace common
{

class ServerSocket : public Socket
{
public:
    ServerSocket();

    auto startListen(ushort port, int nConnections = 1) -> void;

    auto getConnectionSocket() -> ServerSocket;
    
    auto read() -> std::string;

private:
    auto bind() -> bool;
    auto static setSocketAddr(ushort port) -> sockaddr_in;
};

} // namespace common

#endif // TESTPROM_SERVERSOCKET_H
