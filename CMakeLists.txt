cmake_minimum_required(VERSION 3.14)
project(tcp_learn C)

set(CMAKE_C_STANDARD 99)


add_library(
        server
        tcp/TCPServer.c
        tcp/TCPServer.h)

add_library(
        client
        tcp/TCPClient.c
        tcp/TCPClient.h)

add_executable(tcp_learn main.c)

target_link_libraries(tcp_learn server client)