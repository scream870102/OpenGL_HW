#include "Movement.h"

Movement::Movement(Transform* target, float velocity){
	this->target = target;
	this->velocity = velocity;
}

Movement::~Movement(){}


