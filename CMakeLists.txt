#cmake script for pp6 Calculator
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#declare prject
project(pp6calculator)

#include directories
include_directories(PP6Lib)

#define execuatable
add_executable(pp6calculator pp6calculator.cpp PP6Lib/PP6Math.cpp PP6Lib/PP6Math.hpp)