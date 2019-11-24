#pragma once
#include "Enemy.h"
#include "../../Utils/Movement/RandMove.h"
#include "../../Utils/Movement/TraceMove.h"
#define NUM 6
#define MOVE_SPEED 20.0f
#define MOVE_Y_MGNFC 0.5f
#define SYABON_RADIUS 22.0f
#define SHOOT_CD 2000
#define BULLET_SPEED 500
class Syabon :public Enemy
{
private:
	point4 _points[NUM];
	color4 _colors[NUM];
	TraceMove* move;
public:
private:
public:
	Syabon(Player* player, int damage, int health, vec3 initPos, mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Syabon();
	Syabon(const Syabon& h);
	Syabon& operator=(const Syabon h);
	void Update(float delta)override;
};

