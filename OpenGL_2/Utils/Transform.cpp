#include "Transform.h"

Transform::Transform(const Transform& t) {
	position = t.position;
	rotation = t.rotation;
	scale = t.scale;
	points = vPoint4(t.points.begin(), t.points.end());
	colors = vColor4(t.colors.begin(), t.colors.end());
}

Transform::Transform() {
	position = vec3(0.0f);
	rotation = vec3(0.0f);
	scale = vec3(1.0f);
	points.clear();
	colors.clear();
	_modelView = 0;
	_program = 0;
	_projection = 0;
	_vao = 0;
	_vbo = 0;
	//bUpdateMV = false;
	bUpdateProj = false;
}

Transform::~Transform() {
	points.clear();
	colors.clear();
}

Transform Transform::operator=(const Transform& t) {
	this->position = t.position;
	this->rotation = t.rotation;
	this->scale = t.scale;
	return *this;
}


void Transform::CreateBufferObject() {
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	// Create and initialize a buffer object

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points) * points.size() + sizeof(colors) * colors.size(), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points) * points.size(), &points[0]);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) * points.size(), sizeof(colors) * colors.size(), &colors[0]);
}

void Transform::UpdateTRS()
{
	mat4 trsMat;
	trsMat = Translate(position);
	trsMat *= RotateZ(rotation.z);
	trsMat *= Scale(scale);
	_matTRS = trsMat;
	//this->SetTRSMatrix(trsMat);
}

void Transform::SetShader(mat4& mxView, mat4& mxProjection, GLuint uiShaderHandle) {
	// Load shaders and use the resulting shader program
	if (uiShaderHandle == MAX_UNSIGNED_INT) _program = InitShader("vsVtxColor.glsl", "fsVtxColor.glsl");
	else _program = uiShaderHandle;

	// set up vertex arrays
	GLuint vPosition = glGetAttribLocation(_program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	GLuint vColor = glGetAttribLocation(_program, "vColor");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(points) * points.size()));

	_modelView = glGetUniformLocation(_program, "ModelView");
	_matView = mxView;
	glUniformMatrix4fv(_modelView, 1, GL_TRUE, _matView);

	_projection = glGetUniformLocation(_program, "Projection");
	_matProjection = mxProjection;
	glUniformMatrix4fv(_projection, 1, GL_TRUE, _matProjection);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Transform::SetViewMatrix(mat4& mat) {
	_matView = mat;
	//bUpdateMV = true;
}

void Transform::SetProjectionMatrix(mat4& mat) {
	_matProjection = mat;
	bUpdateProj = true;
}

//void Transform::SetTRSMatrix(mat4& mat) {
//	_matTRS = mat;
//	//bUpdateMV = true;
//}

void Transform::SetColor(GLfloat vColor[4]) {
	for (int i = 0; i < colors.size(); i++) {
		colors[i].x = vColor[0];
		colors[i].y = vColor[1];
		colors[i].z = vColor[2];
		colors[i].w = vColor[3];
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) * points.size(), sizeof(colors) * colors.size(), &colors[0]);
}

void Transform::SetColor(color4 vColor)
{
	for (int i = 0; i < colors.size(); i++) {
		colors[i].x = vColor.x;
		colors[i].y = vColor.y;
		colors[i].z = vColor.z;
		colors[i].w = vColor.w;
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) * points.size(), sizeof(colors) * colors.size(), &colors[0]);
}

void Transform::Draw() {
	glUseProgram(_vbo);
	glBindVertexArray(_vao);
	//if (bUpdateMV) {
	UpdateTRS();
	_matMVFinal = _matView * _matTRS;
	//bUpdateMV = false;
	//}
	glUniformMatrix4fv(_modelView, 1, GL_TRUE, _matMVFinal);

	if (bUpdateProj) {
		glUniformMatrix4fv(_projection, 1, GL_TRUE, _matProjection);
		bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, points.size());
}

void Transform::DrawW() {
	glBindVertexArray(_vao);

	//if (bUpdateMV) {
	_matMVFinal = _matView * _matTRS;
	//	bUpdateMV = false;
	//}

	glUniformMatrix4fv(_modelView, 1, GL_TRUE, _matMVFinal);
	if (bUpdateProj) {
		glUniformMatrix4fv(_projection, 1, GL_TRUE, _matProjection);
		bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, points.size());
}

void Transform::Init(point4 ps[], color4 cs[], int num)
{
	int c = sizeof(*cs) * num / sizeof(cs[0]);
	colors = vColor4(cs, cs + c);
	int p = sizeof(*ps) * num / sizeof(ps[0]);
	points = vPoint4(ps, ps + p);
	CreateBufferObject();
	bUpdateProj = false;
}

