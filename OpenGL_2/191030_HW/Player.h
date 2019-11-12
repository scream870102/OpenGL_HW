#include "../Header/Angel.h"

typedef Angel::vec4 color4;
typedef Angel::vec4 point4;
#define PLAYER_NUM 27
class Player {
private:
	const int P_NUM = PLAYER_NUM;
	point4 _points[PLAYER_NUM];
	color4 _colors[PLAYER_NUM];
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
	Player();
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	GLuint GetShaderHandle() { return _program; }
	void SetViewMatrix(mat4& mat);
	void SetProjectionMatrix(mat4& mat);
	void SetTRSMatrix(mat4& mat);
	void SetColor(GLfloat vColor[4]);
	void SetColor(color4 vColor);
	void Draw();
	void DrawW();
};