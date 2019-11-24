#pragma once
#include "SceneObject/Background.h"
#include "CharacterController.h"
#include "SceneObject/SmokePool.h"
#include <vector>
#define MAX_BULLET_NUM 100
#define MAX_SMOKE_NUM 200
#define MAX_BG_NUM 50
#define MAX_ENEMY_NUM 3
#define ENEMY_NUM_TO_KILL 10
class MainScene
{
private:
	// For Model View and Projection Matrix
	mat4 matModelView;
	mat4 matProjection;
	Input input;
	BulletPool* pBulletPool;
	SmokePool* pSmokePool;
	Background* pBg;
	CharacterController* pCc;
public:
private:
public:
	void Update(float delta);
	void Draw();
	MainScene();
	~MainScene();
	//!!!!!!!!!!!!!!!!!!!!!!!
	//NEED TO OVERRIDE = OPERATOR AND COPY CONSTRUCTOR
	//!!!!!!!!!!!!!!!!!!!!!!
	// For input callback
	void OnWinKeyboard(unsigned char key, int x, int y);
	void OnWinSpecialKeyboard(int key, int x, int y);
	void OnWinMouse(int button, int state, int x, int y);
	void OnWinPassiveMouse(int x, int y);
};