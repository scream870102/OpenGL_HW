#pragma once
#include "../Utils/Input.h"
#include "../Utils/CountdownTimer.h"
#include "BulletPool.h"
#include "Character.h"
#define PLAYER_NUM 27
#define BULLETS_NUM 10
#define NORMAL_BULLET_SPEED 500
#define SHOOT_CD 100
typedef std::vector<Bullet*>* BVectorP;
class Player :public Character {
public:
	Player(int health, mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Player();
	Player(const Player& p);
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	void Update(float delta)override;
private:
	void Dead()override;
public:
	//only the pointer for outer input class
	Input* input;
private:
	const int P_NUM = PLAYER_NUM;
	point4 _points[PLAYER_NUM];
	color4 _colors[PLAYER_NUM];
	CountDownTimer* shootTimer;

};