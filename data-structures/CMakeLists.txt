cmake_minimum_required(VERSION 3.17)
project(ansi_c)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/header)

add_executable(linkedList
        src/header/ArrayList.h
        src/collection/ArrayList.c
        src/linkedList.c)

#add_executable(collection
#        src/header/ArrayList.h
#        src/collection/ArrayList.c
#        src/header/Collection.h
#        src/collection/Collection.c
#        src/linkedList.c)
#
#add_executable(selectionSort
#        src/header/Sort.h
#        src/collection/Sort.c
#        src/selectionSort.c)

