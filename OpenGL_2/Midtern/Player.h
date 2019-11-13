#include "../Header/Angel.h"
#include "../Utils/Transform.h"
#define PLAYER_NUM 27
class Player {
private:
	Transform _transform;
	const int P_NUM = PLAYER_NUM;
	point4 _points[PLAYER_NUM];
	color4 _colors[PLAYER_NUM];
public:
	Player();
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	void SetTRSMatrix(mat4& mat);
	void Draw();

};