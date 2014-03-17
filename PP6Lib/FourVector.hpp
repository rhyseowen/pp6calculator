#ifndef FOURVECTOR_HH
#define FOURVECTOR_HH

struct FourVector;

FourVector* createFourVector();

FourVector* createFourVector(double a0, double a1, double a2, double a3);

FourVector* createFourVector(FourVector* initial);

FourVector* boost_z(FourVector* vector,double v);

double FourVectorInerval(FourVector* v);

void destroyFourVector(FourVector *&q);

#endif