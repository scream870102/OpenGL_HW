#include "TraceState.h"
#include "../Boss.h"
void TraceState::Action(float delta) {
	float z = pBoss->transform->rotation.z + B_TS_ROT_VEL * delta;
	z = Mathf::Clamp(z, 360.0f);
	pBoss->transform->rotation.z = z;
	if (shootTimer->IsFinished()) {
		BulletPool::GetInstance()->Fire(ENEMY, transform->GetGlobalPosition(), vec3(), B_TRACE_SPEED,pBoss->damage,pBoss->pPlayer->transform, B_TRACE_TIME);
		shootTimer->Reset();
	}
}

void TraceState::InitAction() {
	shootTimer->Reset();
}

TraceState::TraceState(Boss* boss, int actionTime, int cd, Transform* transform) :State(actionTime, cd, transform) {
	shootTimer = new CountDownTimer(HZ);
	this->pBoss = boss;
}

TraceState::~TraceState() {
	if (shootTimer != NULL)delete shootTimer;
}
