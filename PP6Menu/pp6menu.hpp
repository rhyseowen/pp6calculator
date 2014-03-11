/** \file pp6menu.hpp
 *  \brief A library for menu related helper functions
 *  
 *  A general library of helper functions for the menu system. In an object orented progrm would probably be a superclass to other menu objects.
 */
#ifndef PP6MENU_HH
#define PP6MENU_HH 

#include <iostream>
#include <vector>
#include <climits>

/**
 * @brief Read in numbers for use by opperations
 * @details Promts user and reads in up to 8 numbers which are refered to by the letters a->h. The numbers are then returned as a vector to be used by the opperation
 * 
 * @param numbers Number of input numbers requiered
 * @return A vector containing the numbers input by the user
 */
std::vector<double> readInNumbers(int numbers);

#endif
