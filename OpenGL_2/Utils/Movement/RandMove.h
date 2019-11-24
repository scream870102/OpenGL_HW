#pragma once
#include "Movement.h"
#include "../Random.h"
class RandMove:public Movement
{
private:
	vec2 xRange;
	vec2 yRange;
	vec3 destination;
	vec3 direction;
public:
private:
public:
	RandMove(Transform* target, float velocity,vec2 xRange,vec2 yRange);
	~RandMove();
	const vec3 GetNextPos(float delta) override;
	void FindNewDes();
};


