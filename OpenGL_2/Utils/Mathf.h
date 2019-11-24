#pragma once
#include <math.h>
#include "../Header/Angel.h"
class Mathf
{
#define Rad2Deg 57.29578f
public:
	Mathf();
	~Mathf();
	static float Clamp(float origin, float max, float min = 0.0f);
	static float GetDeg(const vec3& direction);

};