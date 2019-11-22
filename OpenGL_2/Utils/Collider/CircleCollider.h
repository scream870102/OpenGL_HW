#pragma once
#include "../../Header/Angel.h"
class CircleCollider
{
private:
	float radius;
	vec3 centerPoint;
	float scale;
public:
private:
public:
	CircleCollider(float radius, vec3 centerPoint, float scale = 1.0f);
	~CircleCollider();
	const bool IsCollide(CircleCollider* other)const;
	void SetCenterPoint(vec3 newCenterPoint);
	void SetScale(float newScale);
};
