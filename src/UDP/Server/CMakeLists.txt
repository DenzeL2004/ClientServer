
cmake_minimum_required(VERSION 3.17)

SET(TASK_NAME UDPServer)

add_executable(${TASK_NAME} server.cpp ../../general/general.cpp ../UDPgeneral/UDPgeneral.cpp)
