#pragma once
#ifndef _CHARACTER_CONTROLLER_H_
#define _CHARACTER_CONTROLLER_H_
#include "Enemy/Shushu.h"
#include "Enemy/Hakuruma.h"
#include "Enemy/Syabon.h"
#define ENEMY_TYPE_NUM 1
#define INIT_PLAYER_HEALTH 100
#define INIT_PLAYER_DAMAGE 50
#define SHUSHU_HEALTH 500
#define SHUSHU_DAMAGE 50
class CharacterController
{
private:
	int maxEnemyNum;
	int enemyDie;
	bool bBossFight;
public:
	ObjectPool<Enemy> enemies;
	Player* pPlayer;
private:
public:
	CharacterController(int maxEnemyNum,Input * input, mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~CharacterController();
	void Update(float delta);
	void Draw();
	const int HowManyEnemyDie();
	void StartBossFight();
	std::vector<Enemy*>* GetActiveEnemies();
};
#endif // !_CHARACTER_CONTROLLER_H_