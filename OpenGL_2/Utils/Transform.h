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
	GLuint _modelView, _projection;
	GLuint _program;
	mat4 _matView, _matProjection;
	mat4 _matMVFinal, _matTRS;
	bool _bUpdateProj;
	void CreateBufferObject();
public:
	vec3 position;
	vec3 rotation;
	vec3 scale;
	Transform* pParent;
	vPoint4 points;
	vColor4 colors;
	Transform(const Transform& t);
	Transform();
	~Transform();
	GLuint GetShaderHandle() { return _program; }
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	void SetViewMatrix(mat4& mat);
	void SetProjectionMatrix(mat4& mat);
	void SetColor(GLfloat vColor[4]);
	void SetColor(color4 vColor);
	void Draw();
	void DrawW();
	void Init(point4 ps[], color4 cs[], int num, mat4 matView, mat4 matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	mat4 GetTRSMat();
};