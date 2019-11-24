#include "Enemy.h"


void Enemy::DamageAnim(float delta) {
	if (!damageTimer->IsFinished()) {
		float a = this->transform->GetAlpha();
		this->transform->SetAlpha(a - DAMAGA_FADE_VEL * delta);
		if (damageTimer->Remain() % SMOKE_HZ==0)
			SmokePool::GetInstance()->Bomb(this->transform->position);
	}
	else {
		this->transform->SetAlpha(1.0f);
		bTakeDamage = false;
	}
}

Enemy::Enemy(Player* pPlayer, int type, int damage, int health) :Character(type, damage, health) {
	poolParent = NULL;
	shootTimer = NULL;
	damageTimer = new CountDownTimer(DAMAGE_ANIM);
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

void Enemy::Init(vec3 initPos, ObjectPool<Enemy>* poolParent) {
	this->transform->position = initPos;
	this->transform->rotation = vec3();
	if (poolParent != NULL)this->poolParent = poolParent;
	this->Reset();
}

void Enemy::TakeDamage(int damage) {
	if (!bTakeDamage)damageTimer->Reset(DAMAGE_ANIM);
	Character::TakeDamage(damage);
}
