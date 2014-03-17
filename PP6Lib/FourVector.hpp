#ifndef FOURVECTOR_HH
#define FOURVECTOR_HH


class FourVector{
	public:
		//ctors

		/**
		 * @brief Default Constructor
		 */
		FourVector() {a0 = 0; a1 = 0; a2 = 0; a3 = 0;}

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
		void boost_z(const double v);

		/**
		 * @brief Calcualte interval	
		 * @details Caluculate the interval (\f$length^2\f$) of the four vector
		 * @return interval
		 */
		double interval() const;

		//dtor
		/**
		 * @brief Default destructor
		 */
		~FourVector();

		//getters and setters

		double getA0() const;

		double getA1() const;

		double getA2() const;

		double getA3() const;

		double setA0(double a0_in);

		double setA1(double a1_in);

		double setA2(double a2_in);

		double setA3(double a3_in);

	private:
		double a0;
		double a1;
		double a2;
		double a3;

	

};







#endif