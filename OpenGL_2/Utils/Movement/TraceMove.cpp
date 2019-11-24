#include "TraceMove.h"

TraceMove::TraceMove(Transform* target, float velocity, Transform* tracingTarget) :Movement(target, velocity) {
	this->tracingTarget = tracingTarget;
	this->degree = 0.0f;
}

TraceMove::~TraceMove() {}

const vec3 TraceMove::GetNextPos(float delta) {
	//set position due to direction
	vec3 offset = (this->tracingTarget->GetGlobalPosition()) - (this->target->GetGlobalPosition());
	vec3 direction = Angel::normalize(offset);
	vec3 result = target->GetGlobalPosition() + direction * velocity * delta;
	//Rotation the bullet
	degree = Mathf::GetDeg(direction);
	return result;
}

const float TraceMove::GetDegree() {
	return degree;
}
