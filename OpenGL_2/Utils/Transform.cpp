//#include"Transform.h"
//Transform::Transform()
//{
//	position = vec3();
//	rotation = vec3();
//	scale = vec3();
//}
//
//Transform::~Transform()
//{
//	position = NULL;
//	rotation = NULL;
//	scale = NULL;
//}
#include "../Header/vec.h"
#include "Transform.h"
struct Transform
{
	vec3 position;
	vec3 rotation;
	vec3 scale;
	Transform(const Transform& t) { position = t.position; rotation = t.rotation; scale = t.scale; }
	Transform() { position = vec3(); rotation = vec3(); scale = vec3(); }
};

