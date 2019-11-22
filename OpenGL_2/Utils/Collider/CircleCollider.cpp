#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius, vec3 centerPoint, float scale) {
	this->radius = radius;
	this->centerPoint = centerPoint;
	this->scale = scale;
}

CircleCollider::~CircleCollider() {}

const bool CircleCollider::IsCollide(CircleCollider* other)const {
	float distance = Angel::length((other->centerPoint - this->centerPoint));
	return distance <= (this->radius * this->scale + other->radius * other->scale);
}

void CircleCollider::SetCenterPoint(vec3 newCenterPoint) {
	centerPoint = newCenterPoint;
}

void CircleCollider::SetScale(float newScale) {
	this->scale = newScale;
}
