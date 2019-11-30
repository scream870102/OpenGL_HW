#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "../Player/Player.h"
#include "../../Utils/Movement/Movement.h"
class Enemy :public Character
{
private:
protected:
public:
	Player* pPlayer;
	CountDownTimer* shootTimer;
	ObjectPool<Enemy>* poolParent;
private:
protected:
public:
	Enemy(Player* pPlayer, int type = NONE, int damage = 0, int health = 100);
	~Enemy();
	Enemy(const Enemy& e);
	const Enemy& operator=(const Enemy& e);
	virtual void Init(vec3 initPos, ObjectPool<Enemy>* poolParent = NULL);
}; 
#endif // !_ENEMY_H_
