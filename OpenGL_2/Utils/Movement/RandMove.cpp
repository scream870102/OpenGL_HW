#include "RandMove.h"

const vec3 RandMove::GetNextPos(float delta) {
	// if reach the destination find the new destination
	if (Angel::length(target->position - destination) <= 5.0f) {
		FindNewDes();
	}
	vec3 nextPos = target->position + direction * velocity * delta;
	if (nextPos.x > xRange.y || nextPos.x < xRange.x)FindNewDes();
	else if (nextPos.y > yRange.y || nextPos.y < yRange.x)FindNewDes();
	return nextPos;
}

void RandMove::FindNewDes() {
	destination = vec3(Random::GetRand(xRange.y, xRange.x), Random::GetRand(yRange.y, yRange.x), 0.0f);
	direction = Angel::normalize(destination - target->position);
}

RandMove::RandMove(Transform* target, float velocity, vec2 xRange, vec2 yRange) :Movement(target, velocity) {
	this->xRange = xRange;
	this->yRange = yRange;
	destination = vec3(Random::GetRand(xRange.y, xRange.x), Random::GetRand(yRange.y, yRange.x), 0.0f);
	direction = Angel::normalize(destination - target->position);
}

RandMove::~RandMove() {}