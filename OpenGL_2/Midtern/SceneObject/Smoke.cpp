#include "Smoke.h"

Smoke::Smoke(mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	_points[0] = point4(0.0f, -7.0f, 0.0f, 1.0f);
	_points[1] = point4(-6.0f, 4.0f, 0.0f, 1.0f);
	_points[2] = point4(6.0f, 4.0f, 0.0f, 1.0f);
	_colors[0] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[1] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[2] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	colorType[0] = color4(0.98f, 0.81f, 0.81f, 1.0f);
	colorType[1] = color4(1.0f, 0.98f, 0.8f, 1.0f);
	poolParent = NULL;
	transform = new Transform();
	transform->Init(_points, _colors, SMOKE_NUM, matModelView, matProjection, shaderHandle);
	timer = new CountDownTimer(FADE_TIME);
	bUsing = false;
}

Smoke::~Smoke() {
	if (transform != NULL)delete transform;
	if (timer != NULL)delete timer;
}

Smoke::Smoke(const Smoke& s) {
	memcpy(_points, s._points, sizeof(s._points));
	memcpy(_colors, s._colors, sizeof(s._colors));
	poolParent = s.poolParent;
	transform = new Transform(*s.transform);
	timer = new CountDownTimer(timer->GetCD());
	bUsing = s.bUsing;
}

const Smoke& Smoke::operator=(const Smoke& s) {
	if (&s != this) {
		delete transform;
		delete timer;
		memcpy(_points, s._points, sizeof(s._points));
		memcpy(_colors, s._colors, sizeof(s._colors));
		poolParent = s.poolParent;
		transform = new Transform(*s.transform);
		timer = new CountDownTimer(timer->GetCD());
		bUsing = s.bUsing;
	}
	return *this;
}

void Smoke::Draw() {
	transform->Draw();
}

void Smoke::Update(float delta) {
	if (bUsing && timer->IsFinished()) {
		bUsing = false;
		poolParent->Recycle(this);
	}
	if (!timer->IsFinished()) {
		float newScale = this->transform->scale.x - FADE_SCALE_VEL * delta;
		this->transform->scale = vec3(newScale < 0.0f ? 0.0f : newScale);
		float newAlplha = this->transform->GetAlpha() - FADE_ALPHA_VEL * delta;
		this->transform->SetAlpha(newAlplha<0.0f?0.0f:newAlplha);
	}
}

void Smoke::Bomb(const vec3 position) {
	this->transform->position = position;
	this->transform->scale = vec3(Random::GetRand(MAX_SCALE, 1.0f));
	this->transform->SetColor(colorType[Random::GetRandBool() ]);
	this->transform->SetAlpha(Random::GetRand(1.0f,MIN_INIT_ALPHA));
	this->transform->rotation.z = Random::GetRand(360.0f);
	this->timer->Reset();
	this->bUsing = true;
}
