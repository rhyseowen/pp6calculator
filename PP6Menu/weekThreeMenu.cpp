#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

#include "weekThreeMenu.hpp"
#include "pp6menu.hpp"
#include "FourVector.hpp"

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

		if (opperation == "interval" || opperation == "1")
		{
			err = wk3_interval();
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
	std::cout << "1) interval : Calculate the interval of a 4 vector" << std::endl;
	std::cout << "h) help : Print this Message" << std::endl;
	std::cout << "u) up : Go up one menu level" << std::endl;
	std::cout << "q) quit : exit the calculator" << std::endl;
}

int wk3_interval()
{
	std::vector<double> number = readInNumbers(4);
	FourVector vect =  FourVector(number[0], number[1], number[2], number[3]);
	std::cout << "Interval = " << vect.FourVectorInerval() << std::endl;

	return 0;
}
