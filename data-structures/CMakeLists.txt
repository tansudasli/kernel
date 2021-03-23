cmake_minimum_required(VERSION 3.17)
project(ansi_c)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/header)

add_executable(linkedList
        src/header/LinkedList.h
        src/collection/LinkedList.c
        src/linkedList.c)

add_executable(linkedList.Middle
        src/header/LinkedList.h
        src/collection/LinkedList.c
        src/linkedList.middle.c)

add_executable(linkedList.Search
        src/header/LinkedList.h
        src/collection/LinkedList.c
        src/linkedList.search.c)

add_executable(linkedList.BinarySearch
        src/header/LinkedList.h
        src/collection/LinkedList.c
        src/linkedList.binarySearch.c)


add_executable(linkedList.SortedInsert
        src/header/LinkedList.h
        src/collection/LinkedList.c
        src/linkedList.sortedInsert.c)

add_executable(stack
        src/header/Stack.h
        src/collection/Stack.c
        src/stack.c)

add_executable(stack.isBalanced
        src/header/Stack.h
        src/collection/Stack.c
        src/stack.isBalanced.c)

add_executable(stack.reverse
        src/header/Stack.h
        src/collection/Stack.c
        src/stack.reverse.c)


add_executable(queue
        src/header/Queue.h
        src/collection/Queue.c
        src/queue.c)

add_executable(stockSpanProblem
        ../data-structures/src/stockSpanProblem.c)

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

