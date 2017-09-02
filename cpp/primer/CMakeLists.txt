cmake_minimum_required(VERSION 2.8.9)
project(primer_test)

file(GLOB SOURCES "*.cpp")
add_executable(primer_test ${SOURCES})
