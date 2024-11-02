#include "general.hpp"

int CreateServer(int port, const char* ip_addr, int type) {
    int server = socket(AF_INET, type, 0);

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);

    if (bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr))) {
        throw std::runtime_error(std::format("Something went wrong with bind(server = {}, port = {}, ip_addr = {}).\n Errno status: {}.\n", 
                                            server, port, ip_addr, std::strerror(errno)));
    }

    return server;
}

int CreateClient(int type) {
    return socket(AF_INET, type, 0); 
}

void Close(int socket) {
    if (close(socket)) {
        throw std::runtime_error(std::format("Something went wrong with close(socket = {}).\n Errno status: {}.\n", 
                                            socket, std::strerror(errno)));
    }
}

int Recv(int socket, void* buffer, size_t len, int flag) {
    int result = recv(socket, buffer, len, flag);
    if (result < 0){
        throw std::runtime_error(std::format("Something went wrong with recv(socket = {}, buffer = {}, len = {}, flag = {}).\n Socket_fd = {}.\n Errno status: {}.\n", 
                                            socket, buffer, len, flag, socket, std::strerror(errno)));
    }

    return result;
}

int Send(int socket, const void* buffer, size_t len, int flag) {
    int result = send(socket, buffer, len, flag);
    if (result < 0){
        throw std::runtime_error(std::format("Something went wrong with send(socket = {}, buffer = {}, len = {}, flag = {}).\n Socket_fd = {}.\n Errno status: {}.\n", 
                                            socket, buffer, len, flag, socket, std::strerror(errno)));
    }

    return result;
}

int Recvfrom(int socket, void* buffer, size_t len, int flag, struct sockaddr *src, socklen_t *src_len){
    int result = recvfrom(socket, buffer, len, flag, src, src_len);
    if (result < 0){
        throw std::runtime_error(std::format("Something went wrong with recvfrom(socket = {}, buffer = {}, len = {}, flag = {}).\n Socket_fd = {}.\n Errno status: {}.\n", 
                                            socket, buffer, len, flag, socket, std::strerror(errno)));
    }

    return result;
}

int Sendto(int socket, const void* buffer, size_t len, int flag, const struct sockaddr* dst, socklen_t dst_len) {
    int result = sendto(socket, buffer, len, flag, dst, dst_len);
    if (result < 0){
        throw std::runtime_error(std::format("Something went wrong with send(socket = {}, buffer = {}, len = {}, flag = {}).\n Socket_fd = {}.\n Errno status: {}.\n", 
                                            socket, buffer, len, flag, socket, std::strerror(errno)));
    }

    return result;
}

std::string ScanTerminal() {
    std::string text(kMaxBufferSize, 0);
    std::cin.getline(text.data(), kMaxBufferSize - 1);

    return text;
}