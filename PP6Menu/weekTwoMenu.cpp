#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

#include "weekTwoMenu.hpp"
#include "PP6Math.hpp"
#include "pp6menu.hpp"
#include "FileReader.hpp"

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

		}else if (opperation == "generateMuons")
		{
			wk2_generateMuons();
		}else if (opperation == "readInMuons")
		{
			wk2_readInMuons();
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
	std::cout << "generateMuons : Generate 100 random muons" << std::endl;
	std::cout << "readInMuons : Read in muons from file" << std::endl;
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

int wk2_generateMuons()
{
	std::cout << "Generate 100 random muons" << std::endl;
	
	const int numberOffMuons = 100;
	double E[numberOffMuons];
	double px[numberOffMuons];
	double py[numberOffMuons];
	double pz[numberOffMuons];

	generateMuons(numberOffMuons, E, px, py, pz);

	int results[numberOffMuons];

	bubbleSort(E, results, numberOffMuons);

	for (int i = 0; i < numberOffMuons; ++i)
	{
		std::cout << "E= " << E[results[i]] << " px= " << px[results[i]] << " py= " << py[results[i]] << " pz= " << pz[results[i]] << std::endl;
	}

	//calculate mean

	//calculate standard deviation

	return 0;
}

int wk2_readInMuons()
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
			invarientMuonMass[address] = invarientMass(mu_p_E[mu_p], mu_p_px[mu_p], mu_p_py[mu_p], mu_p_pz[mu_p], mu_n_E[mu_n], mu_n_px[mu_n], mu_n_py[mu_n], mu_n_pz[mu_n]);
			// std::cout<<address << " " << invarientMuonMass[address] <<std::endl;
		}
	}

	int sortResults[128*128] = {0};

	std::cout << "Sorting invarient masses" << std::endl;

	bubbleSort(invarientMuonMass, sortResults, 128*128);

	std::cout << "Top 10 invarient masses:" <<std::endl; 

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Invarient mass = " << invarientMuonMass[sortResults[i]] << " mu+ = " << mu_p_evt[(sortResults[i]>>7)] << " mu- = " << mu_n_evt[(sortResults[i]&0x7F)] << std::endl;
		// std::cout << mu_p_E[(sortResults[i]>>7)] << " " << mu_p_px[(sortResults[i]>>7)] << " " << mu_p_py[(sortResults[i]>>7)] << " " << mu_p_pz[(sortResults[i]>>7)] << std::endl;
		// std::cout << mu_n_E[(sortResults[i]&0x7F)] << " " << mu_n_px[(sortResults[i]&0x7F)] << " " << mu_n_py[(sortResults[i]&0x7F)] << " " << mu_n_pz[(sortResults[i]&0x7F)] << std::endl <<std::endl;
	}

	return 0;
}

int getMuonInformation(std::string filename, double muonMass, double *mu_p_px, double *mu_p_py, double *mu_p_pz, double *mu_p_E, int *mu_p_evt, double *mu_n_px, double *mu_n_py, double *mu_n_pz, double *mu_n_E, int *mu_n_evt)
{
	int number_mu_p = 0;
	int number_mu_n = 0;
	//use file reader to open up file
	FileReader f(filename);
	// Only process if the file is open/valid
	if (f.isValid()) {
  		// Loop until out of lines
		while (f.nextLine()) {

    		// retrieve field 2 as a string (starting at 1)
			std::string particle = f.getFieldAsString(2);

			if (particle == "mu+")
			{
				mu_p_evt[number_mu_p] = f.getFieldAsInt(1);
				mu_p_px[number_mu_p] = f.getFieldAsDouble(3);
				mu_p_py[number_mu_p] = f.getFieldAsDouble(4);
				mu_p_pz[number_mu_p] = f.getFieldAsDouble(5);

				mu_p_E[number_mu_p] = sqrt(muonMass*muonMass + mu_p_px[number_mu_p]*mu_p_px[number_mu_p] + mu_p_py[number_mu_p]*mu_p_py[number_mu_p] + mu_p_pz[number_mu_p]*mu_p_pz[number_mu_p]);
				++number_mu_p;
			}else if (particle == "mu-")
			{
				mu_n_evt[number_mu_n] = f.getFieldAsInt(1);
				mu_n_px[number_mu_n] = f.getFieldAsDouble(3);
				mu_n_py[number_mu_n] = f.getFieldAsDouble(4);
				mu_n_pz[number_mu_n] = f.getFieldAsDouble(5);

				mu_n_E[number_mu_n] = sqrt(muonMass*muonMass + mu_n_px[number_mu_n]*mu_n_px[number_mu_n] + mu_n_py[number_mu_n]*mu_n_py[number_mu_n] + mu_n_pz[number_mu_n]*mu_n_pz[number_mu_n]);

				++number_mu_n;
			}

    		// Check that input is o.k.
			if (f.inputFailed()) break;
		}
	}

	return 0;
}

int getNumberOfMuons(std::string filename, int& number_mu_p, int& number_mu_n)
{

	//use file reader to open up file
	FileReader f(filename);
	// Only process if the file is open/valid
	if (f.isValid()) {
  		// Loop until out of lines
		while (f.nextLine()) {

    		// retrieve field 2 as a string (starting at 1)
			std::string particle = f.getFieldAsString(2);

			if (particle == "mu+")
			{
				++number_mu_p;
			}else if (particle == "mu-")
			{
				++number_mu_n;
			}

    		// Check that input is o.k.
			if (f.inputFailed()) break;
		}
	}
	return 0;

}

