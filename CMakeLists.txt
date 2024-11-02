cmake_minimum_required(VERSION 3.17)

project(server-client)

include_directories(include)

add_compile_options(-std=c++20)

add_subdirectory(src/TCP/Server)
add_subdirectory(src/TCP/Client)
