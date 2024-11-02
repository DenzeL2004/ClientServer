#include <iostream>

#include "UDPgeneral.hpp"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        throw std::invalid_argument(std::format("Invalid number of input parameters."));
    }

    int server = CreateServer(atoi(argv[1]), argv[2], SOCK_DGRAM);

    while (true) {
        struct sockaddr_in client_addr; 
        socklen_t client_len = sizeof(client_addr);
       
        std::cout << std::format("Server({}) wait.\n", server);

        std::string request = UDP::RecvText(server, &client_addr, &client_len);
        std::cout << "Client request: " << request << std::endl;

        std::string reply = ScanTerminal();
        UDP::SendText(server, reply.c_str(), reply.size(), &client_addr, client_len);
    }
}