#cmake script for pp6 Calculator
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#declare prject
project(pp6calculator)

#add custom compiler flags
include(CheckCXXCompilerFlag)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	check_cxx_compiler_flag(-std=c++11 HAS_GNUSTYLE_CPP11)
	if(HAS_GNUSTYLE_CPP11)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
	endif()

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic-errors -Wall -Wextra -Werror -Wfatal-errors -Wwrite-strings -Woverloaded-virtual -fno-nonansi-builtins -fno-gnu-keywords -fstrict-aliasing")
endif()

#include directories
include_directories(PP6Lib)
include_directories(PP6Menu)

#add subdirectory contining instructions for pp6lib 
add_subdirectory(PP6Lib)
add_subdirectory(PP6Menu)

#define execuatable
add_executable(pp6calculator pp6calculator.cpp)

#link executable to library
target_link_libraries(pp6calculator pp6menu)

# Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

#Package pp6calculator sources and execuatable
include(CPack)
