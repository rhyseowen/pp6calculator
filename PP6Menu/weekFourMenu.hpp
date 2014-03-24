#ifndef WEEKFOURMENU_HH
#define WEEKFOURMENU_HH 

#include "Particle.hpp"


int weekFourMenu();

/**
 * @brief Print help
 */
void weekFourPrintHelp();

int wk4_pdg();

int wk4_algo();

int wk4_readInMuons();

bool sortFunction(const std::pair<double,std::pair<Particle*,Particle*>>& lhs, const std::pair<double,std::pair<Particle*,Particle*>>& rhs);

#endif
