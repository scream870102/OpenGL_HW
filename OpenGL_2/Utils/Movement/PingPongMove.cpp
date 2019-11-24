#include "PingPongMove.h"

PingPongMove::PingPongMove(Transform* target, float velocity, float maxX, float minX, bool IsIncrease) :Movement(target,velocity){
	this->maxX = maxX;
	this->minX = minX;
	this->y = target->position.y;
	this->bIncrease = IsIncrease;
}

PingPongMove::~PingPongMove() {}

const vec3 PingPongMove::GetNextPos(float delta)  {
	vec3 prevPos = this->target->position;
	vec3 newPos = vec3();
	if (bIncrease)
		newPos.x = prevPos.x + velocity * delta;
	else
		newPos.x = prevPos.x - velocity * delta;
	newPos.y = this->y;
	if (newPos.x >= maxX )
		this->bIncrease = false;
	else if (newPos.x <= minX)
		this->bIncrease = true;
	return newPos;
}

void PingPongMove::SetVertical(float newY) {
	this->y = newY;
}

bool PingPongMove::IsFacingRight(){
	return bIncrease;
}
