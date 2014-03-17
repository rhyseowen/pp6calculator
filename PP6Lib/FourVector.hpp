#ifndef FOURVECTOR_HH
#define FOURVECTOR_HH


class FourVector{
	public:
		//ctors
		FourVector() {a0 = 0; a1 = 0; a2 = 0; a3 = 0;}
		FourVector(double a0, double a1, double a2, double a3);
		FourVector(const FourVector& other);


		void boost_z(const double v);
		double FourVectorInerval() const;

		//dtor
		~FourVector();

		double a0;
		double a1;
		double a2;
		double a3;

	

};







#endif