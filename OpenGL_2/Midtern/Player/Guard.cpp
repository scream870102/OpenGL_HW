#include "Guard.h"
Guard::Guard(mat4& matModelView, mat4& matProjection, GLuint shaderHandle)
{
	_points[0] = point4(5.0f, -5.0f, 0.0f, 1.0f);
	_points[1] = point4(-5.0f, -5.0f, 0.0f, 1.0f);
	_points[2] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[3] = point4(5.0f, -5.0f, 0.0f, 1.0f);
	_points[4] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[5] = point4(20.0f, 0.0f, 0.0f, 1.0f);
	_points[6] = point4(-5.0f, -5.0f, 0.0f, 1.0f);
	_points[7] = point4(-20.0f, 0.0f, 0.0f, 1.0f);
	_points[8] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_colors[0] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[1] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[2] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[3] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[4] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[5] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[6] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[7] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[8] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	transform = new Transform();
	transform->Init(_points, _colors, GUARD_NUM, matModelView, matProjection, shaderHandle);
	collider = new CircleCollider(GUARD_RADIUS, this->transform->GetGlobalPosition());
	IsEnable = true;
}

Guard::~Guard() {
	if (transform != NULL)delete transform;
	if (collider != NULL)delete collider;
}

void Guard::Draw() {
	if (IsEnable)
		transform->Draw();
}

void Guard::Update(float delta) {
	if (IsEnable) {
		collider->SetCenterPoint(transform->GetGlobalPosition());
		collider->SetScale(transform->scale.x);
	}

}

CircleCollider* Guard::GetCollider() {
	return collider;
}
