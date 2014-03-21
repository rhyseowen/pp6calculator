#include "Particle.hpp"

Particle::Particle()
:ParticleName_("NONE"), charge_(0), FourMomentum_(0,0,0,0)
{}

Particle::Particle(const Particle& other)
:ParticleName_(other.getParticleName()), charge_(other.getCharge()), FourMomentum_(other.getFourMomentum())
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

void Particle::setFourMomentum(const FourVector& FourMomentum)
{
	FourMomentum_ = FourMomentum;
}

