#pragma once
#include "../../Utils/Transform.h"
#include "../../Utils/Collider/CircleCollider.h"
#define GUARD_NUM 9
#define GUARD_RADIUS 20
class Guard
{
private:
	point4 _points[GUARD_NUM];
	color4 _colors[GUARD_NUM];
	CircleCollider* collider;
public:
	bool IsEnable;
	Transform* transform;

private:
public:
	Guard(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Guard();
	void Draw();
	void Update(float delta);
	CircleCollider* GetCollider();
};

