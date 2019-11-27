#include "Character.h"

void Character::TakeDamage(int damage) {
	if (!bTakeDamage)damageTimer->Reset(DAMAGE_ANIM);
	health -= damage;
	bTakeDamage = true;
	if (health <= 0)
		Dead();
}

void Character::Update(float delta) {
	if (this->collider != NULL) {
		this->collider->SetCenterPoint(this->transform->position);
		//!!!!!!!!!!!!!!!!!!!
		//SCALE IS ONLY¡@IN X COORDINATE
		//!!!!!!!!!!!!!!!!!!!
		this->collider->SetScale(this->transform->scale.x);
	}
	if (bTakeDamage)
		DamageAnim(delta);
}

void Character::Draw() {
	transform->Draw();
}

const int Character::GetHealth()const {
	return this->health;
}


void Character::Reset() {
	this->health = initHealth;
	this->bDead = false;
	this->transform->SetColors(originColor);
}

const bool Character::IsDead() const {
	return bDead;
}

const bool Character::IsCollide(CircleCollider* other) {
	return this->collider->IsCollide(other);
}

const CircleCollider* Character::GetCollider() {
	return this->collider;
}

void Character::Dead() {
	bDead = true;
}

void Character::DamageAnim(float delta) {
	if (!damageTimer->IsFinished()) {
		float a = this->transform->GetAlpha();
		this->transform->SetAlpha(a - DAMAGA_FADE_VEL * delta);
		if (damageTimer->Remain() % SMOKE_HZ == 0)
			SmokePool::GetInstance()->Bomb(this->transform->position);
	}
	else {
		this->transform->SetAlpha(1.0f);
		bTakeDamage = false;
	}
}

void Character::SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	transform->SetShader(matModelView, matProjection, shaderHandle);
}

Character::Character(int type, int damage, int health) {
	this->type = type;
	this->health = health;
	this->damage = damage;
	this->bDead = false;
	this->transform = NULL;
	this->collider = NULL;
	this->damageTimer = new CountDownTimer(DAMAGE_ANIM);
	this->bTakeDamage = false;
	this->initHealth = health;
}

Character::~Character() {
	if (transform != NULL)delete transform;
	if (collider != NULL)delete collider;
	if (damageTimer != NULL)delete damageTimer;
}

Character::Character(const Character& c) {
	this->health = c.health;
	this->initHealth = c.initHealth;
	this->bDead = c.bDead;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TOFIX:CHECK IF THIS RIGHT WAY
	this->collider = new CircleCollider(*c.collider);
	this->transform = new Transform(*c.transform);
	this->damageTimer = new CountDownTimer(*c.damageTimer);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	this->damage = c.damage;
	this->type = c.type;
	this->originColor = std::vector<color4>(c.originColor.begin(), c.originColor.end());
	this->bTakeDamage = c.bTakeDamage;
}

const Character& Character::operator=(const Character& c) {
	if (&c != this) {
		if (transform != NULL)delete transform;
		if (collider != NULL)delete collider;
		this->health = c.health;
		this->initHealth = c.initHealth;
		this->bDead = c.bDead;
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//TOFIX:CHECK IF THIS RIGHT WAY
		this->collider = new CircleCollider(*c.collider);
		this->transform = new Transform(*c.transform);
		this->damageTimer = new CountDownTimer(*c.damageTimer);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		this->damage = c.damage;
		this->type = c.type;
		this->originColor = std::vector<color4>(c.originColor.begin(), c.originColor.end());
		this->bTakeDamage = c.bTakeDamage;
	}
	return *this;
}

