#include "UDPgeneral.hpp"

std::string UDP::RecvText(int dst_socket, struct sockaddr_in* src_adrr, socklen_t* src_len) {
    
    std::string buffer(kMaxBufferSize, 0);

    Recvfrom(dst_socket, buffer.data(), kMaxBufferSize, MSG_WAITALL, (struct sockaddr*)src_adrr, src_len);
        
    return buffer;
}

int UDP::SendText(int src_socket, const char* buffer, size_t len, struct sockaddr_in* dst_adrr, socklen_t dst_len) { 
    return Sendto(src_socket, buffer, len, MSG_CONFIRM, (const struct sockaddr*)dst_adrr, dst_len);
}