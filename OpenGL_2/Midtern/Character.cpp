#include "Character.h"

Character::Character(int type, int damage, int health) {
	this->type = type;
	this->health = health;
	this->damage = damage;
	this->bDead = false;
	this->transform = NULL;
	this->collider = NULL;
}

Character::~Character() {
	if (transform != NULL)delete transform;
	if (collider != NULL)delete collider;
}

Character::Character(const Character& c) {
	this->health = c.health;
	this->bDead = c.bDead;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TOFIX:CHECK IF THIS RIGHT WAY
	this->collider = new CircleCollider(*c.collider);
	this->transform = new Transform(*c.transform);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	this->damage = c.damage;
	this->type = c.type;
}

const Character& Character::operator=(const Character& c) {
	if (&c != this) {
		if (transform != NULL)delete transform;
		if (collider != NULL)delete collider;
		this->health = c.health;
		this->bDead = c.bDead;
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//TOFIX:CHECK IF THIS RIGHT WAY
		this->collider = new CircleCollider(*c.collider);
		this->transform = new Transform(*c.transform);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		this->damage = c.damage;
		this->type = c.type;
	}
	return *this;
}

void Character::TakeDamage(int damage) {
	health -= damage;
	Print(bDead);
	if (health <= 0)Dead();
}

void Character::Update(float delta) {
	if (this->collider != NULL) {
		this->collider->SetCenterPoint(this->transform->position);
		//!!!!!!!!!!!!!!!!!!!
		//SCALE IS ONLY¡@IN X COORDINATE
		//!!!!!!!!!!!!!!!!!!!
		this->collider->SetScale(this->transform->scale.x);
	}
}

void Character::Draw() {
	transform->Draw();
}

const int Character::GetHealth()const {
	return this->health;
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
	Print("I am Dead");
}
