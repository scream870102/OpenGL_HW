#pragma once
#include "State.h"
#include "../../Bullet/BulletPool.h"
class Boss;
#define B_PS_HZ 200
#define B_PARALLEL_NUM 4
#define B_PARALLEL_SPEED 400.0f
#define B_PS_X_OFFSET WIDTH/9
#define B_PS_ROT_VEL 800.0f
class ParellelState : public State
{
private:
	Boss* pBoss;
	CountDownTimer* shotTimer;
	bool bOffset;
public:
private:
protected:
	void InitAction() override;
	void Action(float delta)override;
public:
	ParellelState(Boss* boss = NULL, int actionTime = 0, int cd = 0, Transform* transform = NULL);
	~ParellelState();
};