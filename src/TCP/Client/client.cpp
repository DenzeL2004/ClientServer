#include <iostream>

#include "TCPgeneral.hpp"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        throw std::invalid_argument(std::format("Invalid number of input parameters."));
    }

    int client = CreateClient(IPPROTO_TCP);
    TCP::MakeConnect(client, atoi(argv[1]), argv[2]);

    std::cout << "Client connection - success.\n";

    std::cout << "send - send request to server.\n" 
              << "close - turn off client.\n";

    while (true) {
        std::cout << "Enter command: ";
        
        std::string cmd;
        getline(std::cin, cmd);

        if (cmd == "send"){
            std::string request;
            getline(std::cin, request);
            TCP::SendText(client, request.c_str(), request.size());

            std::string reply = TCP::RecvText(client);
            std::cout << "Server reply: " << reply << std::endl;
        }
        else if (cmd == "close"){
            Send(client, nullptr, 0, 0);

            Close(client);
            std::cout << "Client off.\n";
            
            break;
        }
        else {
            std::cout << "Uncorrect command.\n";
        }
    }
}