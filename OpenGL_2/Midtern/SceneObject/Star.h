#pragma once
#include "../../Utils/Transform.h"
#include "../../Utils/ObjectPool.h"
#define STAR_NUM 18
class Star {
private:
	point4 _points[STAR_NUM];
	color4 _colors[STAR_NUM];
	float speed;
	float rotateSpeed;
	bool bRotateClockWise;
public:
	ObjectPool<Star>* poolParent;
	Transform* transform;
private:
	void AutoRotation(float delta);
public:
	Star(float speed, float rotateSpeed, bool bRotateClockWise = false, mat4& matModelView = mat4(1.0f), mat4& matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f), GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Star();
	Star(const Star& s);
	const Star& operator=(const Star& s);
	void Draw();
	void Update(float delta);
	void Init(vec3 position);
	void Init(vec3 position, float speed, vec3 scale = vec3(1.0f));
	void SetColor(vec4 color);
	void SetRotation(float speed, bool IsRotateClockwise = false);
};


