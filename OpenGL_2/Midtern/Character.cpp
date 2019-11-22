#include "Character.h"

Character::Character(int health){
	this->health = health;
	this->bDead = health > 0;
	this->transform = NULL;
}

Character::~Character(){}

Character::Character(const Character& c){
	this->transform = c.transform;
	this->health = c.health;
	this->bDead = c.bDead;
}

void Character::TakeDamage(int damage) {
	health -= damage;
	if (health <= 0)Dead();
}

void Character::Update(float delta) {}

void Character::Draw() {
	transform->Draw();
}

const int Character::GetHealth()const {
	return this->health;
}

const bool Character::IsDead() const {
	return bDead;
}

void Character::Dead() {
	bDead = true;
	Print("I am Dead");
}
