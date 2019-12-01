#include "ParallelState.h"
#include "../Boss.h"

void ParellelState::InitAction() {
	shotTimer->Reset();
	bOffset = Random::GetRandBool();
}

void ParellelState::Action(float delta) {
	float z = pBoss->transform->rotation.z+B_PS_ROT_VEL*delta;
	z = Mathf::Clamp(z, 360.0f);
	pBoss->transform->rotation.z = z;
	if (shotTimer->IsFinished()) {
		shotTimer->Reset();
		int xOffset = (WIDTH - B_PS_X_OFFSET) / B_PARALLEL_NUM;
		for (int i = 0; i < B_PARALLEL_NUM; i++) {
			int xPos = B_PS_X_OFFSET + xOffset * (bOffset ? i : i + 1);
			vec3 startPos = vec3(xPos, transform->position.y, 0.0f);
			BulletPool::GetInstance()->Fire(ENEMY, startPos, vec3(0.0f, 1.0f, 0.0f), B_PARALLEL_SPEED, pBoss->damage);

		}
	}
}

ParellelState::ParellelState(Boss* boss, int actionTime, int cd, Transform* transform) :State(actionTime, cd, transform) {
	shotTimer = new CountDownTimer(B_PS_HZ);
	pBoss = boss;
	bOffset = false;
}

ParellelState::~ParellelState() {
	if (shotTimer != NULL)delete shotTimer;
}
