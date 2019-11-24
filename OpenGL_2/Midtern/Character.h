#pragma once
#include "../Utils/Transform.h"
#include "../Utils/Collider/CircleCollider.h"
#include "../Utils/Random.h"
#include "../Utils/CountdownTimer.h"
class Character
{
private:
	int health;
	bool bDead;
	int initHealth;
protected:
	bool bTakeDamage;
	CircleCollider* collider;
	std::vector<color4> originColor;
	CountDownTimer* damageTimer;
public:
	Transform* transform;
	int damage;
	int type;
private:
protected:
	virtual void Dead();
	//MUST make bTakeDamage=false
	virtual void DamageAnim(float delta);
public:
	Character(int type = NONE, int damage = 0, int health = 100);
	~Character();
	Character(const Character& c);
	const Character& operator=(const Character& c);
	virtual void TakeDamage(int damage);
	virtual void Update(float delta);
	virtual void Draw();
	const int GetHealth() const;
	void Reset();
	const bool IsDead() const;
	const bool IsCollide(CircleCollider* other);
	const CircleCollider* GetCollider();

};
