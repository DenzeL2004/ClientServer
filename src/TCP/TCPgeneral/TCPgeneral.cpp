#include "TCPgeneral.hpp"

void TCP::Listen(int server) {
    if (listen(server, TCP::kCountConnectionRequest)){
        throw std::runtime_error(std::format("Something went wrong with listen(server = {}).\n Errno status: {}.\n", 
                                            server, std::strerror(errno)));
    }
}

int TCP::Accept(int server) {
    int client = accept(server, nullptr, nullptr);

    if (client < 0) {
        throw std::runtime_error(std::format("Something went wrong with accept(server = {}).\n Client_fd = {}.\n Errno status: {}.\n", 
                                            server, client, std::strerror(errno)));
    }

    return client;
}

void TCP::MakeConnect(int client, int port, const char* ip_addr) {
    
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);

    if (connect(client, (struct sockaddr*)&server_addr, sizeof(server_addr))){
        throw std::runtime_error(std::format("Something went wrong with connect(client = {}, port = {}, ip_addr = {}).\n Errno status: {}.\n", 
                                            client, port, ip_addr, std::strerror(errno)));
    }
}

#include <iostream>

std::string TCP::RecvText(int socket) {
    size_t msg_len = 0;
    Recv(socket, &msg_len, sizeof(msg_len), 0);

    std::string buffer(msg_len, 0);

    size_t read_bytes = 0;
    do {

        int result = Recv(socket, buffer.data() + read_bytes, msg_len - read_bytes, 0);
        if (result == 0) {
            break;
        }

        read_bytes += result;

    }while (read_bytes < msg_len);
    
    return buffer;
}

int TCP::SendText(int socket, const char* buffer, size_t len) { 
    Send(socket, &len, sizeof(len), 0);
    return Send(socket, buffer, len, 0);
}