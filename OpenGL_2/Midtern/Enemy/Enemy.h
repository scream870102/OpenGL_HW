#pragma once
#include "../Character.h"
#include "../../Utils/ObjectPool.h"
class Enemy :public Character
{
private:
public:
	ObjectPool<Enemy>* poolParent;
private:
public:
	Enemy(int type = NONE, int damage = 0, int health = 100);
	~Enemy();
	Enemy(const Enemy& e);
	const Enemy& operator=(const Enemy& e);
	virtual void Init(vec3 initPos, ObjectPool<Enemy>* poolParent = NULL);

};

