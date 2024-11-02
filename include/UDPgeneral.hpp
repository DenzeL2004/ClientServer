#pragma once

#include "general.hpp"

#include <string>

namespace UDP {

std::string RecvText(int dst_socket, struct sockaddr_in* src_adrr, socklen_t* src_len);

int SendText(int src_socket, const char* buffer, size_t len, struct sockaddr_in* dst_adrr, socklen_t dst_len);

}