#pragma once
#include "Enemy.h"
#include "StateMachine/TraceState.h"
#include "StateMachine/ShotGunState.h"
#include <vector>
#define BOSS_NUM 39
#define BOSS_RADIUS 30
#define BOSS_ACTION_NUM 4
#define B_TRACE_NUM 4
#define B_SHOTGUN_NUM 5
#define B_SIN_ELSP_TIME 2000
#define B_PARELLEL_NUM 7

class Boss : public Enemy
{
	enum class ACTION {
		TRACE,
		SHOTGUN,
		SIN,
		PARALLEL,
	};
	enum class CD
	{
		TRACE = 10000,
		SHOTGUN = 10000,
		SIN = 10000,
		PARALLEL = 10000,
	};
	enum class ACTION_TIME {
		TRACE=500,
		SHOTGUN=1000,
		SIN=2000,
		PARALLEL=2000,
	};
private:
	point4 _points[BOSS_NUM];
	color4 _colors[BOSS_NUM];
	State* currentState;
	std::vector<State*> states;
public:
private:
public:
	void Update(float delta)override;
	Boss(Player* player, int damage, int health, vec3 initPos, mat4& matModelView, mat4& matProjection, GLuint shaderHandle = MAX_UNSIGNED_INT);
	~Boss();
};

