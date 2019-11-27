#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "../Utils/Transform.h"
#include "../Utils/Collider/CircleCollider.h"
#include "../Utils/Random.h"
#include "../Utils/CountdownTimer.h"
#include "SceneObject/SmokePool.h"
#define DAMAGA_FADE_VEL 0.75f 
#define DAMAGE_ANIM 500
#define SMOKE_HZ 25
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
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);

};
#endif // !_CHARACTER_H_