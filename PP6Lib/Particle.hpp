#ifndef PARTICLE_HH
#define PARTICLE_HH 

#include <string>
#include <iostream>

#include "FourVector.hpp"

/**
 * @brief Particle Class
 * @details An object to describe a particle and its properties
 */
class Particle{
	private:
		std::string ParticleName_;
		double charge_;
		double mass_;
		FourVector FourMomentum_;
	public:
		//Constructors
		Particle();

		/**
		 * @brief Copy constructor
		 * 
		 * @param other Particle to copy
		 */
		Particle(const Particle& other);

		/**
		 * @brief Valued Constructor
		 * @details Create an initalised particle object
		 * 
		 * @param ParticleName The name of the particle
		 * @param charge The charge on the particle
		 * @param E The energy of the particle
		 * @param px momentum x component 
		 * @param py momentum y component 
		 * @param pz momentum z component 
		 */
		Particle(const std::string& ParticleName, const double& charge, const double& E, const double& px, const double& py, const double& pz);

		~Particle();

		/**
		 * @brief Get the particles name
		 * @return ParticleName
		 */
		std::string getParticleName() const;

		/**
		 * @brief Set the particles name
		 * 
		 * @param ParticleName name to set
		 */
		void setParticleName(const std::string& ParticleName);

		/**
		 * @brief Get the mass of the particle
		 * @return Particle mass
		 */
		double getMass() const;

		/**
		 * @brief Gets the particles four momentum
		 * @return particles four momentum
		 */
		FourVector getFourMomentum() const;

		/**
		 * @brief Sets the particles four momentum
		 * @details Sets the particles four momentum with a check that it is valid
		 * 
		 * @param FourMomentum four momenta to set
		 * 
		 * @return true if momentum set false otherwise
		 */
		bool setFourMomentum(const FourVector& FourMomentum);

		/**
		 * @brief Set Particles charge
		 * @return charge in units of \f$e\f$
		 */
		double getCharge() const;

		/**
		 * @brief Set the charge of the particle
		 * 
		 * @param charge carge in units of \f$e\f$
		 */
		void setCharge(const double& charge);

		/**
		 * @brief Stream opperator for easy output
		 */
		friend std::ostream& operator<<(std::ostream& stream,const Particle& p);

};


#endif
