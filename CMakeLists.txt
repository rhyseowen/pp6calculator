#cmake script for pp6 Calculator
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#declare prject
project(pp6calculator)

#include directories
include_directories(PP6Lib)

#add pp6lib as a library
add_library(pp6lib PP6Lib/PP6Math.cpp PP6Lib/PP6Math.hpp) 

#define execuatable
add_executable(pp6calculator pp6calculator.cpp)

#link executable to library
target_link_libraries(pp6calculator pp6lib)