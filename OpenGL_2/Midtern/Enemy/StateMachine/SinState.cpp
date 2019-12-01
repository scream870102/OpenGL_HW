#include "SinState.h"
#include "../Boss.h"
#include <math.h>
void SinState::InitAction() {
	timeAcm = 0.0f;
}

void SinState::Action(float delta) {
	float z = pBoss->transform->rotation.z + B_SS_ROT_VEL * delta;
	z = Mathf::Clamp(z, 360.0f);
	pBoss->transform->rotation.z = z;
	timeAcm += delta;
	if (shotTimer->IsFinished()) {
		shotTimer->Reset();
		float degree = B_SIN_OFFSET + (180.0f - B_SIN_OFFSET * 2.0f) * abs(sinf(timeAcm));
		vec3 direction = Angel::normalize(Mathf::ConvertToVec3FromDeg(degree));
		BulletPool::GetInstance()->Fire(ENEMY, transform->GetGlobalPosition(), direction, B_SHOT_GUN_SPEED, pBoss->damage);
	}
}

SinState::SinState(Boss* boss, int actionTime, int cd, Transform* transform) :State(actionTime, cd, transform) {
	shotTimer = new CountDownTimer(B_SS_HZ);
	pBoss = boss;
	timeAcm = 0.0f;
}

SinState::~SinState() {
	if (shotTimer != NULL)delete shotTimer;
}
