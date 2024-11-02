
cmake_minimum_required(VERSION 3.17)

SET(TASK_NAME TCPServer)

add_executable(${TASK_NAME} server.cpp ../../general/general.cpp ../TCPgeneral/TCPgeneral.cpp)
