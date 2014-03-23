#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

#include "weekThreeMenu.hpp"
//messy dependancy tree but allows use wk two features
#include "weekTwoMenu.hpp"
#include "pp6menu.hpp"
#include "PP6Math.hpp"
#include "FourVector.hpp"
#include "Particle.hpp"
#include "FileReader.hpp"

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

int wk3_readInMuons()
{


	int number_mu_p = 0;
	int number_mu_n = 0;

	getNumberOfMuons("observedparticles.dat",number_mu_p,number_mu_n);	

	std::cout << "No. mu+ = " << number_mu_p << " mu- = " << number_mu_n << std::endl;

	if ((number_mu_p > 128) || (number_mu_n > 128))
	{
		std::cout << "Too many muons" << std::endl;
		return 4;
	}

	//set up arrays to hold muon information

	double mu_p_px[128] = {0};
	double mu_p_py[128] = {0};
	double mu_p_pz[128] = {0};
	double mu_p_E[128] = {0};
	int mu_p_evt[128] = {0};

	double mu_n_px[128] = {0};
	double mu_n_py[128] = {0};
	double mu_n_pz[128] = {0};
	double mu_n_E[128] = {0};
	int mu_n_evt[128] = {0};

	getMuonInformation("observedparticles.dat", 0.1057, mu_p_px, mu_p_py, mu_p_pz, mu_p_E, mu_p_evt, mu_n_px, mu_n_py, mu_n_pz, mu_n_E, mu_n_evt);

	Particle MuonP[128];
	Particle MuonN[128];

	for (int i = 0; i < 128; ++i)
	 {
	 	MuonP[i] = Particle("mu", 1, mu_p_E[i], mu_p_px[i], mu_p_py[i], mu_p_pz[i]);
	 	MuonN[i] = Particle("mu", -1, mu_n_E[i], mu_n_px[i], mu_n_py[i], mu_n_pz[i]);
	 } 

	double invarientMuonMass[128*128] = {0};

	for (int mu_p = 0; mu_p < number_mu_p; ++mu_p)
	{
		for (int mu_n = 0; mu_n < number_mu_n; ++mu_n)
		{
			/* generate adress for invarient mass array using the mu_p concatonated to mu_n
			   results in a 14 bit number accesing a 16384 element array
			   mu_p can be recovered using mu_p = address>>7
			   mu_n can be recovered using mu_n = address&0x7F
			*/
			//start by shifting mu_p left 7 places
			int address = mu_p<<7;
			//OR mu_n into the 7 zeros left by mu_p
			address = address|mu_n;
			// invarientMuonMass[address] = invarientMass(mu_p_E[mu_p], mu_p_px[mu_p], mu_p_py[mu_p], mu_p_pz[mu_p], mu_n_E[mu_n], mu_n_px[mu_n], mu_n_py[mu_n], mu_n_pz[mu_n]);
			invarientMuonMass[address] = sqrt( (MuonP[mu_p].getFourMomentum() + MuonN[mu_n].getFourMomentum()).getInterval() );
			// std::cout<<address << " " << invarientMuonMass[address] <<std::endl;
		}
	}

	int sortResults[128*128] = {0};

	std::cout << "Sorting invarient masses" << std::endl;

	bubbleSort(invarientMuonMass, sortResults, 128*128);

	std::cout << "Top 10 invarient masses:" <<std::endl; 

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Invarient mass = " << invarientMuonMass[sortResults[i]] << " mu+ = " << MuonP[(sortResults[i]>>7)] << " mu- = " << MuonN[(sortResults[i]&0x7F)] << std::endl;
		// std::cout << mu_p_E[(sortResults[i]>>7)] << " " << mu_p_px[(sortResults[i]>>7)] << " " << mu_p_py[(sortResults[i]>>7)] << " " << mu_p_pz[(sortResults[i]>>7)] << std::endl;
		// std::cout << mu_n_E[(sortResults[i]&0x7F)] << " " << mu_n_px[(sortResults[i]&0x7F)] << " " << mu_n_py[(sortResults[i]&0x7F)] << " " << mu_n_pz[(sortResults[i]&0x7F)] << std::endl <<std::endl;
	}

	return 0;
}
