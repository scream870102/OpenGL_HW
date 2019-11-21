#pragma once
#include "Star.h"
#include "../Utils/Random.h"
#define MAX_STAR_NUM 20
#define STAR_SPEED 50
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

