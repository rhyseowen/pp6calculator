#include <iostream>
#include <climits>
#include <vector>

#include "weekTwoMenu.hpp"
#include "PP6Math.hpp"
#include "pp6menu.hpp"

int weekTwoMenu()
{
	int err = 0;

	while(true){
		std::cout << "Which Operation would you like to perform " << std::endl;
		std::cout << ": ";

		std::string opperation;
		std::cin >> opperation;

		//fail in input is broken
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n'); 
			err = 2;
			continue;
		}

		if (opperation == "swap")
		{
			wk2_swap();
		}else if (opperation == "sort")
		{
			wk2_sort();

		}else if (opperation == "vectorSort"){
			wk2_vectorSort();

		}else if (opperation == "help")
		{
			//help statement
			weekTwoPrintHelp();
		}else if (opperation == "quit" || opperation == "q")
		{
			return err;
		}else{
			std::cout << "Operator not recognised"<<std::endl;
			err = 2;
			continue;
		}
	}
}

void weekTwoPrintHelp()
{
	std::cout << "Available operations: " << std::endl;
	std::cout << "swap : swap 2 numbers" << std::endl;
	std::cout << "sort : sort 8 numbers" << std::endl;
	std::cout << "vectorSort : sort 8 numbers (using a vector instead of an array)" << std::endl;
	std::cout << "quit : exit the calculator" << std::endl;
}

int wk2_swap()
{
	std::cout << " swap a and b" << std::endl;
	std::vector<double> number = readInNumbers(2);
	std::cout << "Swap " << number[0] << " and " << number[1] << " -> ";
	swap(number[0],number[1]);
	std::cout << number[0] << " and " << number[1] << std::endl;
	return 0;
}
int wk2_sort()
{
	std::cout << "Sort 8 numbers" << std::endl;
	std::vector<double> number = readInNumbers(8);
	double *p_array = &number[0];
	bubbleSort(p_array,8);

	std::cout << "Sorted list: " ;

	for (int i = 0; i < 8; ++i)
	{
		std::cout << number[i] << ", ";
	}

	std::cout << std::endl;
	return 0;
}
int wk2_vectorSort()
{
	std::cout << "Sort 8 numbers" << std::endl;
	std::vector<double> number = readInNumbers(8);

	bubbleSort(number);

	std::cout << "Sorted list: " ;

	for (int i = 0; i < 8; ++i)
	{
		std::cout << number[i] << ", ";
	}

	std::cout << std::endl;

	return 0;
}
