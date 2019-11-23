#pragma once
#include "Bullet.h"
#include "../Character.h"
class BulletPool
{
private:
	ObjectPool<Bullet> _bulletPool;
	//SECTION FOR SINGLETON PATTERN
	static BulletPool* _instance;
	//SECTION FOR SINGLETON PATTERN
public:
private:
public:
	BulletPool(int number = 100, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	~BulletPool();
	Bullet* Fire(int type, vec3 position, float speed, int damage);
	void Draw();
	void Update(float delta);
	void CheckCollisionWithCharacter(const std::vector<Character*> characters);
	bool CheckCollisionWithCharacter(Character* character);
	//SECTION FOR SINGLETON PATTERN
	static BulletPool* Create(int number = 100, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	static BulletPool* GetInstance();
	void Destroy();
	//SECTION FOR SINGLETON PATTERN
};
