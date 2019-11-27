#pragma once
#include "TracingBullet.h"
#include "../Character.h"
class BulletPool
{
private:
	ObjectPool<Bullet> _bulletPool;
	ObjectPool<TracingBullet> _tBulletPool;
	//SECTION FOR SINGLETON PATTERN
	static BulletPool* _instance;
	//SECTION FOR SINGLETON PATTERN
public:
private:
public:
	BulletPool(int number = 100, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	~BulletPool();
	Bullet* Fire(int type, vec3 position, vec3 direction, float speed, int damage);
	Bullet* Fire(int type, vec3 position, vec3 direction, float speed, int damage, Transform* target,int tracingTime);
	void Draw();
	void Update(float delta);
	bool CheckCollisionWithCharacter(Character* character);
	bool CheckCollision(CircleCollider* other,int checkType);
	//SECTION FOR SINGLETON PATTERN
	static BulletPool* Create(int number = 100, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	static BulletPool* GetInstance();
	void Destroy();
	//SECTION FOR SINGLETON PATTERN
};
