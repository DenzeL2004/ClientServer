#pragma once

#include <cstring>
#include <exception>
#include <format>
#include <fstream>
#include <iostream>

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

const size_t kMaxBufferSize = 1 << 15;

int CreateServer(int port, const char* ip_addr, int type);

int CreateClient(int type);

void Close(int socket);

int Recv(int socket, void* buffer, size_t len, int flag);

int Send(int socket, const void* buffer, size_t len, int flag);

int Recvfrom(int socket, void* buffer, size_t len, int flag, struct sockaddr* src, socklen_t* src_len);

int Sendto(int socket, const void* buffer, size_t len, int flag, const struct sockaddr* dst, socklen_t dst_len);

std::string ScanTerminal();