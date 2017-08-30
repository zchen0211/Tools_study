# A Summary

# Basics
# Step 1: Add executable 
cmake_minimum_required (VERSION 2.6)
project (Tutorial)
add_executable(Tutorial tutorial.cc)

# Step 2: Add a Library
add_library(MathFunctions mysqrt.cxx)

include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory (MathFunctions) 
