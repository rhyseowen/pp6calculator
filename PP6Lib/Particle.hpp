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

		Particle(const std::string& ParticleName, const double& charge, const double& E, const double& px, const double& py, const double& pz);

		std::string getParticleName() const;
		void setParticleName(const std::string& ParticleName);



		FourVector getFourMomentum() const;
		bool setFourMomentum(const FourVector& FourMomentum);

		double getCharge() const;
		void setCharge(const double& charge);
		std::string getParticleName();




};


#endif
