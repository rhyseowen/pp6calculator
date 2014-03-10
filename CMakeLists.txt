#cmake script for pp6 Calculator
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#declare prject
project(pp6calculator)

#include directories
include_directories(PP6Lib)

#add subdirectory contining instructions for pp6lib 
add_subdirectory(PP6Lib)

#define execuatable
add_executable(pp6calculator pp6calculator.cpp)

#link executable to library
target_link_libraries(pp6calculator pp6lib)