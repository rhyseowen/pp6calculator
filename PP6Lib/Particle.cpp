#include <cmath>

#include "Particle.hpp"

Particle::Particle()
:ParticleName_("NONE"), charge_(0), mass_(0), FourMomentum_(0,0,0,0)
{}

Particle::Particle(const Particle& other)
:ParticleName_(other.getParticleName()), charge_(other.getCharge()), mass_(other.getMass()), FourMomentum_(other.getFourMomentum())
{}

Particle::Particle(const std::string& ParticleName, const double& charge, const double& E, const double& px, const double& py, const double& pz)
:ParticleName_(ParticleName), charge_(charge), mass_(0), FourMomentum_(E,px,py,pz), event_(0)
{
	mass_ = sqrt(getFourMomentum().getInterval());
}

Particle::Particle(const int event, const std::string& ParticleName, const double& charge, const double& E, const double& px, const double& py, const double& pz)
:ParticleName_(ParticleName), charge_(charge), mass_(0), FourMomentum_(E,px,py,pz), event_(event)
{
	mass_ = sqrt(getFourMomentum().getInterval());
}

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
	if (FourMomentum.getFourVectorType() == FourVector::TIMELIKE)
	{
		FourMomentum_ = FourMomentum;
		return true;
	}
	return false;

}

double Particle::getMass() const
{
	return mass_;
}

Particle::~Particle()
{}

int Particle::getEvent()
{
	return event_;
}

std::ostream& operator<<(std::ostream& stream,const Particle& p)
{
	stream << "[";
	stream << p.getParticleName() << "," << p.getFourMomentum();
	stream << "]";
	return stream;
}
