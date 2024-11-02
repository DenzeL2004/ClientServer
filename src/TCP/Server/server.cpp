#include <iostream>

#include "TCPgeneral.hpp"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        throw std::invalid_argument(std::format("Invalid number of input parameters."));
    }

    int server = CreateServer(atoi(argv[1]), argv[2], IPPROTO_TCP);

    std::cout << "listen - start server in mode waiting for request from client.\n" 
              << "close - turn off server.\n";

    while (true) {
        std::cout << "Enter command: ";
        
        std::string cmd;
        getline(std::cin, cmd);

        if (cmd == "listen"){
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

                std::string reply;
                getline(std::cin, reply);
                TCP::SendText(client, reply.c_str(), reply.size());
            }
        }
        else if (cmd == "close"){
            Close(server);
            std::cout << "Server off.\n";
            
            break;
        }
        else {
            std::cout << "Uncorrect command.\n";
        }
    }
}