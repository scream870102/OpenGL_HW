#include "Star.h"
Star::Star(float speed, float rotateSpeed, bool bRotateClockWise,mat4& matModelView, mat4& matProjection , GLuint shaderHandle){
	_points[0] = point4(0.0f, -10.0f, 0.0f, 1.0f);
	_points[1] = point4(-5.0f, 0.0f, 0.0f, 1.0f);
	_points[2] = point4(5.0f, 0.0f, 0.0f, 1.0f);
	_points[3] = point4(-5.0f, 0.0f, 0.0f, 1.0f);
	_points[4] = point4(-17.0f, 5.0f, 0.0f, 1.0f);
	_points[5] = point4(-5.0f, 10.0f, 0.0f, 1.0f);
	_points[6] = point4(-5.0f, 10.0f, 0.0f, 1.0f);
	_points[7] = point4(0.0f, 20.0f, 0.0f, 1.0f);
	_points[8] = point4(5.0f, 10.0f, 0.0f, 1.0f);
	_points[9] = point4(5.0f, 10.0f, 0.0f, 1.0f);
	_points[10] = point4(17.0f, 5.0f, 0.0f, 1.0f);
	_points[11] = point4(5.0f, 0.0f, 0.0f, 1.0f);
	_points[12] = point4(-5.0f, 0.0f, 0.0f, 1.0f);
	_points[13] = point4(-5.0f, 10.0f, 0.0f, 1.0f);
	_points[14] = point4(5.0f, 10.0f, 0.0f, 1.0f);
	_points[15] = point4(5.0f, 0.0f, 0.0f, 1.0f);
	_points[16] = point4(-5.0f, 0.0f, 0.0f, 1.0f);
	_points[17] = point4(5.0f, 10.0f, 0.0f, 1.0f);
	_colors[0] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[1] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[2] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[3] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[4] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[5] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[6] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[7] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[8] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[9] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[10] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[11] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[12] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[13] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[14] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[15] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[16] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[17] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	poolParent = NULL;
	transform = new Transform();
	transform->Init(_points, _colors, STAR_NUM, matModelView, matProjection, shaderHandle);
	this->speed = speed;
	this->rotateSpeed = rotateSpeed;
	this->bRotateClockWise = bRotateClockWise;
}

Star::~Star(){
	if (transform != NULL)delete transform;
}

Star::Star(const Star& s){
	memcpy(_points, s._points, sizeof(s._points));
	memcpy(_colors, s._colors, sizeof(s._colors));
	speed = s.speed;
	rotateSpeed = s.rotateSpeed;
	bRotateClockWise = s.bRotateClockWise;
	poolParent = s.poolParent;
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TOFIX:CHECK IF THIS RIGHT WAY
	transform = new Transform(*s.transform);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

const Star& Star::operator=(const Star& s){
	if (&s != this) {
		if (transform != NULL)delete transform;
		memcpy(_points, s._points, sizeof(s._points));
		memcpy(_colors, s._colors, sizeof(s._colors));
		speed = s.speed;
		rotateSpeed = s.rotateSpeed;
		bRotateClockWise = s.bRotateClockWise;
		poolParent = s.poolParent;
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//TOFIX:CHECK IF THIS RIGHT WAY
		transform = new Transform(*s.transform);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	return *this;
}

void Star::Draw(){
	transform->Draw();
}

void Star::Update(float delta){
	this->transform->position.y += speed * delta;
	AutoRotation(delta);
	if (transform->position.y >= HEIGHT || transform->position.y <= 0.0f)
		poolParent->Recycle(this);
}

void Star::Init(vec3 position){
	this->transform->position = position;
}


void Star::Init(vec3 position, float speed, vec3 scale){
	this->speed = speed;
	this->transform->position = position;
	this->transform->scale = scale;
}

void Star::SetColor(vec4 color){
	this->transform->SetColor(color);
}

void Star::SetRotation(float speed, bool IsRotateClockwise){
	this->rotateSpeed = speed;
	this->bRotateClockWise = IsRotateClockwise;
}

void Star::AutoRotation(float delta){
	if (bRotateClockWise)
		this->transform->rotation.z += rotateSpeed * delta;
	else
		this->transform->rotation.z -= rotateSpeed * delta;
}

