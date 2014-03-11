/**
 * @file pp6calculator.cpp
 * @brief Main executable for pp6calculator
 * @details Main executable which calls top menu and returns errors propagated up from the menu system
 */

#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <cmath>
#include "topMenu.hpp"

/**
 * @brief Main function
 * @return Error code
 */
int main()
{

	int err = 0;

	err = topMenu();

	return err;
}



