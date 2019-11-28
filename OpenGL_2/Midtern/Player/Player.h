#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../../Utils/Input.h"
#include "../../Utils/CountdownTimer.h"
#include "../Bullet/BulletPool.h"
#include "../Character.h"
#include "../../Utils/Mathf.h"
#include "Guard.h"
#define PLAYER_NUM 51
//#define PLAYER_NUM 39
#define BULLETS_NUM 10
#define NORMAL_BULLET_SPEED 500
#define PLAYER_SHOOT_CD 100
#define PLAYER_RADIUS 50.0f
#define PLAYER_Y_RANGE 0.5f
#define SHOT_GUN_CD 1000
#define SHOUT_GUN_NUM 5
#define SHOUT_GUN_OFFSET 20.0f
#define SHOT_GUN_SPEED 250.0f
#define TRACE_NUM 5
#define TRACE_SPEED 500.0f
#define TRACE_CD 500
#define TRACE_TIME 2000
#define GUARD_MAX_NUM 5
#define GUARD_DISTANCE 100.0f
#define GUARD_ROTATE_VEL 100.0f
#define GUARD_CD 2000
typedef std::vector<Bullet*>* BVectorP;
//THIS iS FOR PREVENT INCLUDE EACH OTHER
//SHOULD INCLUDE CharacterController in CPP FILE
class CharacterController;
class Player :public Character {
private:
	const int P_NUM = PLAYER_NUM;
	point4 _points[PLAYER_NUM];
	color4 _colors[PLAYER_NUM];
	CountDownTimer* shootTimer;
	CountDownTimer* shotGunTimer;
	CountDownTimer* traceTimer;
	bool bShotGun;
	bool bTrace;
	CharacterController* pCC;
	//TEST
	std::vector<Guard*> guards;
	float guardRotOffset;
	CountDownTimer* guardTimer;
public:
	//only the pointer for outer input class
	Input* input;
private:
	void Dead()override;
	void ShotGun(float delta);
	void NormalShot(float delta);
	void TraceShot(float delta);
	void UpdateGuards(float delta);
protected:
public:
	Player(int damage, int health, mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Player();
	Player(const Player& p);
	const Player& operator=(const Player& p);
	void Update(float delta)override;
	void Draw() override;
	void SetCharacterController(CharacterController* pCC);
	std::vector<Guard*>	GetEnableGuards();
};
#endif // !_PLAYER_H_