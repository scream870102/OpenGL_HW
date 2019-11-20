#pragma once
#include "../Utils/Input.h"
#include "Bullet.h"
#define PLAYER_NUM 27
#define BULLETS_NUM 10
class Player {
private:
	const int P_NUM = PLAYER_NUM;
	point4 _points[PLAYER_NUM];
	color4 _colors[PLAYER_NUM];
	ObjectPool<Bullet> _bulletPool;
	std::vector<Bullet*> _currentBullets;
public:
	//only the pointer for outer input class
	Input* input;
	Transform* transform;
	Player(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Player();
	Player(const Player& p);
	void SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	void Draw();
	void Update(float delta);

};