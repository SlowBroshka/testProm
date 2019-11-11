#ifndef TESTPROM_CLIENTSOCKET_H
#define TESTPROM_CLIENTSOCKET_H

#include "Socket.h"

namespace common
{

struct Message
{
    uint checksum;
    std::string data;
};


class ClientSocket : public Socket
{
public:
    ClientSocket();

public:
    auto connect(const std::string &servAddr, ushort serverPort)-> bool;

    auto write(const std::string& data) -> bool;

    virtual ~ClientSocket();
private:
    auto static setSocketAddr(const std::string &servAddr, ushort port) -> sockaddr_in;

private:
};

} // namespace common

#endif // TESTPROM_CLIENTSOCKET_H
