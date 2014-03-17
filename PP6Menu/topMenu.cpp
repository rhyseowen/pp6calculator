#include <iostream>
#include <climits>

#include "topMenu.hpp"
#include "weekOneMenu.hpp"
#include "weekTwoMenu.hpp"
#include "weekThreeMenu.hpp"


int topMenu()
{
	int err = 0;

	topMenuPrintHelp();

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

		if (opperation == "1" || opperation == "weekone")
		{
			err = weekOneMenu();
		}else if (opperation == "2" || opperation == "weektwo")
		{
			err = weekTwoMenu();
		}else if (opperation == "3" || opperation == "weekthree")
		{
			err = weekThreeMenu();
		}else if (opperation == "help" || opperation == "h")
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
	std::cout << "Top Menu : available menus: " << std::endl;
	std::cout << "1) weekone : week one (arithmatic)" << std::endl;
	std::cout << "2) weektwo : week two (data operations)" << std::endl;
	std::cout << "3) weekthree : week three (Four vector manipulation)" << std::endl;
	std::cout << "h) help : Show this message" << std::endl;
	std::cout << "q) quit : exit the calculator" << std::endl;
}
