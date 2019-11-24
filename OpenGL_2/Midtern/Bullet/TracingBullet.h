#pragma once
#include "Bullet.h"
#include <math.h>
#include "../../Utils/Mathf.h"
#include "../../Utils/CountdownTimer.h"
class TracingBullet :public Bullet
{
private:
	Transform* target;
	CountDownTimer* tracingTimer;
public:


private:
public:
	TracingBullet(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~TracingBullet();
	TracingBullet(const TracingBullet& b);
	const TracingBullet& operator=(const TracingBullet& b);
	void Fire(int type, vec3 position, vec3 direction, float speed, int damage, Transform* target,int tracingTime);
	void Update(float delta)override;
};
