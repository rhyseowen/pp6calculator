#add pp6menu as a library
add_library(pp6menu STATIC topMenu.cpp topMenu.hpp) 

add_library(pp6menu_week_one STATIC weekOneMenu.cpp weekOneMenu.hpp)
target_link_libraries(pp6menu_week_one pp6lib)

add_library(pp6menu_week_two STATIC weekTwoMenu.cpp weekTwoMenu.hpp)
target_link_libraries(pp6menu_week_two pp6lib)

target_link_libraries(pp6menu pp6menu_week_one pp6menu_week_two)