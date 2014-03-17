#include "FourVector.hpp"
#include "PP6Math.hpp"


FourVector::FourVector(double a0_in, double a1_in, double a2_in, double a3_in)
	: a0(a0_in), a1(a1_in), a2(a2_in), a3(a3_in)
{}

FourVector::FourVector(const FourVector& other)
	: a0(other.a0), a1(other.a1), a2(other.a2), a3(other.a3)
{}


void FourVector::boost_z(const double v)
{

	fourVectorZBoost(a0, a3, v);
}

double FourVector::FourVectorInerval() const
{

		return interval(a0,a1,a2,a3);
}

FourVector::~FourVector()
{}
