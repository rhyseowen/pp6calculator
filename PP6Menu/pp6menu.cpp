#include "pp6menu.hpp"

/*
Nominal "superclass" for menus for helpfull functions which arent "math"
*/


std::vector<double> readInNumbers(int numbers)
{
	/*
		Function to read in a variable number of doubles from std::cin. Maximum number is 8 
		dictated by the length of the charlist

	*/
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
