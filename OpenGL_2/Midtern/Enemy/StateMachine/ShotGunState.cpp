#include "ShotGunState.h"
#include "../Boss.h"
void ShotGunState::InitAction() {
	shotTimer->Reset();
}

void ShotGunState::Action(float delta) {
	float z = pBoss->transform->rotation.z + B_SHOT_GUN_ROT_VEL * delta;
	z = Mathf::Clamp(z, 360.0f);
	pBoss->transform->rotation.z = z;
	if (shotTimer->IsFinished()) {
		shotTimer->Reset();
		//shot bullets
		float offset = (180.0f - B_SHOUT_GUN_OFFSET * (B_SHOUT_GUN_NUM - 1)) / 2.0f;
		for (int i = 0; i < B_SHOUT_GUN_NUM; i++) {
			float degree = i * B_SHOUT_GUN_OFFSET + offset;
			vec3 direction = Angel::normalize(Mathf::ConvertToVec3FromDeg(degree));
			BulletPool::GetInstance()->Fire(ENEMY, transform->GetGlobalPosition(), direction, B_SHOT_GUN_SPEED, pBoss->damage);
		}
	}
}

ShotGunState::ShotGunState(Boss* boss, int actionTime, int cd, Transform* transform) :State(actionTime, cd, transform) {
	shotTimer = new CountDownTimer(B_SGS_HZ);
	pBoss = boss;
}

ShotGunState::~ShotGunState() {
	if (shotTimer != NULL)delete shotTimer;
}
