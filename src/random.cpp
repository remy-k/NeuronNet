#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int seed) /*: seed(s)*/{
	   
	if (seed == 0) {
		std::random_device rd;
		seed = rd();
    }
    rng = std::mt19937(seed);
}


void RandomNumbers::uniform_double(std::vector<double>& list, double lower, 
							double upper){
	
	std::uniform_real_distribution<> DistUni(lower, upper);
	for(auto& number : list){
		number=DistUni(rng);
	}
}

double RandomNumbers::uniform_double(double lower, double upper){
		
	std::uniform_real_distribution<> DistUni(lower, upper);
	return DistUni(rng);
}

void RandomNumbers::normal(std::vector<double>& list, double mean, double sd){
	
	std::normal_distribution<> DistNorm (mean, sd);
	for(auto& number : list)
		number = DistNorm(rng);
}

double RandomNumbers::normal(double mean, double sd){
	
	std::normal_distribution<> DistNorm (mean, sd);
	return DistNorm(rng);
}

void RandomNumbers::poisson(std::vector<int>& list, double mean){
	
	std::poisson_distribution<> DistPois (mean);
	for(auto& number : list)
		number = DistPois(rng);
}

int RandomNumbers::poisson(double mean){
	
	std::poisson_distribution<> DistPois (mean);
	return DistPois(rng);
}
