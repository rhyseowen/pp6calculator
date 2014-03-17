#ifndef FOURVECTOR_HH
#define FOURVECTOR_HH


class FourVector{
	public:
		//ctors

		/**
		 * @brief Default Constructor
		 */
		FourVector() {a0 = 0; a1 = 0; a2 = 0; a3 = 0; interval_ =0;}

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

		void setA0(double a0_in);

		void setA1(double a1_in);

		void setA2(double a2_in);

		void setA3(double a3_in);

		double getInterval() const; 

		FourVector& operator+=(const FourVector& rhs);

		FourVector& operator-=(const FourVector& rhs);

		FourVector& operator=(const FourVector& rhs);




	private:
		/**
		 * @brief Calcualte interval	
		 * @details Caluculate the interval (\f$length^2\f$) of the four vector
		 * @return interval
		 */
		void intervalV();

		double a0;
		double a1;
		double a2;
		double a3;
		double interval_;
	

};

FourVector operator+(const FourVector& lhs, const FourVector& rhs);

FourVector operator-(const FourVector& lhs, const FourVector& rhs);





#endif