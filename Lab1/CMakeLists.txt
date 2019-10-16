cmake_minimum_required(VERSION 3.14)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")

add_executable(Lab1 main.cpp tritset.cpp tritset.h trit.h trit.cpp catch.hpp tests.cpp)

