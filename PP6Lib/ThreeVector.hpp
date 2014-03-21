#ifndef THREEVECTOR_HH
#define THREEVECTOR_HH 

#include <iostream>

/**
 * @brief A Three Vector Class
 * @details An object to provide a three vector and assosiated mathmatical operations
 */
class ThreeVector{
	private:
		double x_;
		double y_;
		double z_;

		double lengthSquared_;

		void calculateLengthSquared();

	public:
		/**
		 * @brief Blank constructor
		 * @details not much use
		 */
		ThreeVector();

		/**
		 * @brief Valued Constructor
		 * @details Create a three vector specifiying x,y,z values
		 * 
		 * @param x x
		 * @param y y
		 * @param z z
		 */
		ThreeVector(double x, double y, double z);

		/**
		 * @brief Copy Constructor
		 * @details Creates an ne vector as a copy of an other one
		 * 
		 * @param other ThreeVector to copy
		 */
		ThreeVector(const ThreeVector& other);


		/**
		 * @brief Calcuate dot product
		 * @details Calculates the dot product between this three vector and another a.dotProduct(b) is equivalent to \f$ \vec{a} \cdot \vec{b} \f$
		 * 
		 * @param rhs vector to be producted with
		 * @return dot vector \f$\vec{b}\f$
		 */
		double dotProduct(const ThreeVector& rhs) const;

		/**
		 * @brief Calculate cross product
		 * @details Calculates the cross or vector product of the two vector a.crossProduct(b) is equivelent \f$ \vec{a} = \vec{a} \times \vec{b} \f$
		 * 
		 * @param rhs vector \f$\vec{b}\f$
		 */
		void crossProduct(const ThreeVector& rhs);

		/**
		 * @brief Calculate cross product
		 * @details Caclulates the cross product of two vectors and returns the vector result c = ThreeVector::crossProduct(a,b) is equivalent to \f$ \vec{c} = \vec{a} \times \vec{b} \f$
		 * 
		 * @param lhs \f$ \vec{a} \f$
		 * @param rhs \f$ \vec{b} \f$
		 * 
		 * @return \f$ \vec{c} \f$
		 */
		static ThreeVector crossProduct(const ThreeVector& lhs, const ThreeVector& rhs);

		/**
		 * @brief Get vector x component
		 * @return x
		 */
		double getX() const;

		/**
		 * @brief Get vector y component
		 * @return y
		 */
		double getY() const;

		/**
		 * @brief Get vector z component
		 * @return z
		 */
		double getZ() const;

		/**
		 * @brief Get Length Squared
		 * @details gives the leng squred of a vector \f$ l^2 = \vec{a} \cdot \vec{a} \f$
		 * @return \f$ l^2 \f$
		 */
		double getLengthSquared() const;

		/**
		 * @brief Set x value
		 * 
		 * @param x x
		 */
		void setX(double x);

		/**
		 * @brief Set y value
		 * 
		 * @param y y
		 */
		void setY(double y);

		/**
		 * @brief Set z value
		 * 
		 * @param z z
		 */
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
