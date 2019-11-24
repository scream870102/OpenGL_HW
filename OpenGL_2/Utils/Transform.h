#pragma once

#include "../Header/Angel.h"
#include "../Utils/Mathf.h"
#include <vector>
typedef std::vector<vec4> vPoint4;
typedef std::vector<vec4> vColor4;
typedef Angel::vec4 color4;
typedef Angel::vec4 point4;
#define WIDTH 450
#define HEIGHT 800
#define NONE 0
#define PLAYER 1
#define ENEMY 2
class Transform {
private:
	GLuint _vao;
	GLuint _vbo;
	GLuint _modelView, _projection;
	GLuint _program;
	mat4 _matView, _matProjection;
	mat4 _matMVFinal, _matTRS;
	bool _bUpdateProj;

public:
	vec3 position;
	vec3 rotation;
	vec3 scale;
	Transform* pParent;
	vPoint4 points;
	vColor4 colors;
private:
	void CreateBufferObject();
public:
	Transform();
	~Transform();
	Transform(const Transform& t);
	const Transform& operator=(const Transform& t);
	GLuint GetShaderHandle() { return _program; }
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	void SetViewMatrix(mat4& mat);
	void SetProjectionMatrix(mat4& mat);
	void SetColor(const GLfloat vColor[4]);
	void SetColor(const color4& vColor);
	void SetAlpha(float alpha);
	void SetColors(const std::vector<color4>& colors);
	const float GetAlpha()const;
	void Draw();
	void DrawW();
	void Init(point4 ps[], color4 cs[], int num, mat4 matView, mat4 matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	mat4 GetTRSMat();
	const vec3 GetGlobalPosition();

};