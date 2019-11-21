#pragma once
#include "../Header/Angel.h"
class CountDownTimer
{
public:
	CountDownTimer(int CD = 0.0f);
	~CountDownTimer();
	void Init(int CD);
	bool IsFinished();
	void Reset();
	void Reset(int newCD);

private:
	int time;
	int CD;
};

