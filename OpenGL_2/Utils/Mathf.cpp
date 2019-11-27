#include "Mathf.h"

float Mathf::Clamp(float origin, float max, float min) {
	float result = origin;
	if (origin > max)result = max;
	else if (origin < min)result = min;
	return result;
}

float Mathf::GetDeg(const vec3& direction) {
	return atan2f(direction.y, direction.x) * Rad2Deg;
}

vec3 Mathf::ConvertToVec3FromDeg(const float degree, const float offset) {
	vec3 result;
	float radian = (degree + offset) * Deg2Rad;
	result.x = cosf(radian);
	result.y = sinf(radian);
	return result;
}

Mathf::Mathf() {}

Mathf::~Mathf() {}