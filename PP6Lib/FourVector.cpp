#include "FourVector.hpp"
#include "PP6Math.hpp"


FourVector::FourVector(double a0_in, double a1_in, double a2_in, double a3_in)
: a0(a0_in), a1(a1_in), a2(a2_in), a3(a3_in), interval_(0)
{
	intervalV();
}

FourVector::FourVector(const FourVector& other)
: a0(other.getA0()), a1(other.getA1()), a2(other.getA2()), a3(other.getA3()), interval_(other.getInterval())
{}


void FourVector::boost_z(const double v)
{

	fourVectorZBoost(a0, a3, v);
}

void FourVector::intervalV()
{

	interval_ = interval(a0,a1,a2,a3);
}

FourVector::~FourVector()
{}

double FourVector::getA0() const
{
	return a0;
}

double FourVector::getA1() const
{
	return a1;
}

double FourVector::getA2() const
{
	return a2;
}

double FourVector::getA3() const
{
	return a3;
}

void FourVector::setA0(double a0_in)
{
	a0 = a0_in;
}

void FourVector::setA1(double a1_in)
{
	a1 = a1_in;
}

void FourVector::setA2(double a2_in)
{
	a2 = a2_in;
}

void FourVector::setA3(double a3_in)
{
	a3 = a3_in;
}

double FourVector::getInterval() const
{
	return interval_;
}
