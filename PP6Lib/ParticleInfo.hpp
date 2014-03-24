#ifndef PARTICLEINFO_HH
#define PARTICLEINFO_HH 

#include <string>
#include <map>



class ParticleInfo
{
public:
	ParticleInfo(const std::string& FileName);
	ParticleInfo(const ParticleInfo& other);
	~ParticleInfo();

	int getPDGCode(std::string& ParticleName);

	int getCharge(int pdgCode);
	std::string getName(int pdgCode);
	double getMassMeV(int pdgCode);
	double getMassGeV(int pdgCode);

	ParticleInfo& operator=(const ParticleInfo& other);
private:
	std::map<std::string, int>PartNameId_;
	std::map<int, int> PartIdCharge_;
	std::map<int, std::string> PartIdName_;
	std::map<int, double> PartIdMassMev_;
};

#endif
