#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

#include "weekThreeMenu.hpp"
#include "pp6menu.hpp"
#include "PP6Math.hpp"
#include "FourVector.hpp"
#include "Particle.hpp"

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
		}if (opperation == "boost_z" || opperation == "2")
		{
			err = wk3_boostZ();
		}else if (opperation == "generateMuons" || opperation == "3")
		{
			err = wk3_generateMuons();
		}else if (opperation == "help" || opperation == "h")
		{
			//help statement
			weekThreePrintHelp();
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



void weekThreePrintHelp()
{
	std::cout << "Week Three Menu: available operations: " << std::endl;
	std::cout << "1) interval : Calculate the interval of a 4 vector" << std::endl;
	std::cout << "2) boost_z : boost a four vector along the z axis" << std::endl;
	std::cout << "3) generateMuons: Generate Muons and use the particle class" << std::endl;
	std::cout << "h) help : Print this Message" << std::endl;
	std::cout << "u) up : Go up one menu level" << std::endl;
	std::cout << "q) quit : exit the calculator" << std::endl;
}

int wk3_interval()
{
	std::vector<double> number = readInNumbers(4);
	FourVector vect =  FourVector(number[0], number[1], number[2], number[3]);
	std::cout << "Interval = " << vect.getInterval() << std::endl;

	return 0;
}

int wk3_boostZ()
{
	std::vector<double> number = readInNumbers(5);
	FourVector vect =  FourVector(number[0], number[1], number[2], number[3]);

	vect.boost_z(number[4]);

	std::cout << "New values a0 = " << vect.getA0() << " a1 = " << vect.getA1() << " a2 = " << vect.getA2() << " a3 = " << vect.getA3() << std::endl;


	return 0;
}

int wk3_generateMuons()
{
	std::cout << "Generate 100 random muons" << std::endl;
	
	const int numberOffMuons = 100;
	double E[numberOffMuons];
	double px[numberOffMuons];
	double py[numberOffMuons];
	double pz[numberOffMuons];

	Particle Muons[numberOffMuons];

	generateMuons(numberOffMuons, E, px, py, pz);

	for (int i = 0; i < numberOffMuons; ++i)
	{
		Muons[i] = Particle("mu", -1, E[i], px[i], py[i], pz[i]);
	}

	int results[numberOffMuons];

	bubbleSort(E, results, numberOffMuons);

	for (int i = 0; i < numberOffMuons; ++i)
	{
		std::cout << Muons[results[i]].getFourMomentum() << std::endl;
	}

	double mean_E = 0;

	for (int i = 0; i < numberOffMuons; ++i)
	{
		mean_E += Muons[i].getFourMomentum().getA0()/((double)numberOffMuons);
	}

	std::cout << "Mean energy = " << mean_E << std::endl;

	double stdDeviation = 0;

	for (int i = 0; i < numberOffMuons; ++i)
	{
		stdDeviation += ((Muons[i].getFourMomentum().getA0() - mean_E)*(Muons[i].getFourMomentum().getA0() - mean_E))/((double)numberOffMuons);
	}

	stdDeviation = sqrt(stdDeviation);

	std::cout << "Standard deviation = " << stdDeviation << std::endl;

	return 0;
}
