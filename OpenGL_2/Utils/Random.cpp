#include "Random.h"

float Random::GetRand(float max, float min) {
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	std::uniform_real_distribution<float> dis(min, max);
	float result = dis(gen);
	return result;
}

int Random::GetRand(int max, int min) {
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	if (max == min)return max;
	else if (max < min) {
		int tmp = max;
		max = min;
		min = tmp;
	}
	std::uniform_int_distribution<int> dis(min, max);
	int result = dis(gen);
	return result;
}

bool Random::GetRandBool() {
	std::random_device rd;
	std::default_random_engine gen = std::default_random_engine(rd());
	std::uniform_int_distribution<int> dis(0, 9);
	int rand = dis(gen);
	return rand % 2 == 0;
}

Random::Random() {}

Random::~Random() {}
