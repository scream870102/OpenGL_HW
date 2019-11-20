#pragma once
#define MAX_KEY_NUM 120
#define MOUSE_PRESSED 0
#define MOUSE_RELEASE 1
#define LEFT_MOUSE 0
#define RIGHT_MOUSE 2
#include <stdio.h>
#include "../Header/Angel.h"
class Input
{
public:
	Input();
	~Input();
	int mouseX;
	int mouseY;
	bool IsGetKey(int key);
	bool IsGetMouse(int mouse);
	void	KeyPressed(int key);
	void MousePressed(int button, int state, int x, int y);
	void MouseMove(int x, int y);
	void Update();
private:
	bool bKeyPressed;
	int keyPressed;
	bool bLeftPressed;
	bool bRightPressed;
};


