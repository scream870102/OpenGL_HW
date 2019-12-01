#pragma once
#include "State.h"
#include "../../Bullet/BulletPool.h"
#define B_SGS_HZ 200
#define B_SHOUT_GUN_NUM 5
#define B_SHOUT_GUN_OFFSET 20.0f
#define B_SHOT_GUN_SPEED 250.0f
#define B_SHOT_GUN_ROT_VEL -250.0f
class Boss;
class ShotGunState : public State
{
private:
	Boss* pBoss;
	CountDownTimer* shotTimer;
public:
private:
protected:
	void InitAction() override;
	void Action(float delta)override;
public:
	ShotGunState(Boss* boss = NULL, int actionTime = 0, int cd = 0, Transform* transform = NULL);
	~ShotGunState();
};