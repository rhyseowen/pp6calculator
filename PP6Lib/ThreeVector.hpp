#ifndef THREEVECTOR_HH
#define THREEVECTOR_HH 

class ThreeVector{
	private:
		double x_;
		double y_;
		double z_;

		double lengthSquared_;

	public:
		ThreeVector();
		ThreeVector(double x, double y, double z);
		ThreeVector(const ThreeVector& other);

		void dotProduct(const ThreeVector& rhs);
		void crossProduct(const ThreeVector& rhs);

		double getX() const;
		double getY() const;
		double getZ() const;

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

		std::ostream& operator<<(std::ostream& stream,const ThreeVector& v);

		bool operator==(const ThreeVector& rhs);
		bool operator!=(const ThreeVector& rhs);

		friend ThreeVector operator+(const ThreeVector& lhs, const ThreeVector& rhs);
		friend ThreeVector operator-(const ThreeVector& lhs, const ThreeVector& rhs);

		friend ThreeVector operator*(const ThreeVector& lhs, const int& rhs);
		friend ThreeVector operator*(const int& lhs, const ThreeVector& rhs);

		friend ThreeVector operator*(const ThreeVector& lhs, const double& rhs);
		friend ThreeVector operator*(const double& lhs, const ThreeVector& rhs);

		friend ThreeVector operator*(const ThreeVector& lhs, const float& rhs);
		friend ThreeVector operator*(const float& lhs, const ThreeVector& rhs);

		friend ThreeVector operator/(const ThreeVector& lhs, const int& rhs);
		friend ThreeVector operator/(const int& lhs, const ThreeVector& rhs);

		friend ThreeVector operator/(const ThreeVector& lhs, const double& rhs);
		friend ThreeVector operator/(const double& lhs, const ThreeVector& rhs);

		friend ThreeVector operator/(const ThreeVector& lhs, const float& rhs);
		friend ThreeVector operator/(const float& lhs, const ThreeVector& rhs);

};

#endif
