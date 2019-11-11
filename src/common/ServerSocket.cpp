//
// Created by slowbroshka on 11/11/19.
//

#include "ServerSocket.h"
namespace common
{

ServerSocket::ServerSocket(ushort serverPort)
{
    socketAddr = setSocketAddr(serverPort);
}

auto ServerSocket::setSocketAddr(ushort port) -> sockaddr_in
{
    sockaddr_in res{};
    res.sin_family = AF_INET;
    res.sin_port = htons(port);
    res.sin_addr.s_addr = htonl(INADDR_ANY);

    return res;
}

auto ServerSocket::bind() -> void
{
    if (::bind(socketFd, (sockaddr*)&socketAddr, sizeof(socketAddr)) < 0) {
        std::cerr << "Binnd socket error" << __FUNCTION__;
        // throw
    }
}

} // namespace common
