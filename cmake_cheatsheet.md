# cmake cheatsheet

Yangqing Jia's link: https://rix0r.nl/blog/2015/08/13/cmake-guide/

## Basics
- cmake, cmake-gui
- In commands, capital and lower letters do not matter
- message() print logs: message(FATAL_ERROR "GCC version must be at least 7.1!")
- variables: ${xxx}
- set variables: set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
- set set(ELF_SOURCES Pybind.cc concurrency/Counter.cc logging/Pybind.cc)

## Flags
- CMAKE_CXX_STANDARD: 17
- CMAKE_CXX_FLAGS: -Wall -Werror -Wextra -Wno-register -fPIC -march=native
- PYBIND11_CPP_STANDARD: -std=c++17
- CMAKE_BUILD_TYPE: Release
- CMAKE_CURRENT_SOURCE_DIR
- CMAKE_C_COMPILER
- CMAKE_CXX_COMPILER
- CMAKE_C_FLAGS
- EXECUTABLE_OUTPUT_PATH
- LIBRARY_OUTPUT_PATH

## General process
- cmake_minimum_required(VERSION 3.3)
- project(elf)
- find header files: include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src_cpp/)
- add other projects with their own CMakeLists in building: add_subdirectory(src_cpp/elf ${CMAKE_CURRENT_BINARY_DIR}/elf)
- To build a library file: add_library(elf ${ELF_SOURCES}) will build a libelf.a; add_library(name [STATIC | SHARED | MODULE] source1)
- enable_testing() to enable tests in cmake
- add_executable(test_name test_file)
- target_link_libraries(test_name elf gtest)

## Find Packages
- find_package(Threads)
- find_package(TBB REQUIRED tbb)  # Need to find_package in parent scope


## execute something
execute_process(COMMAND git rev-parse HEAD OUTPUT_VARIABLE GIT_COMMIT_HASH)

## function

## pybind library
- pybind11_add_module(py_elfgames_go pybind_module.cc)
- target_link_libraries(py_elfgames_go PRIVATE elfgames_go zmq)
- py_elfgames_go is importable in python

## other important
- string
- list