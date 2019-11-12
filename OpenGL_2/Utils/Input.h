#pragma once
#define MAX_KEY_NUM 120
enum class KeyCode
{
	w = 119,
	a = 97,
	s = 115,
	d = 100,
	q = 113,
	e = 101,
	j = 106,
	k = 107,
	r = 72,
	esc = 33,
	space = 32,
};
class Input
{
public:
	Input();
	~Input();
	bool GetKey(KeyCode key);
	void UpdateKey(int key);
	void Reset();
	int keyPress[MAX_KEY_NUM]={0};
private:

};


