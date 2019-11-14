#include "Bullet.h"

Bullet::Bullet(mat4& matModelView, mat4& matProjection, GLuint shaderHandle ) {
	_points[0] = point4(0.0f, -22.0f, 0.0f, 1.0f);
	_points[1] = point4(-15.0f, 0.0f, 0.0f, 1.0f);
	_points[2] = point4(15.0f, 0.0f, 0.0f, 1.0f);
	_points[3] = point4(-15.0f, 0.0f, 0.0f, 1.0f);
	_points[4] = point4(15.0f, 0.0f, 0.0f, 1.0f);
	_points[5] = point4(0.0f, 22.0f, 0.0f, 1.0f);
	_colors[0] = color4(0.9872279228246539f, 0.8364391701289224f, 0.8083559619770144f, 1.0f);
	_colors[1] = color4(0.9100404722946842f, 0.8479726794163994f, 0.9841797298654561f, 1.0f);
	_colors[2] = color4(0.7791333360548004f, 0.9954438096148324f, 0.9120188658124543f, 1.0f);
	_colors[3] = color4(0.886823422135872f, 0.9171992229515382f, 0.99305950847159f, 1.0f);
	_colors[4] = color4(0.8321819282966201f, 0.9638891490868704f, 0.795982349360338f, 1.0f);
	_colors[5] = color4(0.9175100699955497f, 0.8732428871076069f, 0.8110669448209172f, 1.0f);
	Transform.Init(_points, _colors, BULLET_NUM,matModelView,matProjection,shaderHandle);
}

Bullet::~Bullet()
{
}

void Bullet::SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle){
	Transform.SetShader(matModelView, matProjection, shaderHandle);
}

void Bullet::Draw(){
	Transform.Draw();
}

void Bullet::Update(float delta){

}