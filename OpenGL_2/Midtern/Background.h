#pragma once
#include "Star.h"
#include "../Utils/Random.h"
#define MAX_STAR_NUM 20
#define MAX_STAR_SPEED 80
#define MIN_STAR_SPEED 50
#define MIN_STAR_ALPHA 0.25f
#define MAX_STAR_ALPHA 0.75f
#define MAX_STAR_SCALE 0.75f
#define MIN_STAR_SCALE 0.25f
#define MIN_STAR_ROTATE_SPEED 30.0f
#define MAX_STAR_ROTATE_SPEED 50.0f
class Background
{
public:
	Background(int number = 100, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Background();
	void Draw();
	void Update(float delta);

private:
	ObjectPool<Star> _starPool;
};

