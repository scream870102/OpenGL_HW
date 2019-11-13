#include "../Header/Angel.h"
#include "../Utils/Transform.h"
#include "../Utils/Input.h"
#define PLAYER_NUM 27
class Player {
private:
	const int P_NUM = PLAYER_NUM;
	point4 _points[PLAYER_NUM];
	color4 _colors[PLAYER_NUM];
public:
	//only the pointer for outer input class
	Input* i;
	Transform Transform;
	Player();
	~Player();
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	void Draw();
	void Update(float delta);

};