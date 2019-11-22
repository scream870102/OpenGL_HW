#pragma once
#include <random>
class Random
{
public:
	Random();
	~Random();
	static float GetRand(float max, float min = 0.0f);
	static int GetRand(int max, int min = 0);
	static bool GetRandBool();
};

