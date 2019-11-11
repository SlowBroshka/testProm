#include "../common/ClientSocket.h"



int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "usage "<< argv[0] <<" hostname port" << std::endl;
        exit(0);
    }
    auto serverArrd = std::string(argv[1]);
    auto serverPort = strtol(argv[2], &argv[2], 10);
    
    std::cout << "serverArrd: " << serverArrd << " serverPort: " << serverPort << std::endl;

    common::ClientSocket clientSocket{};

    if (!clientSocket.connect(serverArrd, serverPort)) {
        std::cerr << "Connection error" << std::endl;
        exit(1);
    }
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true)
    {
        printf("Please enter the message: ");
        std::string msg{};
        std::cin >> msg;
        if (clientSocket.write(msg)) {
            std::cout << "\nWrite success" << std::endl;
        } else {
            std::cout << "\nWrite failed" << std::endl;
        }

//        n = read(sockfd, buffer, 255);
//        if (n < 0)
//            error("ERROR reading from socket");
    }
#pragma clang diagnostic pop
    return 0;
}
