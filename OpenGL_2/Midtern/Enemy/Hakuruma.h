#pragma once
#include "Enemy.h"
#include "../../Utils/Movement/RandMove.h"
class Hakuruma:public Enemy
{
#define NUM 36
#define MOVE_SPEED 200.0f
#define MOVE_Y_MGNFC 0.5f
#define HAKURUMA_RADIUS 22.0f
#define SHOOT_CD 2000
#define BULLET_SPEED 500
private:
	point4 _points[NUM];
	color4 _colors[NUM];
	RandMove* move;
public:
private:
public:
	Hakuruma(Player* player, int damage, int health, vec3 initPos, mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Hakuruma();
	Hakuruma(const Hakuruma& h);
	Hakuruma& operator=(const Hakuruma h);
	void Update(float delta)override;
};

