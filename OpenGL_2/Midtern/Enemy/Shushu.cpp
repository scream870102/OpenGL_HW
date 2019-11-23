#include "Shushu.h"

Shushu::Shushu(int damage, int health, vec3 initPos, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) :Enemy(ENEMY, damage, health) {
	_points[0] = point4(0.0f, -24.0f, 0.0f, 1.0f);
	_points[1] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[2] = point4(6.0f, -9.0f, 0.0f, 1.0f);
	_points[3] = point4(-15.0f, -5.0f, 0.0f, 1.0f);
	_points[4] = point4(-24.0f, 0.0f, 0.0f, 1.0f);
	_points[5] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[6] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[7] = point4(-6.0f, 15.0f, 0.0f, 1.0f);
	_points[8] = point4(0.0f, 24.0f, 0.0f, 1.0f);
	_points[9] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[10] = point4(24.0f, 0.0f, 0.0f, 1.0f);
	_points[11] = point4(8.0f, 6.0f, 0.0f, 1.0f);
	_colors[0] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[1] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[2] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[3] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[4] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[5] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[6] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[7] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[8] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[9] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[10] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	_colors[11] = color4(0.57f, 0.82f, 0.8f, 1.0f);
	transform = new Transform();
	transform->Init(_points, _colors, NUM, matModelView, matProjection, shaderHandle);
	transform->position = initPos;
	timer = new CountDownTimer(SHUSHU_SHOOT_CD,Random::GetRand(SHUSHU_SHOOT_CD));
	move = new PingPongMove(this->transform, MOVE_SPEED, (float)WIDTH, 0.0f);
	collider = new CircleCollider(SHUSHU_RADIUS, this->transform->position);
}

Shushu::~Shushu() {
	if (timer != NULL)delete timer;
	if (move != NULL)delete move;
}

Shushu::Shushu(const Shushu& s) :Enemy(s) {
	memcpy(_points, s._points, sizeof(s._points));
	memcpy(_colors, s._colors, sizeof(s._colors));
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TOFIX:CHECK IF THIS RIGHT WAY
	timer = new CountDownTimer(*s.timer);
	move = new PingPongMove(*s.move);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

Shushu& Shushu::operator=(const Shushu& s) {
	if (&s != this) {
		if (timer != NULL)delete timer;
		if (move != NULL)delete move;
		memcpy(_points, s._points, sizeof(s._points));
		memcpy(_colors, s._colors, sizeof(s._colors));
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//TOFIX:CHECK IF THIS RIGHT WAY
		timer = new CountDownTimer(*s.timer);
		move = new PingPongMove(*s.move);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	return *this;
}

void Shushu::Update(float delta) {
	Enemy::Update(delta);
	this->transform->position = move->GetNextPos(delta);
	AutoRotation(delta);
	if (timer->IsFinished()) {
		timer->Reset();
		BulletPool::GetInstance()->Fire(ENEMY, this->transform->position, BULLET_SPEED, this->damage);
	}
}

void Shushu::Dead() {
	Enemy::Dead();
	Print("KISUNOSHURIKEN");
}

void Shushu::AutoRotation(float delta) {
	if (this->move->IsFacingRight())
		this->transform->rotation.z += ROTATE_SPEED * delta;
	else
		this->transform->rotation.z -= ROTATE_SPEED * delta;
}
