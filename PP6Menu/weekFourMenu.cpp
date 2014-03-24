#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>


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
		}else if (opperation == "algo" || opperation == "2")
		{
			err = wk4_algo();
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
	std::cout << "2) algo : use STL algorithms" << std::endl;
	std::cout << "h) help : Print this Message" << std::endl;
	std::cout << "u) up : Go up one menu level" << std::endl;
	std::cout << "q) quit : exit the calculator" << std::endl;
}

int wk4_pdg()
{
	FileReader f("pdg.dat");

	std::vector<std::string> particleType;
	std::vector<int> idNumber;
	std::vector<int> charge;
	std::vector<double> mass;

	if (f.isValid())	
	{
		while (f.nextLine())
		{
			particleType.push_back( f.getField<std::string>(1));
			idNumber.push_back( f.getField<int>(2));
			charge.push_back( f.getField<int>(3));
			mass.push_back( f.getField<double>(4));

		}
	}


	for (unsigned int i = 0; i < particleType.size(); ++i)
	{
		std::cout << particleType[i] << " " << idNumber[i] << " " << charge[i] << " " << mass[i] << std::endl;
	}
	return 0;

}

int wk4_algo()
{
	/* initialize random seed: */
  	srand (time(NULL));

	std::vector<int> randInts;

	randInts.resize(10);

	for (std::vector<int>::iterator i = randInts.begin(); i != randInts.end(); ++i)
	{
		*i = rand()%100;
	}

	std::copy(randInts.begin(), randInts.end(), std::ostream_iterator<int>(std::cout, "\n"));

	std::cout << "MAX = " << *std::max_element(randInts.begin(), randInts.end()) << std::endl;

	std::cout << "MIN = " << *std::min_element(randInts.begin(), randInts.end()) << std::endl;

	std::sort(randInts.begin(), randInts.end());

	std::copy(randInts.begin(), randInts.end(), std::ostream_iterator<int>(std::cout, "\n"));

	return 0;
}
