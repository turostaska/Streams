cmake_minimum_required(VERSION 3.15)
project(Stream)

set(CMAKE_CXX_STANDARD 17)

add_executable(Stream main.cpp stream.cpp stream.h linked_list.cpp linked_list.h eratosthenes.cpp eratosthenes.h)