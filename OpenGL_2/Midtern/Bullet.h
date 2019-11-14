#pragma once
#include "../Utils/Transform.h"
#define BULLET_NUM 6
class Bullet
{
public:
	Bullet(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Bullet();
	Transform Transform;
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	void Draw();
	void Update(float delta);

private:
	point4 _points[BULLET_NUM];
	color4 _colors[BULLET_NUM];

};
