#include "State.h"
void State::Init(int actionTime, int cd, Transform* transform) {
	this->actionTime = actionTime;
	this->cd = cd;
	this->transform = transform;
	this->timer->Reset(cd);
	this->eState = STATE::CD;
}
// if cd state is already finished
bool State::IsReady() {
	if (eState == STATE::CD && timer->IsFinished())
		return true;
	else return false;
}
bool State::Update(float delta) {
	//ACTION STATE END
	//SET STATE TO CD AND RESET CD
	if (eState == STATE::ACTION && timer->IsFinished()) {
		eState = STATE::CD;
		timer->Reset(Random::GetRand(cd,cd/2));
		return true;
	}
	//Still in action state keep call action method
	else if (eState == STATE::ACTION && !timer->IsFinished()) {
		Action(delta);
		return false;
	}
	else
		return true;
}
void State::Action(float delta){}

void State::InitAction(){}

void State::StartAction(){
	eState = STATE::ACTION;
	timer->Reset(actionTime);
	InitAction();
}

State::State(int actionTime, int cd, Transform* transform) {
	timer = new CountDownTimer(cd,Random::GetRand(cd));
	this->actionTime = actionTime;
	this->cd = cd;
	this->transform = transform;
	this->eState = STATE::CD;
}

State::~State() {
	if (timer != NULL)delete timer;
}