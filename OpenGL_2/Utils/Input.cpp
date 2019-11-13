#include "Input.h"
Input::Input()
{
	keyPressed = 0;
	bKeyPressed = false;
	bLeftPressed = false;
	bRightPressed = false;
	mouseX = 0;
	mouseY = 0;
}

Input::~Input(){
}

bool Input::IsGetKey(int key) {
	if (bKeyPressed && key == keyPressed)
		return true;
	return false;
}

bool Input::IsGetMouse(int mouse){
	if (mouse == LEFT_MOUSE)
		return bLeftPressed;
	else if (mouse == RIGHT_MOUSE)
		return bRightPressed;
	return false;
}

void Input::KeyPressed(int key){
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//Special Key are the same value with normal key
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	keyPressed = key;
	bKeyPressed = true;
}

void Input::MousePressed(int button, int state, int x, int y){
	if (button == LEFT_MOUSE) {
		if (state == MOUSE_PRESSED)bLeftPressed = true;
		else if (state == MOUSE_RELEASE)bLeftPressed = false;
	}
	else if (button == RIGHT_MOUSE) {
		if (state == MOUSE_PRESSED)bRightPressed = true;
		else if (state == MOUSE_RELEASE)bRightPressed = false;
	}
	this->mouseX = x;
	this->mouseY = y;
}

void Input::MouseMove(int x, int y){
	this->mouseX = x;
	this->mouseY = y;
}

void Input::Update(){
	bKeyPressed = false;
}

