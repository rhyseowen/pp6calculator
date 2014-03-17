#include "FourVector.hpp"

struct FourVector
{
	double a0;
	double a1;
	double a2;
	double a3;
};

FourVector* createFourVector(){
	return new FourVector;
}

void destroyFourVector(FourVector *&p)
{
	if (p)
	{
		delete p;
		p =0;
	}
}