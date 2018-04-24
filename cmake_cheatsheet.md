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
- CMAKE_MODULE_PATH: look for packages here
- CMAKE_C_COMPILER
- CMAKE_CXX_COMPILER
- CMAKE_C_FLAGS
- EXECUTABLE_OUTPUT_PATH
- LIBRARY_OUTPUT_PATH
- PROJECT_SOURCE_DIR

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
- find_package(OpenCV REQUIRED)

## execute something
execute_process(COMMAND git rev-parse HEAD OUTPUT_VARIABLE GIT_COMMIT_HASH)

## function

## pybind library
- pybind11_add_module(py_elfgames_go pybind_module.cc)
- target_link_libraries(py_elfgames_go PRIVATE elfgames_go zmq)
- py_elfgames_go is importable in python
- file(WRITE/APPEND/READ/GLOB/GLOB_RECURSE): file manipulation,

## other important
- add_custom_target: Add a target with no output so it will always be built.
- add_definitions: add_definitions(-DCPU_ONLY)
- configure_file(input output): copy a file to another location and modify its
contents
- foreach()
- include: load and run CMake code from a file or module
- include_directories: e.g. include_directories(SYSTEM ${GLOG_INCLUDE_DIRS})
- macro(name): define macro, paired with endmacro()
- marked_as_advanced:
- message(mode "message to say"): print out compiling message!!!
- option(USE_XXX "message" ON): options
- project(caffe): project setup, automatically set languages, and variables such
as PROJECT_SOURCE_DIR
- set(variable, value [CACHE] [FORCE] | [ PARENT_SCOPE])
- source_group(name FILES src): define a grouping of source files
- string()

## list
- list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)