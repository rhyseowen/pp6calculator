#add pp6menu as a library
add_library(pp6menu STATIC topMenu.cpp topMenu.hpp weekOneMenu.cpp weekOneMenu.hpp) 
target_link_libraries(pp6menu pp6lib)