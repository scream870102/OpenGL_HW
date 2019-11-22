#pragma once
#include "../Character.h"
#include "../../Utils/CountdownTimer.h"
#include "../Bullet/BulletPool.h"
#include "../../Utils/Movement/PingPongMove.h"
#define NUM 12
#define SHUSHU_SHOOT_CD 2000
#define BULLET_SPEED 100
#define MOVE_SPEED 150.0f
#define ROTATE_SPEED 200.0f
#define SHUSHU_RADIUS 24.0f
class Shushu :public Character {
private:
	point4 _points[NUM];
	color4 _colors[NUM];
	CountDownTimer* timer;
	PingPongMove* move;
public:
private:
	void Dead()override;
	void AutoRotation(float delta);
public:
	Shushu(int damage, int health, vec3 initPos, mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Shushu();
	Shushu(const Shushu& s);
	Shushu& operator=(const Shushu& s);
	void Update(float delta)override;


};

