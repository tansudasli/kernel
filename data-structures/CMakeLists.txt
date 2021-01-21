cmake_minimum_required(VERSION 3.17)
project(ansi_c)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/header)

add_executable(linkedList
        src/header/list.h
        src/collection/list.c
        src/linkedList.c)