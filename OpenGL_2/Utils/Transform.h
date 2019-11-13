#pragma once

#include "../Header/Angel.h"
#include <vector>
typedef std::vector<vec4> vPoint4;
typedef std::vector<vec4> vColor4;
typedef Angel::vec4 color4;
typedef Angel::vec4 point4;
class Transform {
private:
	GLuint _vao;
	GLuint _vbo;
	GLuint _program;
	GLuint _modelView, _projection;
	mat4 _matView, _matProjection;
	mat4 _matMVFinal, _matTRS;
	bool bUpdateMV;
	bool bUpdateProj;
	void CreateBufferObject();
public:
	vec3 position;
	vec3 rotation;
	vec3 scale;
	Transform(const Transform& t);
	Transform();
	~Transform();
	Transform operator =(const Transform& t);
	vPoint4 points;
	vColor4 colors;
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	GLuint GetShaderHandle() { return _program; }
	void SetViewMatrix(mat4& mat);
	void SetProjectionMatrix(mat4& mat);
	void SetTRSMatrix(mat4& mat);
	void SetColor(GLfloat vColor[4]);
	void SetColor(color4 vColor);
	void Draw();
	void DrawW();
	void Init(point4 ps[],color4 cs[],int num);
};