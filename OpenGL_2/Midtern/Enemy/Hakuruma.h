#pragma once
#ifndef _HAKURUMA_H_
#define _HAKURUMA_H_

#include "Enemy.h"
#include "../../Utils/Movement/RandMove.h"
#define HAKURUMA_NUM 60
#define HAKURUMA_MOVE_SPEED 200.0f
#define MOVE_Y_MGNFC 0.5f
#define HAKURUMA_RADIUS 22.0f
#define SHOOT_CD 2000
#define BULLET_SPEED 500
#define ROTATE_VEL 400.0f
class Hakuruma:public Enemy
{
private:
	point4 _points[HAKURUMA_NUM];
	color4 _colors[HAKURUMA_NUM];
	RandMove* move;
	bool bFacingRight;
public:
private:
	void AutoRotation(float delta);
public:
	Hakuruma(Player* player, int damage, int health, vec3 initPos, mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Hakuruma();
	Hakuruma(const Hakuruma& h);
	Hakuruma& operator=(const Hakuruma h);
	void Update(float delta)override;
};
#endif // !_HAKURUMA_H_
