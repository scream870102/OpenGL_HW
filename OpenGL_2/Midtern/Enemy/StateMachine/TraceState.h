#pragma once
#include "State.h"
#include "../../Bullet/BulletPool.h"
#define HZ 150
#define B_TRACE_SPEED 500
#define B_TRACE_TIME 1500
#define B_TS_ROT_VEL -1500.0f
class Boss;
class TraceState : public State
{
private:
	CountDownTimer* shootTimer;
	Boss* pBoss;
public:
private:
protected:
	void InitAction() override;
	void Action(float delta)override;
public:
	TraceState(Boss* boss = NULL, int actionTime = 0, int cd = 0, Transform* transform = NULL);
	~TraceState();
};