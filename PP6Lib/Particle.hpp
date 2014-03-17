#ifndef PARTICLE_HH
#define PARTICLE_HH 

class Particle{
	private:
		std::string ParticleName_;
		double charge_;
		FourVector FourMomentum_;
	public:
		//Constructors
		Particle();
		Particle(particle& other);



		FourVector getFourMomentum() const;
		double getCharge() const;
		std::string getParticleName();




};


#endif
