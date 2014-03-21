#include <cmath>

#include "FourVector.hpp"
#include "PP6Math.hpp"


FourVector::FourVector(double a0_in, double a1_in, double a2_in, double a3_in)
: a0_(a0_in), spaceLike_(a1_in, a2_in, a3_in), interval_(0)
{
	calculateInterval();
}

FourVector::FourVector(const FourVector& other)
: a0_(other.getA0()), spaceLike_(other.spaceLike_), interval_(other.getInterval())
{}


void FourVector::boost_z(const double& v)
{

	double a0Prime = lorentzGamma(v)*(getA0() - v*getA3());
	//a1 is unchanged
	//a2 is unchanged
	double a3Prime = lorentzGamma(v)*(getA3() - v*getA0());

	setA0(a0Prime);
	setA3(a3Prime);
}

void FourVector::calculateInterval()
{

	interval_ = interval(a0_,spaceLike_.getX(),spaceLike_.getY(),spaceLike_.getZ());
}

FourVector::~FourVector()
{}

double FourVector::getA0() const
{
	return a0_;
}

double FourVector::getA1() const
{
	return spaceLike_.getX();
}

double FourVector::getA2() const
{
	return spaceLike_.getY();
}

double FourVector::getA3() const
{
	return spaceLike_.getZ();
}

void FourVector::setA0(double a0_in)
{
	a0_ = a0_in;
}

void FourVector::setA1(double a1_in)
{
	spaceLike_.setX(a1_in);
}

void FourVector::setA2(double a2_in)
{
	spaceLike_.setY(a2_in);
}

void FourVector::setA3(double a3_in)
{
	spaceLike_.setZ(a3_in);
}

double FourVector::getInterval() const
{
	return interval_;
}

ThreeVector FourVector::getThreeVector() const
{
	return spaceLike_;
}

void FourVector::setThreeVector( const ThreeVector& newVector)
{
	spaceLike_ = newVector;
	calculateInterval();
}

FourVector::FourVectorType FourVector::getFourVectorType() const
{
	double sqrtInterval = sqrt(fabs(interval_));

	if (sqrtInterval < 0)
	{
		return SPACELIKE;
	}else if (sqrtInterval > 0)
	{
		return TIMELIKE;
	}
	return NULLVECTOR;
}

FourVector& FourVector::operator+=(const FourVector& rhs)
{

	setA0(getA0() + rhs.getA0());
	setA0(getA1() + rhs.getA1());
	setA0(getA2() + rhs.getA2());
	setA0(getA3() + rhs.getA3());

	calculateInterval();

	return *this;
}

FourVector& FourVector::operator-=(const FourVector& rhs)
{
	setA0(getA0() - rhs.getA0());
	setA0(getA1() - rhs.getA1());
	setA0(getA2() - rhs.getA2());
	setA0(getA3() - rhs.getA3());

	calculateInterval();

	return *this;
}

FourVector& FourVector::operator=(const FourVector& rhs)
{
	if (&rhs != this)
	{
		setA0(rhs.getA0());
		setA1(rhs.getA1());
		setA2(rhs.getA2());
		setA3(rhs.getA3());

		calculateInterval();
	}
	return *this;
}

FourVector operator+(const FourVector& lhs, const FourVector& rhs)
{
	FourVector temp(lhs);
	temp += rhs;
	return temp;
}


FourVector operator-(const FourVector& lhs, const FourVector& rhs)
{
	FourVector temp(lhs);
	temp -= rhs;
	return temp;
}

double FourVector::lorentzGamma(const double& v)const
{
	return 1.0/(sqrt(1-(v/1)*(v/1)));
}
