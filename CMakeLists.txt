cmake_minimum_required(VERSION 3.27)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DataStructures
        main.cpp
        BinarySearchTree.h
        HashMap.h
        Vec.h
        cmake-build-debug/FibHeap.h)
