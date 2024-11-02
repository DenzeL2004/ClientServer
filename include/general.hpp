#pragma once

#include <cstring>
#include <exception>
#include <format>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int CreateServer(int port, const char* ip_addr, int protocol);

int CreateClient(int protocol);

void Close(int socket);

int Recv(int socket, void* buffer, size_t len, int flag);

int Send(int socket, const void* buffer, size_t len, int flag);