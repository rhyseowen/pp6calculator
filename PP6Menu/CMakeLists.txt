#add pp6menu as a library
add_library(pp6menu STATIC pp6menu.cpp pp6menu.hpp)

add_library(topMenu STATIC topMenu.cpp topMenu.hpp) 

add_library(pp6menu_week_one STATIC weekOneMenu.cpp weekOneMenu.hpp)
target_link_libraries(pp6menu_week_one pp6lib pp6menu)

add_library(pp6menu_week_two STATIC weekTwoMenu.cpp weekTwoMenu.hpp)
target_link_libraries(pp6menu_week_two pp6lib pp6menu FileReader)

add_library(pp6menu_week_three STATIC weekThreeMenu.cpp weekThreeMenu.hpp)
target_link_libraries(pp6menu_week_three pp6lib pp6menu)

target_link_libraries(topMenu pp6menu_week_one pp6menu_week_two pp6menu_week_three)