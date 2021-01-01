cmake_minimum_required(VERSION 3.17)
project(c_sandbox)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/header)

add_executable(helloworld
        src/helloworld.c)

#todo: add more executables, if you need
add_executable(operators
        src/operators.c)

add_executable(operatorsLogical
        src/operatorsLogical.c)

add_executable(getInput
        src/header/interaction.h
        src/getInput.c
        src/utility/interaction.c)
