#pragma once
#include "Movement.h"
class PingPongMove:public Movement
{
private:
	float maxX;
	float minX;
	float y;
	mutable bool bIncrease;
public:
private:
public:
	PingPongMove(Transform* target, float velocity, float maxX, float minX, bool IsIncrease = true);
	~PingPongMove();
	const vec3 GetNextPos(float delta) override;
	void SetVertical(float newY);
	bool IsFacingRight();
};
