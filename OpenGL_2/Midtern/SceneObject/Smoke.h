#pragma once
#include "../../Utils/CountdownTimer.h"
#include "../../Utils/Transform.h"
#include "../../Utils/ObjectPool.h"
#include "../../Utils/Random.h"
#include "../../Utils/Mathf.h"
#define SMOKE_NUM 3
#define FADE_TIME 500
#define MAX_SCALE 2.5f
#define FADE_ALPHA_VEL 1.0f
#define FADE_SCALE_VEL 2.0f
#define MIN_INIT_ALPHA 0.8f
#define SMOKE_COLOR 2
class Smoke
{
private:
	point4 _points[SMOKE_NUM];
	color4 _colors[SMOKE_NUM];
	CountDownTimer* timer;
	bool bUsing;
	color4 colorType[SMOKE_COLOR];
public:
	Transform* transform;
	ObjectPool<Smoke>* poolParent;
private:
public:
	Smoke(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Smoke();
	Smoke(const Smoke& s);
	const Smoke& operator=(const Smoke& s);
	void Draw();
	void Update(float delta);
	void Bomb(const vec3 position);
};
