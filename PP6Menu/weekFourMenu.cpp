#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cmath>


#include "weekFourMenu.hpp"
#include "FileReader.hpp"
#include "ParticleInfo.hpp"
#include "Particle.hpp"


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
		}else if (opperation == "readinmuons" || opperation == "3")
		{
			err = wk4_readInMuons();
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
	std::cout << "3) readinmuons : Read in muons from file and print out the 10 pairs with highest invarient mass" << std::endl;
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

bool sortFunction(const std::pair<double,std::pair<Particle*,Particle*>>& lhs, const std::pair<double,std::pair<Particle*,Particle*>>& rhs)
{
	return lhs.first > rhs.first;
}

int wk4_readInMuons()
{
	FileReader f("observedparticles.dat");
	ParticleInfo info("pdg.dat");

	std::vector<Particle*> mu_p;
	std::vector<Particle*> mu_n;

	//Read in Particles
	if (f.isValid())
	{
		while(f.nextLine())
		{
			int event = f.getField<int>(1);
			std::string particleName = f.getField<std::string>(2);
			double px = f.getField<double>(3);
			double py = f.getField<double>(4);
			double pz = f.getField<double>(5);

			//look up mass from database and use it to calculte E (bit wastefull to do this everytime but only keep muons)
			double m = info.getMassGeV(info.getPDGCode(particleName));
			double E = sqrt(m*m + px*px + py*py + pz*pz);

			//Create particles for mu+ and mu- and push them back into their respective vectors
			if (particleName == "mu+")
			{
				Particle *p = new Particle(event, particleName, info.getCharge(info.getPDGCode(particleName)), E,px,py,pz);
				mu_p.push_back(p);
			}else if (particleName == "mu-")
			{
				Particle *p = new Particle(event, particleName, info.getCharge(info.getPDGCode(particleName)), E,px,py,pz);
				mu_n.push_back(p);
			}

		}
	}

	//vector to hold the invarient mass and the two particles which it belongs two 
	std::vector<std::pair<double,std::pair<Particle*,Particle*>>> invarientMass;
	//fill the vector avoiding duplicates
	for (unsigned int i = 0; i < mu_p.size(); ++i)
	{
		for (unsigned int j = i; j < mu_n.size(); ++j)
		{
			double m = sqrt(fabs((mu_p[i]->getFourMomentum() + mu_n[j]->getFourMomentum()).getInterval()));
			invarientMass.push_back(std::make_pair(m,std::make_pair(mu_p[i],mu_n[j])));
			
		}
	}

	//sort the vector the sortFunction only compairs the first element of the pairs (the invarient mass)
	std::sort(invarientMass.begin(), invarientMass.end(), sortFunction);

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Invarient Mass[GeV] = " << invarientMass[i].first;
		std::cout << " ,mu+ event number = " << invarientMass[i].second.first->getEvent();
		std::cout << " ,mu- event number = " << invarientMass[i].second.second->getEvent() << std::endl;
	}

	//delete particles to free up memory

	for (std::vector<Particle*>::iterator i = mu_p.begin(); i != mu_p.end(); ++i)
	{
		delete *i;
		*i = nullptr;
	}
	for (std::vector<Particle*>::iterator i = mu_n.begin(); i != mu_n.end(); ++i)
	{
		delete *i;
		*i = nullptr;
	}
	return 0;

}

