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
include_directories(FileReader-1.0.0)

#add subdirectory contining instructions for pp6lib 
add_subdirectory(PP6Lib)
add_subdirectory(PP6Menu)
add_subdirectory(FileReader-1.0.0)

#define execuatable
add_executable(pp6calculator pp6calculator.cpp)

#link executable to library
target_link_libraries(pp6calculator topMenu)

#copy data file from source directort to build directory
configure_file(observedparticles.dat ${CMAKE_CURRENT_BINARY_DIR}/observedparticles.dat COPYONLY)
configure_file(pdg.dat ${CMAKE_CURRENT_BINARY_DIR}/pdg.dat COPYONLY)


# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)

# Install pp6calculator to the bin subdirectory of CMAKE_INSTALL_PREFIX
install(TARGETS pp6calculator DESTINATION bin)

#Package pp6calculator sources and execuatable
include(CPack)
