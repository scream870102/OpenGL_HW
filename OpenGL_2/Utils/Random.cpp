#include "Random.h"
Random::Random(){}

Random::~Random(){}

float Random::GetRand(float max, float min){
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	std::uniform_real_distribution<float> dis(min, max);
	float result = dis(gen);
	return result;
}

int Random::GetRand(int max, int min){
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	std::uniform_int_distribution<int> dis(min, max);
	int result = dis(gen);
	return result;
}

bool Random::GetRandBool(){
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	std::uniform_int_distribution<int> dis(0, 9);
	int rand = dis(gen);
	return rand%2==0;
}

