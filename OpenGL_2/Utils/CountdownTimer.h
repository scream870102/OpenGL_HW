#pragma once
#include "../Header/Angel.h"
class CountDownTimer
{
private:
	int time;
	int CD;
public:
private:
public:
	CountDownTimer(int CD = 0.0f);
	~CountDownTimer();
	void Init(int CD);
	bool IsFinished();
	void Reset();
	void Reset(int newCD);
};

