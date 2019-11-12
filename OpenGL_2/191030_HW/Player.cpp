#include "Player.h"
Player::Player() {
	//_points[0] = point4(-0.0f, -18.0f, 0.0f, 1.0f);
	//_points[1] = point4(-17.0f, 19.0f, 0.0f, 1.0f);
	//_points[2] = point4(0.0f, 10.0f, 0.0f, 1.0f);
	//_points[3] = point4(0.0f, 10.0f, 0.0f, 1.0f);
	//_points[4] = point4(17.0f, 19.0f, 0.0f, 1.0f);
	//_points[5] = point4(-0.0f, -18.0f, 0.0f, 1.0f);
	//_colors[0] = color4(1.0f, 1.0f, 1.0f, 1.0f);  // (r, g, b, a)
	//_colors[1] = color4(1.0f, 0.0f, 0.0f, 1.0f);
	//_colors[2] = color4(.0f, 1.0f, 0.0f, 1.0f);
	//_colors[3] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	//_colors[4] = color4(0.0f, 1.0f, 0.0f, 1.0f);
	//_colors[5] = color4(0.0f, 0.0f, 1.0f, 1.0f);
	_points[0] = point4(0.0f, -30.0f, 0.0f, 1.0f);
	_points[1] = point4(-10.0f, -12.0f, 0.0f, 1.0f);
	_points[2] = point4(10.0f, -12.0f, 0.0f, 1.0f);
	_points[3] = point4(-51.0f, -13.0f, 0.0f, 1.0f);
	_points[4] = point4(-36.0f, 12.0f, 0.0f, 1.0f);
	_points[5] = point4(0.0f, 15.0f, 0.0f, 1.0f);
	_points[6] = point4(7.0f, 20.0f, 0.0f, 1.0f);
	_points[7] = point4(-7.0f, 20.0f, 0.0f, 1.0f);
	_points[8] = point4(0.0f, 53.0f, 0.0f, 1.0f);
	_points[9] = point4(0.0f, 15.0f, 0.0f, 1.0f);
	_points[10] = point4(51.0f, -13.0f, 0.0f, 1.0f);
	_points[11] = point4(36.0f, 12.0f, 0.0f, 1.0f);
	_points[12] = point4(-39.0f, -13.0f, 0.0f, 1.0f);
	_points[13] = point4(-14.0f, -10.0f, 0.0f, 1.0f);
	_points[14] = point4(0.0f, 12.0f, 0.0f, 1.0f);
	_points[15] = point4(13.0f, -10.0f, 0.0f, 1.0f);
	_points[16] = point4(39.0f, -13.0f, 0.0f, 1.0f);
	_points[17] = point4(0.0f, 12.0f, 0.0f, 1.0f);
	_points[18] = point4(10.0f, 20.0f, 0.0f, 1.0f);
	_points[19] = point4(29.0f, 66.0f, 0.0f, 1.0f);
	_points[20] = point4(2.0f, 56.0f, 0.0f, 1.0f);
	_points[21] = point4(-10.0f, -12.0f, 0.0f, 1.0f);
	_points[22] = point4(10.0f, -12.0f, 0.0f, 1.0f);
	_points[23] = point4(0.0f, 6.0f, 0.0f, 1.0f);
	_points[24] = point4(-29.0f, 66.0f, 0.0f, 1.0f);
	_points[25] = point4(-10.0f, 20.0f, 0.0f, 1.0f);
	_points[26] = point4(-2.0f, 56.0f, 0.0f, 1.0f);
	_colors[0] = color4(0.9099312546088323f, 0.8658456441194392f, 0.7637422342385652f, 1.0f);
	_colors[1] = color4(0.9811738639902003f, 0.7595056032531191f, 0.8024661498270882f, 1.0f);
	_colors[2] = color4(0.8587138231316165f, 0.8981577870381722f, 0.7628545893718714f, 1.0f);
	_colors[3] = color4(0.9879270534648469f, 0.8473888249213098f, 0.808741175754832f, 1.0f);
	_colors[4] = color4(0.9507417675972624f, 0.89705567474343f, 0.9230607582059067f, 1.0f);
	_colors[5] = color4(0.9443259988096081f, 0.8058041574736291f, 0.9841460641336566f, 1.0f);
	_colors[6] = color4(0.8491486747944369f, 0.7783093786941417f, 0.8291182143995542f, 1.0f);
	_colors[7] = color4(0.8492372271614717f, 0.9852722932938801f, 0.9661979715530267f, 1.0f);
	_colors[8] = color4(0.8026653677408511f, 0.7534817306439753f, 0.943156683799408f, 1.0f);
	_colors[9] = color4(0.8713044338915821f, 0.8650116194830613f, 0.9415218567246679f, 1.0f);
	_colors[10] = color4(0.9337346701780015f, 0.8996899422510214f, 0.887667524431818f, 1.0f);
	_colors[11] = color4(0.7518518846736804f, 0.862707774196625f, 0.9684532234277026f, 1.0f);
	_colors[12] = color4(0.8806562315170136f, 0.9518831117648097f, 0.8665515681699674f, 1.0f);
	_colors[13] = color4(0.8786314911227235f, 0.8739787965879714f, 0.9015680865321072f, 1.0f);
	_colors[14] = color4(0.9914515202334456f, 0.9814394602364698f, 0.834627843467969f, 1.0f);
	_colors[15] = color4(0.8452444928752638f, 0.8970215752474888f, 0.9224395541413011f, 1.0f);
	_colors[16] = color4(0.8105516070954035f, 0.7897920981612175f, 0.932449079498953f, 1.0f);
	_colors[17] = color4(0.86004872562867f, 0.903483688978697f, 0.7897167185131739f, 1.0f);
	_colors[18] = color4(0.8007234759064085f, 0.9270034800444833f, 0.8103167049808927f, 1.0f);
	_colors[19] = color4(0.973595010581028f, 0.9378260873749149f, 0.8476533107586135f, 1.0f);
	_colors[20] = color4(0.7706991996650137f, 0.8608714352099041f, 0.9853247813525605f, 1.0f);
	_colors[21] = color4(0.7987424517246242f, 0.7690790128552953f, 0.8755979006220204f, 1.0f);
	_colors[22] = color4(0.9496810471878238f, 0.9577606009297338f, 0.8907229730634064f, 1.0f);
	_colors[23] = color4(0.8928003788161281f, 0.9612531841079072f, 0.9396544620662455f, 1.0f);
	_colors[24] = color4(0.8339279563742212f, 0.9029766440824398f, 0.9770839169051371f, 1.0f);
	_colors[25] = color4(0.956410196467498f, 0.9359492260520559f, 0.9526516267995727f, 1.0f);
	_colors[26] = color4(0.9595336435425172f, 0.8790594347152512f, 0.9377534316165966f, 1.0f);

	// Create and initialize a buffer object 
	CreateBufferObject();
	bUpdateProj = false;
}


void Player::CreateBufferObject() {
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	// Create and initialize a buffer object

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(_points) + sizeof(_colors), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(_points), _points);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(_points), sizeof(_colors), _colors);
}

void Player::SetShader(mat4& mxView, mat4& mxProjection, GLuint uiShaderHandle) {
	// Load shaders and use the resulting shader program
	if (uiShaderHandle == MAX_UNSIGNED_INT) _program = InitShader("vsVtxColor.glsl", "fsVtxColor.glsl");
	else _program = uiShaderHandle;

	// set up vertex arrays
	GLuint vPosition = glGetAttribLocation(_program, "vPosition");
	glEnableVertexAttribArray(vPosition);
	glVertexAttribPointer(vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	GLuint vColor = glGetAttribLocation(_program, "vColor");
	glEnableVertexAttribArray(vColor);
	glVertexAttribPointer(vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(_points)));

	_modelView = glGetUniformLocation(_program, "ModelView");
	_matView = mxView;
	glUniformMatrix4fv(_modelView, 1, GL_TRUE, _matView);

	_projection = glGetUniformLocation(_program, "Projection");
	_matProjection = mxProjection;
	glUniformMatrix4fv(_projection, 1, GL_TRUE, _matProjection);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Player::SetViewMatrix(mat4& mat) {
	_matView = mat;
	bUpdateMV = true;
}

void Player::SetProjectionMatrix(mat4& mat) {
	_matProjection = mat;
	bUpdateProj = true;
}

void Player::SetTRSMatrix(mat4& mat) {
	_matTRS = mat;
	bUpdateMV = true;
}

void Player::SetColor(GLfloat vColor[4]) {
	for (int i = 0; i < P_NUM; i++) {
		_colors[i].x = vColor[0];
		_colors[i].y = vColor[1];
		_colors[i].z = vColor[2];
		_colors[i].w = vColor[3];
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(_points), sizeof(_colors), _colors);
}

void Player::SetColor(color4 vColor)
{
	for (int i = 0; i < P_NUM; i++) {
		_colors[i].x = vColor.x;
		_colors[i].y = vColor.y;
		_colors[i].z = vColor.z;
		_colors[i].w = vColor.w;
	}
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(_points), sizeof(_colors), _colors);
}

void Player::Draw() {
	glUseProgram(_vbo);
	glBindVertexArray(_vao);
	if (bUpdateMV) {
		_matMVFinal = _matView * _matTRS;
		bUpdateMV = false;
	}
	glUniformMatrix4fv(_modelView, 1, GL_TRUE, _matMVFinal);

	if (bUpdateProj) {
		glUniformMatrix4fv(_projection, 1, GL_TRUE, _matProjection);
		bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, P_NUM);
}

void Player::DrawW() {
	glBindVertexArray(_vao);

	if (bUpdateMV) {
		_matMVFinal = _matView * _matTRS;
		bUpdateMV = false;
	}

	glUniformMatrix4fv(_modelView, 1, GL_TRUE, _matMVFinal);
	if (bUpdateProj) {
		glUniformMatrix4fv(_projection, 1, GL_TRUE, _matProjection);
		bUpdateProj = false;
	}
	glDrawArrays(GL_TRIANGLES, 0, P_NUM);
}
