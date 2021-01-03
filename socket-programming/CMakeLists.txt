cmake_minimum_required(VERSION 3.17)
project(socket_programming)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/header)

#run w/
# cmake --build cmake-build-debug --target all -- -j 9
add_executable(tcp_client
        src/tcpClient.c)

add_executable(tcp_server
        src/tcpServer.c)