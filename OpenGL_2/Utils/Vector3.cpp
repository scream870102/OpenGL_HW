#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::~Vector3()
{
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator=(const Vector3* b)
{
	this->x = b->x;
	this->y = b->y;
	this->z = b->z;
	return Vector3(x,y,z);
}

Vector3 Vector3::operator+(const Vector3* b)
{
	this->x = x + b->x;
	this->y = y + b->y;
	this->z = z + b->z;
	return Vector3(x,y,z);
}

Vector3 Vector3::operator-(const Vector3* b)
{
	this->x = x - b->x;
	this->y = y - b->y;
	this->z = z - b->z;
	return Vector3(x,y,z);
}

Vector3 Vector3::operator*(const float& b)
{
	if (b != 0.0f) {
		this->x = x * b;
		this->y = y * b;
		this->z = z * b;
	}
	return Vector3(x,y,z);
}

Vector3 Vector3::operator/(const float& b)
{
	if (b != 0.0f) {
		this->x = x / b;
		this->y = y / b;
		this->z = z / b;
	}
	return Vector3(x,y,z);
}


