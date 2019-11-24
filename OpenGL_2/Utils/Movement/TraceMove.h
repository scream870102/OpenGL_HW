#pragma once
#include "Movement.h"
#include "../Mathf.h"
class TraceMove :public Movement
{
private:
	Transform* tracingTarget;
	float degree;
public:
private:
public:
	TraceMove(Transform* target, float velocity, Transform* tracingTarget);
	~TraceMove();
	const vec3 GetNextPos(float delta)override;
	const float GetDegree();
};
