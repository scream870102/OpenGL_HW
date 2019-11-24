#pragma once
#include "Smoke.h"
class SmokePool
{
private:
	ObjectPool<Smoke> smokePool;
	static SmokePool* instance;
public:
	

private:
public:
	SmokePool(int number = 200, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	~SmokePool();
	Smoke* Bomb(const vec3 position);
	void Draw();
	void Update(float delta);
	//SECTION FOR SINGLETON PATTERN
	static SmokePool* Create(int number = 200, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	static SmokePool* GetInstance();
	void Destroy();
};
