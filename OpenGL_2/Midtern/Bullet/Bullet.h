#pragma once
#include "../../Utils/Transform.h"
#include "../../Utils/ObjectPool.h"
#include "../../Utils/Collider/CircleCollider.h"
#define BULLET_NUM 6
#define COLOR_NUM 3
#define BULLET_RADIUS 12.5f
class Bullet
{
protected:
	point4 _points[BULLET_NUM];
	color4 _colors[BULLET_NUM];
	int type;
	float speed;
	int damage;
	CircleCollider* collider;
	vec4 colors[COLOR_NUM];
	vec3 direction;
public:
	ObjectPool<Bullet>* poolParent;
	Transform* transform;
private:
public:
	Bullet(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Bullet();
	Bullet(const Bullet& b);
	const Bullet& operator=(const Bullet& b);
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	void Draw();
	virtual void Update(float delta);
	void Fire(int type, vec3 position, vec3 direction, float speed, int damage);
	CircleCollider* GetCollider();
	const int GetType();
	const int GetDamage();
};
