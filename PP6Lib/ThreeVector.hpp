#ifndef THREEVECTOR_HH
#define THREEVECTOR_HH 

#include <iostream>

class ThreeVector{
	private:
		double x_;
		double y_;
		double z_;

		double lengthSquared_;

		void calculateLengthSquared();

	public:
		ThreeVector();
		ThreeVector(double x, double y, double z);
		ThreeVector(const ThreeVector& other);

		double dotProduct(const ThreeVector& rhs) const;
		void crossProduct(const ThreeVector& rhs);

		double getX() const;
		double getY() const;
		double getZ() const;

		double getLengthSquared() const;

		void setX(double x);
		void setY(double y);
		void setZ(double z);

		ThreeVector& operator+=(const ThreeVector& rhs);
		ThreeVector& operator-=(const ThreeVector& rhs);
		ThreeVector& operator=(const ThreeVector& rhs);

		ThreeVector& operator*=(const int& rhs);
		ThreeVector& operator*=(const double& rhs);
		ThreeVector& operator*=(const float& rhs);

		ThreeVector& operator/=(const int& rhs);
		ThreeVector& operator/=(const double& rhs);
		ThreeVector& operator/=(const float& rhs);

		bool operator==(const ThreeVector& rhs);
		bool operator!=(const ThreeVector& rhs);

		friend std::ostream& operator<<(std::ostream& stream,const ThreeVector& v);

		friend ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs);
		friend ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs);

		friend ThreeVector operator*(const ThreeVector& lhs, const int& rhs);
		friend ThreeVector operator*(const int& lhs, const ThreeVector& rhs);

		friend ThreeVector operator*(const ThreeVector& lhs, const double& rhs);
		friend ThreeVector operator*(const double& lhs, const ThreeVector& rhs);

		friend ThreeVector operator*(const ThreeVector& lhs, const float& rhs);
		friend ThreeVector operator*(const float& lhs, const ThreeVector& rhs);

		friend ThreeVector operator/(const ThreeVector& lhs, const int& rhs);

		friend ThreeVector operator/(const ThreeVector& lhs, const double& rhs);

		friend ThreeVector operator/(const ThreeVector& lhs, const float& rhs);

};

#endif
