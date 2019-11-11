#include "ClientSocket.h"



namespace common
{

ClientSocket::ClientSocket()
{
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
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
    ::bcopy(
        (char *)server->h_addr,
        (char *)&res.sin_addr.s_addr,
        server->h_length);
    return res;
}

auto ClientSocket::connect(
    const std::string &servAddr, ushort serverPort) -> bool
{
    _port = serverPort;
    socketAddr = setSocketAddr(servAddr, serverPort);
    if (::connect(socketFd, (sockaddr *)&socketAddr, sizeof(socketAddr)) < 0) {
        std::cerr << "Connection socket error " <<std::endl;
        return false;
    }
    return true;
}

auto ClientSocket::write(const std::string &data) -> bool
{
    char buffer[buffSize];
    ::bzero(buffer, buffSize);
    ::bcopy(data.c_str(), &buffer, data.size());
    if (data.size() < buffSize) {
        int n = ::write(socketFd, buffer, data.size());
        return n > 0;
    }
    return false;
}

} // namespace common
