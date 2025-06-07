cmake_minimum_required(VERSION 3.31)
project(coroutines CXX)

set(CMAKE_CXX_STANDARD 26)

add_executable(coroutines main.cpp
        coroutine.hpp
        coroutine.cpp)
