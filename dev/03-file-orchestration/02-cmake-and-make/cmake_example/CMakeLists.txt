cmake_minimum_required(VERSION 3.28.3)

set(CMAKE_CXX_STANDARD 17)

project(demo)

add_executable(demo src/main.cpp src/increment_and_sum.cpp src/vect_add_one.cpp)