#include <iostream>

#include "TCPgeneral.hpp"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        throw std::invalid_argument(std::format("Invalid number of input parameters."));
    }

    int server = CreateServer(atoi(argv[1]), argv[2], SOCK_STREAM);

    while (true) {
       
        std::cout << std::format("Server({}) listen.\n", server);
        TCP::Listen(server);

        int client = TCP::Accept(server);
        std::cout << std::format("Server({}) accept client({}).\n", server, client);

        while(true) {
            std::string request = TCP::RecvText(client);
            
            if (request.size() == 0){
                Close(client);
                std::cout << std::format("Connection with the client({}) was lost.\n", client);
                break;
            }
            
            std::cout << "Client request: " << request << std::endl;

            std::string reply = ScanTerminal();
            TCP::SendText(client, reply.c_str(), reply.size());
        }
    }
}