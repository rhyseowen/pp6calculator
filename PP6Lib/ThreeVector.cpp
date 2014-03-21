#include <iostream>

#include "ThreeVector.hpp"
#include "PP6Math.hpp"

ThreeVector::ThreeVector()
: x_(0), y_(0), z_(0), lengthSquared_(0)
{}

ThreeVector::ThreeVector(double x, double y, double z)
: x_(x), y_(y), z_(z), lengthSquared_(0)
{
	calculateLengthSquared();
}

ThreeVector::ThreeVector(const ThreeVector& other)
: x_(other.x_), y_(other.y_), z_(other.z_), lengthSquared_(other.lengthSquared_)
{}

ThreeVector::~ThreeVector()
{}

void ThreeVector::calculateLengthSquared()
{
	lengthSquared_ = x_*x_ + y_*y_ + z_*z_;
}

double ThreeVector::dotProduct(const ThreeVector& rhs) const
{
	return x_ * rhs.x_ + y_ * rhs.y_ + z_ * rhs.z_; 
}

void ThreeVector::crossProduct(const ThreeVector& rhs)
{
	double xPrime = y_*rhs.z_-z_*rhs.y_;
	double yPrime = z_*rhs.x_-x_*rhs.z_;
	double zPrime = x_*rhs.y_-y_*rhs.x_;

	x_ = xPrime;
	y_ = yPrime;
	z_ = zPrime;
}

ThreeVector ThreeVector::crossProduct(const ThreeVector& lhs, const ThreeVector& rhs)
{
	ThreeVector temp(lhs);
	temp.crossProduct(rhs);

	return temp;
}

double ThreeVector::getX() const
{
	return x_;
}

double ThreeVector::getY() const
{
	return y_;
}

double ThreeVector::getZ() const
{
	return z_;
}

double ThreeVector::getLengthSquared() const 
{
	return lengthSquared_;
} 

void ThreeVector::setX(double x)
{
	x_ = x;
	calculateLengthSquared();
}

void ThreeVector::setY(double y)
{
	y_ = y;
	calculateLengthSquared();
}

void ThreeVector::setZ(double z)
{
	z_ = z;
	calculateLengthSquared();
}

ThreeVector& ThreeVector::operator+=(const ThreeVector& rhs)
{
	x_ += rhs.x_;
	y_ += rhs.y_;
	z_ += rhs.z_;

	calculateLengthSquared();

	return *this ;
}

ThreeVector& ThreeVector::operator-=(const ThreeVector& rhs)
{
	x_ -= rhs.x_;
	y_ -= rhs.y_;
	z_ -= rhs.z_;

	calculateLengthSquared();

	return *this ;
}

ThreeVector& ThreeVector::operator=(const ThreeVector& rhs)
{
	x_ = rhs.x_;
	y_ = rhs.y_;
	z_ = rhs.z_;

	calculateLengthSquared();

	return *this ;
}

ThreeVector& ThreeVector::operator*=(const int& rhs)
{
	x_ *= rhs;
	y_ *= rhs;
	z_ *= rhs;

	calculateLengthSquared();

	return *this ;
}

ThreeVector& ThreeVector::operator*=(const double& rhs)
{
	x_ *= rhs;
	y_ *= rhs;
	z_ *= rhs;

	calculateLengthSquared();

	return *this ;
}

ThreeVector& ThreeVector::operator*=(const float& rhs)
{
	x_ *= rhs;
	y_ *= rhs;
	z_ *= rhs;

	calculateLengthSquared();

	return *this ;
}

ThreeVector& ThreeVector::operator/=(const int& rhs)
{
	x_ /= rhs;
	y_ /= rhs;
	z_ /= rhs;

	calculateLengthSquared();

	return *this ;
}

ThreeVector& ThreeVector::operator/=(const double& rhs)
{
	x_ /= rhs;
	y_ /= rhs;
	z_ /= rhs;

	calculateLengthSquared();

	return *this ;
}

ThreeVector& ThreeVector::operator/=(const float& rhs)
{
	x_ /= rhs;
	y_ /= rhs;
	z_ /= rhs;

	calculateLengthSquared();

	return *this ;
}

bool ThreeVector::operator==(const ThreeVector& rhs)
{
	bool equal = true;

	if (!doubleCompare(x_, rhs.x_))
	{
		equal = false;
	}
	if (!doubleCompare(y_, rhs.y_))
	{
		equal = false;
	}
	if (!doubleCompare(z_, rhs.z_))
	{
		equal = false;
	}

	return equal;

}

bool ThreeVector::operator!=(const ThreeVector& rhs)
{
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& stream,const ThreeVector& v)
{
	stream << "[";
	stream << v.x_ << "," << v.y_ << "," << v.z_;
	stream << "]";

	return stream;

}

ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs)
{
	ThreeVector temp(lhs);
	temp += rhs;
	return temp;
}

ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs)
{
	ThreeVector temp(lhs);
	temp -= rhs;
	return temp;
}

ThreeVector operator*(const ThreeVector& lhs, const int& rhs)
{
	ThreeVector temp(lhs);
	temp *= rhs;
	return temp;
}

ThreeVector operator*(const int& lhs, const ThreeVector& rhs)
{
	return rhs*lhs;
}

ThreeVector operator*(const ThreeVector& lhs, const double& rhs)
{
	ThreeVector temp(lhs);
	temp *= rhs;
	return temp;
}

ThreeVector operator*(const double& lhs, const ThreeVector& rhs)
{
	return rhs*lhs;
}

ThreeVector operator*(const ThreeVector& lhs, const float& rhs)
{
	ThreeVector temp(lhs);
	temp *= rhs;
	return temp;
}

ThreeVector operator*(const float& lhs, const ThreeVector& rhs)
{
	return rhs*lhs;
}

ThreeVector operator/(const ThreeVector& lhs, const int& rhs)
{
	ThreeVector temp(lhs);
	temp /= rhs;
	return temp;
}

ThreeVector operator/(const ThreeVector& lhs, const double& rhs)
{
	ThreeVector temp(lhs);
	temp /= rhs;
	return temp;
}

ThreeVector operator/(const ThreeVector& lhs, const float& rhs)
{
	ThreeVector temp(lhs);
	temp /= rhs;
	return temp;
}

