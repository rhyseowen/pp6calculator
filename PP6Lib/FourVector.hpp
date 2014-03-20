#ifndef FOURVECTOR_HH
#define FOURVECTOR_HH

#include "ThreeVector.hpp"

class FourVector{
	private:
		/**
		 * @brief Calcualte interval	
		 * @details Caluculate the interval (\f$length^2\f$) of the four vector
		 * @return interval
		 */
		void calculateInterval();
		double lorentzGamma(const double& v) const;

		double a0_;

		ThreeVector spaceLike_;

		double interval_;
	
	public:
		//ctors

		/**
		 * @brief Default Constructor
		 */
		FourVector() {a0_ = 0; interval_ =0;}

		/**
		 * @brief Initalised Constructor
		 * 
		 * @param a0 a0
		 * @param a1 a1
		 * @param a2 a2
		 * @param a3 a3
		 */
		FourVector(double a0, double a1, double a2, double a3);

		/**
		 * @brief Copy Constructor
		 * 
		 * @param other FourVector to Copy
		 */
		FourVector(const FourVector& other);

		/**
		 * @brief Boost FourVector in z direction
		 * @details Boosts the four vector object into a frame at \f$ v \f$ velocity in the z axis, using natural units 
		 * 
		 * @param v velocity in natural units
		 */
		void boost_z(const double& v);


		//dtor
		/**
		 * @brief Default destructor
		 */
		~FourVector();

		//getters and setters

		/**
		 * @brief get a0
		 */
		double getA0() const;

		/**
		 * @brief get a1
		 */
		double getA1() const;

		/**
		 * @brief get a2
		 */
		double getA2() const;

		/**
		 * @brief get a3
		 */
		double getA3() const;

		/**
		 * @brief set a0 component
		 */
		void setA0(double a0_in);

		/**
		 * @brief set a1 component
		 */
		void setA1(double a1_in);

		/**
		 * @brief set a2 component
		 */
		void setA2(double a2_in);

		/**
		 * @brief set a3 component
		 */
		void setA3(double a3_in);

		/**
		 * @brief Get the four vector interval
		 * @details Returns the interval of the four vector ie \f$A_{\mu}A^{\mu} = \text{interval}\f$
		 * @return interval
		 */
		double getInterval() const; 


		/**
		 * @brief Add another FourVector component wise
		 * 
		 * @param rhs Other FourVector
		 */
		FourVector& operator+=(const FourVector& rhs);

		FourVector& operator-=(const FourVector& rhs);

		FourVector& operator=(const FourVector& rhs);

		friend FourVector operator+(const FourVector& lhs, const FourVector& rhs);

		friend FourVector operator-(const FourVector& lhs, const FourVector& rhs);

};

#endif
