cmake_minimum_required(VERSION 3.25)
project(stack)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(stack
        main.cpp
        stack_queue.cpp
        stack_queue.h)
