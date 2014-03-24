#include <iostream>
#include <climits>
#include <string>

#include "weekFourMenu.hpp"
#include "FileReader.hpp"


int weekFourMenu()
{
	int err = 0;

	weekFourPrintHelp();

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

		if (opperation == "pdg" || opperation == "1")
		{
			err = wk4_pdg();
		}else if (opperation == "help" || opperation == "h")
		{
			//help statement
			weekFourPrintHelp();
		}else if (opperation == "up" || opperation == "u")
		{
			return err;
		}else if (opperation == "quit" || opperation == "q")
		{
			std::exit(err);
		}else{
			std::cout << "Operator not recognised"<<std::endl;
			err = 2;
			continue;
		}
	}
}

void weekFourPrintHelp()
{
	std::cout << "Week Three Menu: available operations: " << std::endl;
	std::cout << "1) pdg : print values from pdg database" << std::endl;
	std::cout << "h) help : Print this Message" << std::endl;
	std::cout << "u) up : Go up one menu level" << std::endl;
	std::cout << "q) quit : exit the calculator" << std::endl;
}

int wk4_pdg()
{
	FileReader f("observedparticles.dat");
	if (f.isValid())	
	{
		while (f.nextLine())
		{
			std::cout << f.getField<int>(1) << " ";
			std::cout << f.getField<std::string>(2) << " ";
			std::cout << f.getField<double>(3) << " ";
			std::cout << f.getField<double>(4) << " ";
			std::cout << f.getField<double>(5) << " ";
			std::cout << f.getField<std::string>(6) << std::endl;
		}
	}
	return 0;

}
