#pragma once
#include "../Transform.h"
class Movement
{
protected:
	Transform* target;
	float velocity;
public:
private:
public:
	Movement(Transform* target, float velocity);
	~Movement();
	virtual const vec3 GetNextPos(float delta) = 0;
};
