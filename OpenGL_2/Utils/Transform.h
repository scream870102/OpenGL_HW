//#pragma once
//#include "../Header/vec.h"
////class Transform
////{
////public:
////	Transform();
////	~Transform();
////	vec3 position;
////	vec3 rotation;
////	vec3 scale;
////};
////struct Transform
////{
////	vec3 position;
////	vec3 rotation;
////	vec3 scale;
////};


#include "../Header/vec.h"
struct Transform
{
	vec3 position;
	vec3 rotation;
	vec3 scale;
	Transform(const Transform& t);
	Transform();
};