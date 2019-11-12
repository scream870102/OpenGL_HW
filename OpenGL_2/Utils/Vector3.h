#pragma once
class Vector3
{
public:
	Vector3();
	~Vector3();
	Vector3(float x, float y, float z);
	float x;
	float y;
	float z;
	Vector3 operator =(const Vector3* b);
	Vector3 operator +(const Vector3* b);
	Vector3 operator -(const Vector3* b);
	Vector3 operator *(const float& b);
	Vector3 operator /(const float& b);
private:

};