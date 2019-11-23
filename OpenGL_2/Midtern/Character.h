#pragma once
#include "../Utils/Transform.h"
#include "../Utils/Collider/CircleCollider.h"
#include "../Utils/Random.h"
class Character
{
private:
	int health;
	bool bDead;
protected:
	CircleCollider* collider;
public:
	Transform* transform;
	int damage;
	int type;
private:
protected:
	virtual void Dead();
public:
	Character(int type = NONE, int damage = 0, int health = 100);
	~Character();
	Character(const Character& c);
	const Character& operator=(const Character& c);
	void TakeDamage(int damage);
	virtual void Update(float delta);
	virtual void Draw();
	const int GetHealth() const;
	const bool IsDead() const;
	const bool IsCollide(CircleCollider* other);
	const CircleCollider* GetCollider();

};
