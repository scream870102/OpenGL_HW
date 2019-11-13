#pragma once
#include "../Header/Angel.h"
#include "Player.h"
class MainScene
{
public:
	MainScene();
	~MainScene();
	void Update(float delta);
	Player* pPlayer;
	// For input callback
	void OnWinKeyboard(unsigned char key, int x, int y);
	void Draw();
private:
	// For Model View and Projection Matrix
	mat4 matModelView;
	mat4 matProjection;
	
	

};