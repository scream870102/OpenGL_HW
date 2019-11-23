#pragma once
#include "../Utils/ObjectPool.h"
#include "Player/Player.h"
#include "../Utils/Random.h"
#include "../Utils/Input.h"
#include "Enemy/Shushu.h"
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
};
