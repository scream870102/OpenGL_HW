#pragma once
#include "Bullet.h"
class Character
{
public:
	Character();
	~Character();

private:
	ObjectPool<Bullet> _bulletPool;
};

Character::Character()
{
}

Character::~Character()
{
}