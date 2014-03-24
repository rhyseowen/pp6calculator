#include <vector>

#include "ParticleInfo.hpp"
#include "FileReader.hpp"

ParticleInfo::ParticleInfo(std::string& FileName)
{
	FileReader f(FileName);

	std::vector<std::string> particleType;
	std::vector<int> idNumber;
	std::vector<int> charge;
	std::vector<double> mass;

	if (f.isValid())	
	{
		while (f.nextLine())
		{
			particleType.push_back( f.getField<std::string>(1));
			idNumber.push_back( f.getField<int>(2));
			charge.push_back( f.getField<int>(3));
			mass.push_back( f.getField<double>(4));

		}
	}

	for (unsigned int i = 0; i < particleType.size(); ++i)
	{
		PartNameId_.insert(std::make_pair(particleType[i], idNumber[i]));
		PartIdCharge_.insert(std::make_pair(idNumber[i], charge[i]));
		PartIdName_.insert(std::make_pair(idNumber[i],particleType[i]));
		PartIdMassMev_.insert(std::make_pair(idNumber[i], mass[i]));
	}


}

ParticleInfo::ParticleInfo(const ParticleInfo& other)
:PartNameId_(other.PartNameId_), PartIdCharge_(other.PartIdCharge_), PartIdName_(other.PartIdName_), PartIdMassMev_(other.PartIdMassMev_)
{}

int ParticleInfo::getPDGCode(std::string& ParticleName)
{
	auto p = PartNameId_.find(ParticleName);
	if (p != PartNameId_.end())
	{
		return (*p).second;
	}
	return 0;
}

int ParticleInfo::getCharge(int pdgCode)
{
	auto p = PartIdCharge_.find(pdgCode);
	if (p != PartIdCharge_.end())
	{
		return (*p).second;
	}
	return 0;
}

std::string ParticleInfo::getName(int pdgCode)
{
	auto p = PartIdName_.find(pdgCode);
	if (p != PartIdName_.end())
	{
		return (*p).second;
	}
	return "";
}

double ParticleInfo::getMassMeV(int pdgCode)
{
	auto p = PartIdMassMev_.find(pdgCode);
	if (p != PartIdMassMev_.end())	
	{
		return (*p).second;	
	}
	return 0.0;
}

double ParticleInfo::getMassGeV(int pdgCode)
{
	return getMassMeV(pdgCode)/1000.0;
}

ParticleInfo& ParticleInfo::operator=(const ParticleInfo& other)
{
	PartNameId_ = other.PartNameId_;
	PartIdCharge_ = other.PartIdCharge_;
	PartIdName_ = other.PartIdName_;
	PartIdMassMev_ = other.PartIdMassMev_;

	return *this;
}
