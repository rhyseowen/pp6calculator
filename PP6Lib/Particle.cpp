#include "Particle.hpp"

Particle::Particle()
:ParticleName_("NONE"), charge_(0), FourMomentum_(0,0,0,0)
{}

Particle::Particle(const Particle& other)
:ParticleName_(other.getParticleName()), charge_(other.getCharge()), FourMomentum_(other.getFourMomentum())
{}

Particle::Particle(const std::string& ParticleName, const double& charge, const double& E, const double& px, const double& py, const double& pz)
:ParticleName_(ParticleName), charge_(charge), FourMomentum_(E,px,py,pz)
{}

double Particle::getCharge() const
{
	return charge_;
}

void Particle::setCharge(const double& charge)
{
	charge_ = charge;
}

std::string Particle::getParticleName() const
{
	return ParticleName_;
}

void Particle::setParticleName(const std::string& ParticleName)
{
	ParticleName_ = ParticleName;
}


FourVector Particle::getFourMomentum() const
{
	return FourMomentum_;
}

bool Particle::setFourMomentum(const FourVector& FourMomentum)
{
	FourMomentum_ = FourMomentum;
	//add check for sensible 4 Momenta reject and return false if not physical
	return true;

}

