#include "Enemy.h"

void Enemy::Init(vec3 initPos, ObjectPool<Enemy>* poolParent) {
	this->transform->position = initPos;
	this->transform->rotation = vec3();
	if (poolParent != NULL)this->poolParent = poolParent;
	this->Reset();
}

Enemy::Enemy(Player* pPlayer, int type, int damage, int health) :Character(type, damage, health) {
	poolParent = NULL;
	shootTimer = NULL;
	this->pPlayer = pPlayer;
}

Enemy::~Enemy() {
	if (shootTimer != NULL)delete shootTimer;
}

Enemy::Enemy(const Enemy& e) : Character(e) {
	this->poolParent = e.poolParent;
	this->pPlayer = e.pPlayer;
	this->shootTimer = new CountDownTimer(*e.shootTimer);
}

const Enemy& Enemy::operator=(const Enemy& e) {
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//CHECK OPERATOR
	if (&e != this) {
		if (shootTimer != NULL)delete shootTimer;
		this->pPlayer = e.pPlayer;
		this->poolParent = e.poolParent;
		this->shootTimer = new CountDownTimer(e.shootTimer->GetCD());
	}
	return *this;
}


