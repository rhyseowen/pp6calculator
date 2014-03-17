#ifndef FOURVECTOR_HH
#define FOURVECTOR_HH


class FourVector{
	public:
		// static FourVector* createFourVector();
		// static FourVector* createFourVector(double a0, double a1, double a2, double a3);
		// static FourVector* createFourVector(FourVector* initial);
		void boost_z(const double v);
		double FourVectorInerval() const;
		// void destroyFourVector(FourVector *&q);

		double a0;
		double a1;
		double a2;
		double a3;

	

};







#endif