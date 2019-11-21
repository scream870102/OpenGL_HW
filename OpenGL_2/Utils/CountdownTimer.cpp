#include "CountdownTimer.h"


CountDownTimer::CountDownTimer(int CD) {
	this->CD = CD;
	this->time = glutGet(GLUT_ELAPSED_TIME) + CD;
}

CountDownTimer::~CountDownTimer() {}

void CountDownTimer::Init(int CD){
	this->CD = CD;
	this->time = glutGet(GLUT_ELAPSED_TIME) + this->CD;
}

bool CountDownTimer::IsFinished() {
	return time <= glutGet(GLUT_ELAPSED_TIME);
}

void CountDownTimer::Reset() {
	this->time = glutGet(GLUT_ELAPSED_TIME) + this->CD;
}

void CountDownTimer::Reset(int newCD) {
	this->CD = newCD;
	this->time = glutGet(GLUT_ELAPSED_TIME) + this->CD;
}
