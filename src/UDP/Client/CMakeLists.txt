
cmake_minimum_required(VERSION 3.17)

SET(TASK_NAME UDPClient)

add_executable(${TASK_NAME} client.cpp ../../general/general.cpp ../UDPgeneral/UDPgeneral.cpp)

