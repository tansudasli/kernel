cmake_minimum_required(VERSION 3.17)
project(dynamic-programming)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/header)

add_executable(fibonacci src/fibonacci.c)
add_executable(gridTraveller src/gridTraveller.c)