#include "Transform.h"

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
}

void Transform::SetProjectionMatrix(mat4& mat) {
	_matProjection = mat;
	_bUpdateProj = true;
}

void Transform::SetColor(const GLfloat vColor[4]) {
	for (int i = 0; i < (int)colors.size(); i++) {
		colors[i].x = vColor[0];
		colors[i].y = vColor[1];
		colors[i].z = vColor[2];
		colors[i].w = vColor[3];
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) * points.size(), sizeof(colors) * colors.size(), &colors[0]);
}

void Transform::SetColor(const color4& vColor) {
	for (int i = 0; i < (int)colors.size(); i++) {
		colors[i] = vColor;
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) * points.size(), sizeof(colors) * colors.size(), &colors[0]);
}

void Transform::SetAlpha(float alpha) {
	float newA = Mathf::Clamp(alpha, 1.0f);
	for (int i = 0; i < (int)colors.size(); i++) {
		colors[i].w = newA;
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) * points.size(), sizeof(colors) * colors.size(), &colors[0]);
}

void Transform::SetColors(const std::vector<color4>& refColor) {
	if ((int)refColor.size() >= (int)this->colors.size()) {
		for (int i = 0; i < (int)colors.size(); i++) {
			colors[i] = refColor[i];
		}
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferSubData(GL_ARRAY_BUFFER, sizeof(points) * points.size(), sizeof(colors) * colors.size(), &colors[0]);
	}

}

const float Transform::GetAlpha() const {
	return colors[0].w;
}

void Transform::Draw() {
	glUseProgram(_vbo);
	glBindVertexArray(_vao);
	_matTRS = GetTRSMat();
	_matMVFinal = _matView * _matTRS;
	glUniformMatrix4fv(_modelView, 1, GL_TRUE, _matMVFinal);

	if (_bUpdateProj) {
		glUniformMatrix4fv(_projection, 1, GL_TRUE, _matProjection);
		_bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, points.size());
}

void Transform::DrawW() {
	glBindVertexArray(_vao);
	_matTRS = GetTRSMat();
	_matMVFinal = _matView * _matTRS;

	glUniformMatrix4fv(_modelView, 1, GL_TRUE, _matMVFinal);
	if (_bUpdateProj) {
		glUniformMatrix4fv(_projection, 1, GL_TRUE, _matProjection);
		_bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, points.size());
}

void Transform::Init(point4 ps[], color4 cs[], int num, mat4 matView, mat4 matProjection, GLuint shaderHandle) {
	int c = sizeof(*cs) * num / sizeof(cs[0]);
	colors = vColor4(cs, cs + c);
	int p = sizeof(*ps) * num / sizeof(ps[0]);
	points = vPoint4(ps, ps + p);
	CreateBufferObject();
	_bUpdateProj = false;
	SetShader(matView, matProjection, shaderHandle);
}

mat4 Transform::GetTRSMat() {
	mat4 trsMat;
	if (pParent != NULL)
		trsMat = pParent->GetTRSMat();

	trsMat *= Translate(position);
	trsMat *= RotateZ(rotation.z);
	trsMat *= Scale(scale);

	return trsMat;
}

const vec3 Transform::GetGlobalPosition() {
	mat4 mat = GetTRSMat();
	return vec3(mat[0][3], mat[1][3], mat[2][3]);
}

Transform::Transform() {
	_vao = 0;
	_vbo = 0;
	_modelView = 0;
	_projection = 0;
	_program = 0;
	_matView = mat4();
	_matProjection = mat4();
	_matMVFinal = mat4();
	_matTRS = mat4();
	_bUpdateProj = false;
	position = vec3(0.0f);
	rotation = vec3(0.0f);
	scale = vec3(1.0f);
	pParent = NULL;
	points.clear();
	colors.clear();
}

Transform::~Transform() {
	if (points.size() != 0)points.clear();
	if (colors.size() != 0)colors.clear();
}

Transform::Transform(const Transform& t) {
	_matView = t._matView;
	_matProjection = t._matProjection;
	_bUpdateProj = t._bUpdateProj;
	position = t.position;
	rotation = t.rotation;
	scale = t.scale;
	pParent = t.pParent;
	points = vPoint4(t.points.begin(), t.points.end());
	colors = vColor4(t.colors.begin(), t.colors.end());
	Init(&points[0], &colors[0], (int)points.size(), _matView, _matProjection);
}

const Transform& Transform::operator=(const Transform& t) {
	if (&t != this) {
		if (points.size() != 0)points.clear();
		if (colors.size() != 0)colors.clear();
		_matView = t._matView;
		_matProjection = t._matProjection;
		_bUpdateProj = t._bUpdateProj;
		position = t.position;
		rotation = t.rotation;
		scale = t.scale;
		pParent = t.pParent;
		points = vPoint4(t.points.begin(), t.points.end());
		colors = vColor4(t.colors.begin(), t.colors.end());
		Init(&points[0], &colors[0], (int)points.size(), _matView, _matProjection);
	}
	return *this;
}

