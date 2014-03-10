#include <iostream>
#include <climits>

#include "topMenu.hpp"
#include "weekOneMenu.hpp"
#include "weekTwoMenu.hpp"


int topMenu()
{
	int err = 0;

	while(true){
		std::cout << "Which menu would you like? (help to show available menus) " << std::endl;
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

		if (opperation == "1")
		{
			err = weekOneMenu();
		}else if (opperation == "2")
		{
			err = weekTwoMenu();
		}else if (opperation == "help")
		{
			//help statement
			topMenuPrintHelp();
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

void topMenuPrintHelp()
{
	std::cout << "Available menus: " << std::endl;
	std::cout << "1 : week one (arithmatic)" << std::endl;
	std::cout << "2 : week two (data operations)" << std::endl;
	std::cout << "quit : exit the calculator" << std::endl;
}
