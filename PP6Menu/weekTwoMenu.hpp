/**
 * @file weekTwoMenu.hpp
 * @brief Menu of opperations for week2
 */
#ifndef WEEKTWOMENU_HH
#define WEEKTWOMENU_HH 

/**
 * @brief Main week two function
 * @details The main loop of the week 2 menu called by the top menu.
 * @return error code to propergate back to exit
 */
int weekTwoMenu();

/**
 * @brief Print help
 */
void weekTwoPrintHelp();

/**
 * @brief Execute swap opperation
 * @return Error code
 */
int wk2_swap();

/**
 * @brief Execute sort opperation
 * @return Error code
 */
int wk2_sort();

/**
 * @brief Execute vector sort opperation
 * @return Error code
 */
int wk2_vectorSort();

/**
 * @brief Execute generate muon opperation
 * @return Error code
 */
int wk2_generateMuons();

/**
 * @brief Execute read in muon opperation
 * @return Error code
 */
int wk2_readInMuons();

/**
 * @brief Count number of muons in a file
 * @details Counts the number of mu+ and mu- found in the file 
 * 
 * @param filename file to scan
 * @param number_mu_p int to fill with number of mu+
 * @param number_mu_n int to fill with number of mu-
 * @return Error code
 */
int getNumberOfMuons(std::string filename, int& number_mu_p, int& number_mu_n);

/**
 * @brief Get muon information from file
 * @details Gets muon information from file and also calculates energy based on muon mass and momentum for mu+ and mu- and fills them into seperate arrays
 * 
 * @param filename file to read from
 * @param muonMass muon mass to use [GeV]
 * @param mu_p_px mu+ px
 * @param mu_p_py mu+ py
 * @param mu_p_pz mu+ pz
 * @param mu_p_E mu+ E
 * @param mu_p_evt mu+ Event number
 * @param mu_n_px mu- px
 * @param mu_n_py mu- py
 * @param mu_n_pz mu- pz
 * @param mu_n_E mu- E
 * @param mu_n_evt mu- Event number
 * @return Error code
 */
int getMuonInformation(std::string filename, double muonMass, double *mu_p_px, double *mu_p_py, double *mu_p_pz, double *mu_p_E, int *mu_p_evt, double *mu_n_px, double *mu_n_py, double *mu_n_pz, double *mu_n_E, int *mu_n_evt);

#endif
