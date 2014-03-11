/** \file pp6menu.cpp
 *  \brief A library for menu related helper functions
 *  
 *  A general library of helper functions for the menu system. In an object orented progrm would probably be a superclass to other menu objects.
 */

#include "pp6menu.hpp"


std::vector<double> readInNumbers(int numbers)
{
	std::vector<double> in_numbers;

	for (int i = 0; i < numbers; ++i)
	{
		double number;
		char charlist[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
		std::cout << "Set variable " << charlist[i] << std::endl << ": ";
		std::cin >> number;

		if (!std::cin)
		{
			//if cin is broken flush and jump back an itteration
			std::cout << "Number not recognised" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			--i;
			continue;
		}

		in_numbers.push_back(number);

	}
	return in_numbers;
}
