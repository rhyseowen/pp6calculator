#ifndef PARTICLE_HH
#define PARTICLE_HH 

#include <string>
#include "FourVector.hpp"

class Particle{
	private:
		std::string ParticleName_;
		double charge_;
		FourVector FourMomentum_;
	public:
		//Constructors
		Particle();
		Particle(const Particle& other);

		std::string getParticleName() const;
		void setParticleName(const std::string& ParticleName);



		FourVector getFourMomentum() const;
		void setFourMomentum(const FourVector& FourMomentum);

		double getCharge() const;
		void setCharge(const double& charge);
		std::string getParticleName();




};


#endif
