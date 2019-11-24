#include "Mathf.h"

Mathf::Mathf() {}

Mathf::~Mathf() {}

float Mathf::Clamp(float origin, float max, float min) {
	float result = origin;
	if (origin > max)result = max;
	else if (origin < min)result = min;
	return result;
}

float Mathf::GetDeg(const vec3& direction){
	return atan2f(direction.y, direction.x) * Rad2Deg;
}
