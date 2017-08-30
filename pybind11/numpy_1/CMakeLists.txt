cmake_minimum_required(VERSION 2.8.12)
project(example)

find_package(pybind11 REQUIRED)
# add_subdirectory(pybind11)

set(PYBIND11_TEST_FILES
  test_numpy_array.cc
)

pybind11_add_module(test_numpy test_numpy_array.cc)
