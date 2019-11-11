//
// Created by slowbroshka on 11/11/19.
//

#include "ServerSocket.h"
namespace common
{

ServerSocket::ServerSocket()
{
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
}

auto ServerSocket::setSocketAddr(ushort port) -> sockaddr_in
{
    sockaddr_in res{};
    res.sin_family = AF_INET;
    res.sin_port = htons(port);
    res.sin_addr.s_addr = htonl(INADDR_ANY);

    return res;
}

auto ServerSocket::bind() -> bool
{
    if (::bind(socketFd, (sockaddr*)&socketAddr, sizeof(socketAddr)) < 0) {
        std::cerr << "Binnd socket error" << __FUNCTION__;
        // throw
        return false;
    }
    return true;
}

auto ServerSocket::startListen(ushort port, int nConnections) -> void
{
    _port = port;
    socketAddr = setSocketAddr(_port);
    if (!bind()) {
        std::cout<< "Server socket bind error" << std::endl;
        exit(1);
    }
    ::listen(socketFd, nConnections);
}
auto ServerSocket::read() -> std::string
{
    char buffer[buffSize];
    ::bzero(buffer, buffSize);
    
    int readBytes = ::recv(socketFd, &buffer, buffSize, 0);
    if (readBytes >= buffSize) {
        std::cout << "Read error out of buffer" << std::endl;
        return std::string{};
    }
    return std::string{buffer};
}

auto ServerSocket::getConnectionSocket() -> ServerSocket
{
    ServerSocket res{};
    socklen_t sockaddr_size = sizeof(res.socketAddr);
    res.socketFd = accept(socketFd, (sockaddr *)&res.socketAddr, &sockaddr_size);
    return res;
}

} // namespace common
