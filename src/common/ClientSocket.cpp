#include "ClientSocket.h"

#include <netdb.h>

#include <netinet/in.h>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>

namespace common
{

ClientSocket::ClientSocket(const std::string &servAddr, ushort serverPort)
{
    _port = serverPort;
    socketAddr = setSocketAddr(servAddr, serverPort);
}

ClientSocket::~ClientSocket()
{
    close(socketFd);
}

auto ClientSocket::setSocketAddr(const std::string &servAddr, ushort port)
    -> sockaddr_in
{
    hostent *server = gethostbyname(servAddr.c_str());

    sockaddr_in res{};
    res.sin_family = AF_INET;
    res.sin_port = htons(port);
    bcopy(
        (char *)server->h_addr,
        (char *)&res.sin_addr.s_addr,
        server->h_length);

    return res;
}

auto ClientSocket::connect() -> bool
{
    if (::connect(socketFd, (struct sockaddr *)&socketAddr, sizeof(socketAddr)) < 0) {
        std::cerr << "Connection socket error " <<std::endl;
        return false;
    }
    return true;
}

} // namespace common
