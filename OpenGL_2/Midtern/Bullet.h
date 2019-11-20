#pragma once
#include "../Utils/Transform.h"
#include "../Utils/ObjectPool.h"
#define BULLET_NUM 6
class Bullet
{
private:
	point4 _points[BULLET_NUM];
	color4 _colors[BULLET_NUM];
public:
	ObjectPool<Bullet>* poolParent;
	Transform* transform;
	Bullet(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Bullet();
	Bullet(const Bullet& b);
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	void Draw();
	void Update(float delta);
};
