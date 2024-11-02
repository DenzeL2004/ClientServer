#pragma once

#include "general.hpp"

#include <string>

namespace TCP {

const int kCountConnectionRequest = 1;

void Listen(int server);

int Accept(int server);

void MakeConnect(int client, int port, const char* ip_addr);

std::string RecvText(int socket);

int SendText(int socket, const char* buffer, size_t len);

}