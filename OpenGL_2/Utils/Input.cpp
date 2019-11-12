#include "Input.h"
#include <stdio.h>
Input::Input()
{
	Reset();
}

Input::~Input()
{
}



bool Input::GetKey(KeyCode key)
{

	bool result = keyPress[(int)key] == 0 ? false : true;
	if (result)printf_s("%d\n", key);
	Reset();
	return result;
}

void Input::UpdateKey(int key)
{
	Reset();
	if (key < MAX_KEY_NUM) {
		//printf_s("%c\n", key);
		keyPress[key] = 1;
	}
}

void Input::Reset()
{
	for (int i = 0; i < MAX_KEY_NUM; i++)
		keyPress[i] = 0;
}