#include "FourVector.hpp"
#include "PP6Math.hpp"


// static FourVector* FourVector::createFourVector(){
// 	return new FourVector();
// }

// static FourVector* FourVector::createFourVector(double a0, double a1, double a2, double a3)
// {
// 	FourVector * p = new FourVector();
// 	p->a0 = a0;
// 	p->a1 = a1;
// 	p->a2 = a2;
// 	p->a3 = a3;

// 	return p;
// }

// static FourVector* FourVector::createFourVector(FourVector* initial)
// {
// 	FourVector * p = createFourVector(initial->a0, initial->a1, initial->a2, initial->a3);
// 	return p;

// }

void FourVector::boost_z(const double v)
{

	fourVectorZBoost(a0, a3, v);
}

double FourVector::FourVectorInerval() const
{

		return interval(a0,a1,a2,a3);
}


// void FourVector::destroyFourVector(FourVector *&p)
// {
// 	if (p)
// 	{
// 		delete p;
// 		p =0;
// 	}
// }
