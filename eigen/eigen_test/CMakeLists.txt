cmake_minimum_required(VERSION 3.7)
project(my_program)

include_directories(/usr/local/include/eigen3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES my_program.cpp)
add_executable(my_program ${SOURCE_FILES})
