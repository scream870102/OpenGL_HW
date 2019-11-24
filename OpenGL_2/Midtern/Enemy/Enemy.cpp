#include "Enemy.h"


void Enemy::DamageAnim(float delta) {
	if (!damageTimer->IsFinished()) {
		float a = this->transform->GetAlpha();
		this->transform->SetAlpha(a - DAMAGA_FADE_VEL * delta);
	}
	else {
		this->transform->SetAlpha(1.0f);
		bTakeDamage = false;
	}
}

Enemy::Enemy(Player* pPlayer, int type, int damage, int health) :Character(type, damage, health) {
	poolParent = NULL;
	damageTimer = new CountDownTimer(DAMAGE_ANIM);
	this->pPlayer = pPlayer;

}

Enemy::~Enemy() {}

Enemy::Enemy(const Enemy& e) : Character(e) {
	this->poolParent = e.poolParent;
	this->pPlayer = e.pPlayer;
}

const Enemy& Enemy::operator=(const Enemy& e) {
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//CHECK OPERATOR
	if (&e != this) {
		*this = e;
		this->pPlayer = e.pPlayer;
		this->poolParent = e.poolParent;
	}
	return *this;
}

void Enemy::Init(vec3 initPos, ObjectPool<Enemy>* poolParent) {
	this->transform->position = initPos;
	if (poolParent != NULL)this->poolParent = poolParent;
	this->Reset();
}

void Enemy::TakeDamage(int damage) {
	if (!bTakeDamage)damageTimer->Reset(DAMAGE_ANIM);
	Character::TakeDamage(damage);
}
