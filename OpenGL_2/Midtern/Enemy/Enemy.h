#pragma once
#include "../Player/Player.h"
#include "../../Utils/ObjectPool.h"
#define DAMAGA_FADE_VEL 0.5f 
#define DAMAGE_ANIM 1000
class Enemy :public Character
{
private:
protected:
	Player* pPlayer;
public:
	ObjectPool<Enemy>* poolParent;
private:
protected:
	void DamageAnim(float delta)override;
public:
	Enemy(Player* pPlayer,int type = NONE, int damage = 0, int health = 100);
	~Enemy();
	Enemy(const Enemy& e);
	const Enemy& operator=(const Enemy& e);
	virtual void Init(vec3 initPos, ObjectPool<Enemy>* poolParent = NULL);
	void TakeDamage(int damage) override;

};

