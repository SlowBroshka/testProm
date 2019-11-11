#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
    ushort portno = strtol(argv[1], &argv[1], 10);
    std::cout << portno << std::endl;

    int sock, listener;
    sockaddr_in addr{};
    sockaddr_in connection{};
    socklen_t sockaddr_size = sizeof(connection);
    char buf[1024];
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(portno);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

    while(true)
    {

        sock = accept(listener, (sockaddr *)&connection, &sockaddr_size);
        std::cout << "Connection: " << inet_ntoa(connection.sin_addr) << " : " <<  connection.sin_port << std::endl;
        if (sock < 0)
        {
            perror("accept");
            exit(3);
        }

        while(true)
        {
            bytes_read = recv(sock, buf, 1024, 0);
            if(bytes_read <= 0) break;
            send(sock, buf, bytes_read, 0);
        }

        close(sock);
    }

#pragma clang diagnostic pop

    return 0;
}