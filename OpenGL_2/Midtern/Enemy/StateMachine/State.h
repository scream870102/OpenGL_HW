#pragma once
#include "../../../Utils/CountdownTimer.h"
#include "../../../Utils/Transform.h"
#include "../../../Utils/Random.h"
class State
{
	enum class STATE
	{
		ACTION,
		CD,
	};
private:
	STATE eState;
	int actionTime;
	int cd;
	CountDownTimer* timer;
protected:
	Transform* transform;
public:
private:
protected:
	virtual void Action(float delta);
	virtual void InitAction();
public:
	virtual void Init(int actionTime, int cd, Transform* transform);
	bool IsReady();
	bool Update(float delta);
	void StartAction();
	State(int actionTime = 0, int cd = 0, Transform* transform = NULL);
	~State();

};

