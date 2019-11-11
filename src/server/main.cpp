#include "../common/ServerSocket.h"

int main(int argc, char *argv[])
{
    ushort servPort = strtol(argv[1], &argv[1], 10);
    std::cout << servPort << std::endl;
    
    
    common::ServerSocket serverSocket{};
    serverSocket.startListen(servPort, 1);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

    while(true)
    {
        common::ServerSocket connection = serverSocket.getConnectionSocket();
        while(true)
        {
            std::string data = connection.read();
            std::cout << "Data: " << data << std::endl;
            //send(sock, buf, bytes_read, 0);
        }
    }

#pragma clang diagnostic pop

    return 0;
}