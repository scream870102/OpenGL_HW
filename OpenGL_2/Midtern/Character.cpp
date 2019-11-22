#include "Character.h"

Character::Character(int health){
	this->health = health;
	this->bDead = health > 0;
}

Character::~Character(){}

Character::Character(const Character& c){
	transform = c.transform;
	health = health;
	bDead = bDead;
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
