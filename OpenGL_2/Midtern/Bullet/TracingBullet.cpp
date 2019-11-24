#include "TracingBullet.h"

TracingBullet::TracingBullet(mat4& matModelView, mat4& matProjection, GLuint shaderHandle) :Bullet(matModelView, matProjection, shaderHandle) {
	target = NULL;
	tracingTimer = new CountDownTimer();
}

TracingBullet::~TracingBullet() {}

TracingBullet::TracingBullet(const TracingBullet& b) :Bullet(b) {
	target = b.target;
}

const TracingBullet& TracingBullet::operator=(const TracingBullet& b) {
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//CHECK OPERATOR
	if (&b != this) {
		*this = b;
		this->target = b.target;
	}
	return *this;
}

void TracingBullet::Fire(int type, vec3 position, vec3 direction, float speed, int damage, Transform* target,int tracingTime) {
	this->tracingTimer->Reset(tracingTime);
	this->target = target;
	this->transform->rotation = vec3(0.0f);
	Bullet::Fire(type, position, direction, speed, damage);
}

void TracingBullet::Update(float delta) {
	//set position due to direction
	vec3 newDirection = Angel::normalize(this->target->GetGlobalPosition() - this->transform->GetGlobalPosition());
	this->transform->position += newDirection * speed * delta;
	//Rotation the bullet
	float rot = Mathf::GetDeg(newDirection);
	this->transform->rotation.z = rot;
	//Update Collider
	this->collider->SetCenterPoint(this->transform->position);
	this->collider->SetScale(this->transform->scale.x);
	//CALL RECYCLE METHOD
	if (tracingTimer->IsFinished())poolParent->Recycle(this);
	if (transform->position.y >= HEIGHT || transform->position.y <= 0.0f)
		poolParent->Recycle(this);
}
