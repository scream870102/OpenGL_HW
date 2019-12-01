#pragma once
#include "State.h"
#define B_SS_HZ 150
#define B_SIN_OFFSET 45.0f
#define B_SIN_SPEED 250.0f
#define B_SS_ROT_VEL 50.0f
class Boss;
class SinState :public State
{
private:
	Boss* pBoss;
	CountDownTimer* shotTimer;
	float timeAcm;
public:
private:
protected:
	void InitAction() override;
	void Action(float delta)override;
public:
	SinState(Boss* boss = NULL, int actionTime = 0, int cd = 0, Transform* transform = NULL);
	~SinState();
};
