#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

#include "weekThreeMenu.hpp"

int weekThreeMenu()
{
	int err = 0;

	weekThreePrintHelp();

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

		if (opperation == "swap" || opperation == "1")
		{
			//wk2_swap();
		}else if (opperation == "help" || opperation == "h")
		{
			//help statement
			weekThreePrintHelp();
		}else if (opperation == "up" || opperation == "u")
		{
			return err;
		}
		else if (opperation == "quit" || opperation == "q")
		{
			std::exit(err);
		}else{
			std::cout << "Operator not recognised"<<std::endl;
			err = 2;
			continue;
		}
	}
}



void weekThreePrintHelp()
{
	std::cout << "Week Two Menu: available operations: " << std::endl;
	std::cout << "1) swap : swap 2 numbers" << std::endl;
	std::cout << "h) help : Print this Message" << std::endl;
	std::cout << "u) up : Go up one menu level" << std::endl;
	std::cout << "q) quit : exit the calculator" << std::endl;
}
