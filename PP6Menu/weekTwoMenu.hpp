#ifndef WEEKTWOMENU_HH
#define WEEKTWOMENU_HH 

int weekTwoMenu();
void weekTwoPrintHelp();

int wk2_swap();
int wk2_sort();
int wk2_vectorSort();
int wk2_generateMuons();
int wk2_readInMuons();
int getNumberOfMuons(std::string filename, int& number_mu_p, int& number_mu_n);
int getMuonInformation(std::string filename, double muonMass, double *mu_p_px, double *mu_p_py, double *mu_p_pz, double *mu_p_E, int *mu_p_evt, double *mu_n_px, double *mu_n_py, double *mu_n_pz, double *mu_n_E, int *mu_n_evt);

#endif
