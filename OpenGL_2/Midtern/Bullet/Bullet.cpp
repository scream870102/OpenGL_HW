#include "Bullet.h"

void Bullet::Draw() {
	transform->Draw();
}

void Bullet::Update(float delta) {
	//set position due to direction
	this->transform->position += this->direction * speed * delta;
	//Update Collider
	this->collider->SetCenterPoint(this->transform->position);
	this->collider->SetScale(this->transform->scale.x);
	//CALL RECYCLE METHOD
	if (transform->position.y >= HEIGHT || transform->position.y <= 0.0f)
		poolParent->Recycle(this);
}

void Bullet::Fire(int type, vec3 position, vec3 direction, float speed, int damage) {
	this->type = type;
	this->transform->position = position;
	this->speed = speed;
	this->transform->SetColor(colors[type]);
	this->damage = damage;
	this->direction = direction;
}

CircleCollider* Bullet::GetCollider() {
	return this->collider;
}

const int Bullet::GetType() {
	return this->type;
}

const int Bullet::GetDamage() {
	return this->damage;
}

void Bullet::SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	transform->SetShader(matModelView, matProjection, shaderHandle);
}

Bullet::Bullet(mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	_points[0] = point4(0.0f, -13.0f, 0.0f, 1.0f);
	_points[1] = point4(-12.0f, 0.0f, 0.0f, 1.0f);
	_points[2] = point4(12.0f, 0.0f, 0.0f, 1.0f);
	_points[3] = point4(-12.0f, -1.0f, 0.0f, 1.0f);
	_points[4] = point4(0.0f, 13.0f, 0.0f, 1.0f);
	_points[5] = point4(12.0f, 0.0f, 0.0f, 1.0f);
	_colors[0] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[1] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[2] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[3] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[4] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[5] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	poolParent = NULL;
	transform = new Transform();
	transform->Init(_points, _colors, BULLET_NUM, matModelView, matProjection, shaderHandle);
	type = NONE;
	speed = 0.0f;
	damage = 0;
	collider = new CircleCollider(BULLET_RADIUS, this->transform->position);
	colors[PLAYER] = vec4(0.72f, 0.86f, 0.72f, 1.0f);
	colors[ENEMY] = vec4(1.0f, 0.69f, 0.49f, 1.0f);
	direction = vec3(0.0f);
}

Bullet::~Bullet() {
	if (transform != NULL)delete transform;
	if (collider != NULL)delete collider;
}

Bullet::Bullet(const Bullet& b) {
	memcpy(_points, b._points, sizeof(b._points));
	memcpy(_colors, b._colors, sizeof(b._colors));
	poolParent = b.poolParent;
	transform = new Transform(*b.transform);
	type = b.type;
	speed = b.speed;
	collider = new CircleCollider(*b.collider);
	damage = b.damage;
	direction = b.direction;
}

const Bullet& Bullet::operator=(const Bullet& b) {
	if (&b != this) {
		delete transform;
		delete collider;
		memcpy(_points, b._points, sizeof(b._points));
		memcpy(_colors, b._colors, sizeof(b._colors));
		poolParent = b.poolParent;
		transform = new Transform(*b.transform);
		collider = new CircleCollider(*b.collider);
		type = b.type;
		speed = b.speed;
		damage = b.damage;
		direction = b.direction;
	}
	return *this;
}