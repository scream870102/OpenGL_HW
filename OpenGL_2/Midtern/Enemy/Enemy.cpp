#include "Enemy.h"


Enemy::Enemy(int type, int damage, int health) :Character(type, damage, health) {
	poolParent = NULL;
}

Enemy::~Enemy() {}

Enemy::Enemy(const Enemy& e) : Character(e) {}

const Enemy& Enemy::operator=(const Enemy& e) {
	if (&e != this) {}
	return *this;
}

void Enemy::Init(vec3 initPos, ObjectPool<Enemy>* poolParent) {
	this->transform->position = initPos;
	if(poolParent!=NULL)this->poolParent = poolParent;
}
