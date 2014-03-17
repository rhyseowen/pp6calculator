#include "FourVector.hpp"
#include "PP6Math.hpp"

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

FourVector* createFourVector(double a0, double a1, double a2, double a3)
{
	FourVector * p = new FourVector;
	p->a0 = a0;
	p->a1 = a1;
	p->a2 = a2;
	p->a3 = a3;

	return p;
}

FourVector* createFourVector(FourVector* initial)
{
	FourVector * p = createFourVector(initial->a0, initial->a1, initial->a2, initial->a3);
	return p;

}

FourVector* boost_z(FourVector* vector, double v)
{
	FourVector * p = createFourVector(vector);

	fourVectorZBoost(p->a0, p->a3, v);
	return p;
}

void destroyFourVector(FourVector *&p)
{
	if (p)
	{
		delete p;
		p =0;
	}
}