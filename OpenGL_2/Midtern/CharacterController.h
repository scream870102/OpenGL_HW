#pragma once
#ifndef _CHARACTER_CONTROLLER_H_
#define _CHARACTER_CONTROLLER_H_
#include "Enemy/Shushu.h"
#include "Enemy/Hakuruma.h"
#include "Enemy/Syabon.h"
#include "Enemy/Boss.h"
#define ENEMY_TYPE_NUM 3
#define INIT_PLAYER_HEALTH 5000
#define INIT_PLAYER_DAMAGE 50
#define SHUSHU_HEALTH 250
#define SHUSHU_DAMAGE 50
#define HAKURUMA_HEALTH 500
#define HAKURUMA_DAMAGE 25
#define SYABON_HEALTH 100
#define SYABON_DAMAGE 100

#define BOSS_HEALTH 5000
#define BOSS_DAMAGE 50
class CharacterController
{
private:
	int maxEnemyNum;
	int enemyDie;
	bool bBossFight;
public:
	ObjectPool<Enemy> enemies;
	Boss* boss;
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