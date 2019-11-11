//
// Created by slowbroshka on 11/11/19.
//
#ifndef TESTPROM_SOCKET_H
#define TESTPROM_SOCKET_H

#include <unistd.h>

#include <netdb.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <thread>

#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

namespace common
{

class Socket
{
public:
    Socket();

protected:
    ushort _port;
    int socketFd;
    sockaddr_in socketAddr;

    std::thread thread;
    
public:
    constexpr static uint buffSize = 256;
};

} // namespace common

#endif // TESTPROM_SOCKET_H
