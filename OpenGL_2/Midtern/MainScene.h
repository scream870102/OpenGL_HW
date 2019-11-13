#pragma once
#include "../Header/Angel.h"
#include "Player.h"
//For move
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
//For rotation
#define Q_KEY 113
#define E_KEY 101
//For Scale
#define J_KEY 106
#define K_KEY 107
//Function Key
#define ESC_KEY 33
#define SPACE_KEY 32
#define R_KEY 72
class MainScene
{
public:
	MainScene();
	~MainScene();
	void Update(float delta);
	Player* pPlayer;
	// For input callback
	void OnWinKeyboard(unsigned char key, int x, int y);
	void OnWinSpecialKeyboard(int key, int x, int y);
	void OnWinMouse(int button, int state, int x, int y);
	void Draw();
private:
	// For Model View and Projection Matrix
	mat4 matModelView;
	mat4 matProjection;
	
	

};