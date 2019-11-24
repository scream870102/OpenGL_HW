#include "Syabon.h"
Syabon::Syabon(Player* player, int damage, int health, vec3 initPos, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) :Enemy(player, ENEMY, damage, health) {
	_points[0] = point4(0.0f, -21.0f, 0.0f, 1.0f);
	_points[1] = point4(-12.0f, -7.0f, 0.0f, 1.0f);
	_points[2] = point4(12.0f, -7.0f, 0.0f, 1.0f);
	_points[3] = point4(-5.0f, -7.0f, 0.0f, 1.0f);
	_points[4] = point4(5.0f, -7.0f, 0.0f, 1.0f);
	_points[5] = point4(0.0f, 21.0f, 0.0f, 1.0f);
	_colors[0] = color4(0.6196078431372549f, 0.6352941176470588f, 0.8392156862745098f, 1.0f);
	_colors[1] = color4(0.6196078431372549f, 0.6352941176470588f, 0.8392156862745098f, 1.0f);
	_colors[2] = color4(0.6196078431372549f, 0.6352941176470588f, 0.8392156862745098f, 1.0f);
	_colors[3] = color4(0.6196078431372549f, 0.6352941176470588f, 0.8392156862745098f, 1.0f);
	_colors[4] = color4(0.6196078431372549f, 0.6352941176470588f, 0.8392156862745098f, 1.0f);
	_colors[5] = color4(0.6196078431372549f, 0.6352941176470588f, 0.8392156862745098f, 1.0f);
	transform = new Transform();
	transform->Init(_points, _colors, NUM, matModelView, matProjection, shaderHandle);
	transform->position = initPos;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//MUST SET ORIGINAL COLORS
	originColor = std::vector<color4>(_colors, _colors + (int)(sizeof(_colors) / sizeof(_colors[0])));
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	move = new TraceMove(transform, MOVE_SPEED,pPlayer->transform);
	collider = new CircleCollider(SYABON_RADIUS, this->transform->position);
	shootTimer = new CountDownTimer(SHOOT_CD);
}

Syabon::~Syabon() {
	if (move != NULL)delete move;
}

Syabon::Syabon(const Syabon& h) :Enemy(h) {
	memcpy(_points, h._points, sizeof(h._points));
	memcpy(_colors, h._colors, sizeof(h._colors));
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TOFIX:CHECK IF THIS RIGHT WAY
	move = new TraceMove(*h.move);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

Syabon& Syabon::operator=(const Syabon h) {
	if (&h != this) {
		if (move != NULL)delete move;
		memcpy(_points, h._points, sizeof(h._points));
		memcpy(_colors, h._colors, sizeof(h._colors));
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//TOFIX:CHECK IF THIS RIGHT WAY
		move = new TraceMove(*h.move);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	return *this;
}

void Syabon::Update(float delta) {
	Enemy::Update(delta);
	this->transform->rotation.z = move->GetDegree()+90.0f;
	this->transform->position = move->GetNextPos(delta);
	if (shootTimer->IsFinished()) {
		shootTimer->Reset();
		vec3 direction = Angel::normalize(pPlayer->transform->position - transform->position);
		BulletPool::GetInstance()->Fire(ENEMY, transform->position, direction, BULLET_SPEED, damage);
	}
}
