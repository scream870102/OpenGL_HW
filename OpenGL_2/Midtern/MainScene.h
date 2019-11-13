#pragma once
#include "../Header/Angel.h"
#include "Player.h"
#include "../Utils/Input.h"
class MainScene
{
public:
	Player* pPlayer;
	void Update(float delta);
	void Draw();
	MainScene();
	~MainScene();
	// For input callback
	void OnWinKeyboard(unsigned char key, int x, int y);
	void OnWinSpecialKeyboard(int key, int x, int y);
	void OnWinMouse(int button, int state, int x, int y);
	void OnWinPassiveMouse(int x, int y);
	
private:
	// For Model View and Projection Matrix
	mat4 matModelView;
	mat4 matProjection;
	Input input;



};