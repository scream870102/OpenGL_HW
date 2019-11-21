#pragma once
//#include "../Utils/ObjectPool.h"
#include "Bullet.h"
class BulletPool
{
public:
	BulletPool(int number = 100, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	~BulletPool();
	static BulletPool* Create(int number = 100, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	static BulletPool* GetInstance();
	void Destroy();
	bool Fire(int type,vec3 position,float speed);
	void Draw();
	void Update(float delta);

private:
	ObjectPool<Bullet> _bulletPool;
	static BulletPool* _instance;
};
