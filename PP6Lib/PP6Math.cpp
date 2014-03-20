#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cfloat>
#include <cstdlib>

#include "PP6Math.hpp"




void swap(double& number1, double& number2)
{
	double temp = number1;
	number1 = number2;
	number2 = temp;
}

void swap(int& number1, int& number2)
{
	int temp = number1;
	number1 = number2;
	number2 = temp;
}

bool bubbleSort(double *array, int size)
{
	//list starts unsorted
	bool sorted = false;

	while(!sorted){
		//see if we needed a swap this itteration
		bool swapNeeded = false;
		for (int i = 0; i < (size -1); ++i)
		{
			//if a number is small than its neighbor to the right swap them
			if (array[i] < array[i+1])
			{
				swap(array[i], array[i+1]);
				swapNeeded = true;
			}
		}

		//if no swaps were needed the list is now soted and the while can finish
		sorted = !swapNeeded;
	}
	return sorted;
}

bool bubbleSort(double *array, int *results, int size)
{
	bool sorted = false;

	for (int i = 0; i < size; ++i)
	{
		results[i] = i;
	}

	while(!sorted){
		bool swapNeeded = false;
		for (int i = 0; i < (size -1); ++i)
		{
			if (array[results[i]] < array[results[i+1]])
			{
				swap(results[i], results[i+1]);
				swapNeeded = true;
			}
		}
		sorted = !swapNeeded;
	}
	return sorted;
}

bool bubbleSort(std::vector<double>& array)
{
	bool sorted = false;

	while(!sorted){
		bool swapNeeded = false;
		for (unsigned int i = 0; i < (array.size() -1); ++i)
		//unsigned int used to suppress compiler warnings
		{
			if (array[i] < array[i+1])
			{
				swap(array[i], array[i+1]);
				swapNeeded = true;
			}
		}
		sorted = !swapNeeded;
	}
	return sorted;
}


double multiply(double number1, double number2)
{
	return number1 * number2;
}

double divide(double number1, double number2)
{
	return number1 / number2;
}

double addition(double number1, double number2)
{
	return number1 + number2;
}

double subtraction(double number1, double number2)
{
	return number1 - number2;
}

double solveXaxis(double m, double c)
{
	// y = mc + c @y=0
	// x = -c/m
	return -c / m;
}

double solveQuadraticP(double a, double b, double c)
{
	//find the positive solution for a quadratic
	return (-b + sqrt(b*b - 4*a*c))/(2*a);
}

double solveQuadraticN(double a, double b, double c)
{
	//find the negetive solution for a quadratic
	return (-b - sqrt(b*b - 4*a*c))/(2*a);
}

bool solveQuadratic(double a, double b, double c, double& result1, double& result2)
{
	if ((b*b-4*a*c) < 0)
	{
		return false;
	}else{
		result1 = solveQuadraticP(a,b,c);
		result2 = solveQuadraticN(a,b,c);

		return true;
	}
}

double vectorLength3(double i, double j, double k)
{
	return sqrt(i*i+j*j+k*k);
}

double vectorDotProductSqrt4(double a0, double a1, double a2, double a3, double b0, double b1, double b2, double b3)
{
	//calculate the dot product between two four vectors a and b then square root it
	return sqrt(std::abs( vectorDotProduct4(a0,a1,a2,a3,b0,b1,b2,b3)));
}

double vectorDotProduct4(double a0, double a1, double a2, double a3, double b0, double b1, double b2, double b3)
{
	return ( a0*b0 - a1*b1 -a2*b2 - a3*b3);
}



bool doubleZeroCheck(double number)
{
	if ( (fabs(number - 0.0)) <=  DBL_EPSILON)
	{
		//number is probably 0
		return true;
	}else{
		return false;
	}
}

double invarientMass(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2)
{
	double m2 = 0;
	m2 = (E1 + E2)*(E1 + E2) - (px1+px2)*(px1+px2) - (py1+py2)*(py1+py2) - (pz1+pz2)*(pz1+pz2);
	return m2;
}

int generateMuons(int numberOfMuons, double *E, double *px, double *py, double *pz)
{
	/* initialize random seed: */
  	srand (time(NULL));

	for (int muon = 0; muon < numberOfMuons; ++muon)
	{
		double muonMass = 0.1057; // Muon Mass GeV 
		//generate an on shell muon with random momentum
		px[muon] = (rand()%2000 -1000)*0.001;
		py[muon] = (rand()%2000 -1000)*0.001;
		pz[muon] = (rand()%2000 -1000)*0.001;
		//in natural unit E^2 = m^2 + p^2
		E[muon] = sqrt(muonMass*muonMass + px[muon]*px[muon] + py[muon]*py[muon] + pz[muon]*pz[muon]);
	}
	return 0;
}

int fourVectorZBoost(double& a0, double& a3, double vz )
{
	 double a0Prime = lorentzGamma(vz)*(a0 - vz*a3);
	//a1 is unchanged
	//a2 is unchanged
	double a3Prime = lorentzGamma(vz)*(a3 - vz*a0);

	a0 = a0Prime;
	a3 = a3Prime;
	return 0;
}

double lorentzGamma(double v)
{
	return 1.0/(sqrt(1-(v/1)*(v/1)));
}

double interval(double a0, double a1, double a2, double a3)
{
	return vectorDotProduct4(a0,a1,a2,a3,a0,a1,a2,a3);
}

bool doubleCompare(const double& a, const double& b)
{
	if (a == b)
	{
		return true;
	}
	double error = fabs(a-b)/ (a > b ? a :b);
	if (error <= DBL_EPSILON)
	{
		return true;
	}
	return false;
}

