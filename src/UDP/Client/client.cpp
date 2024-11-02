#include <iostream>

#include "UDPgeneral.hpp"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        throw std::invalid_argument(std::format("Invalid number of input parameters."));
    }

    int client = CreateClient(SOCK_DGRAM);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET; 
	server_addr.sin_port = htons(atoi(argv[1])); 
	server_addr.sin_addr.s_addr = inet_addr(argv[2]); 

    while (true) {

       std::cout << "Enter command: ";
        
        std::string cmd;
        getline(std::cin, cmd);

        if (cmd == "send"){
            std::string request = ScanTerminal();

            socklen_t len = sizeof(server_addr); 

            UDP::SendText(client, request.c_str(), request.size(), &server_addr, len);

            std::string reply = UDP::RecvText(client, &server_addr, &len);
            std::cout << "Server reply: " << reply << std::endl;
        }
        else if (cmd == "close"){
            Close(client);
            std::cout << "Client off.\n";
            
            break;
        }
        else {
            std::cout << "Uncorrect command.\n";
        }
    }
}