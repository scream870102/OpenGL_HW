#pragma once
#include "../Transform.h"
class PingPongMove
{
private:
	float velocity;
	float maxX;
	float minX;
	float y;
	mutable bool bIncrease;
	Transform* target;
public:
private:
public:
	PingPongMove(Transform* target, float velocity, float maxX, float minX, bool IsIncrease = true);
	~PingPongMove();
	const vec3 GetNextPos(float delta)const;
	void SetVertical(float newY);
	bool IsFacingRight();
};
