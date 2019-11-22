#pragma once
#include "../Utils/Transform.h"
class Character
{
public:
	Character(int health=100);
	~Character();
	Character(const Character& c);
	void TakeDamage(int damage);
	virtual void Update(float delta);
	virtual void Draw();
	const int GetHealth() const;
	const bool IsDead() const;
protected:
	virtual void Dead();
public:
	Transform* transform;
private:
	int health;
	bool bDead;
};
