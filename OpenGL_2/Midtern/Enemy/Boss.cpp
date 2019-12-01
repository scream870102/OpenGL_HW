#include "Boss.h"


void Boss::Dead() {
	Character::Dead();
	this->transform->SetAlpha(0.2f);
}

void Boss::DamageAnim(float delta) {
	if (!damageTimer->IsFinished()) {
		float a = this->transform->GetAlpha();
		this->transform->SetAlpha(a - DAMAGA_FADE_VEL * delta);
		if (damageTimer->Remain() % SMOKE_HZ == 0) {
			vec3 bombPos=this->transform->position;
			bombPos.x += Random::GetRand(BOSS_RADIUS, -BOSS_RADIUS);
			bombPos.y += Random::GetRand(BOSS_RADIUS, -BOSS_RADIUS);
			SmokePool::GetInstance()->Bomb(bombPos);
		}
	}
	else {
		this->transform->SetAlpha(1.0f);
		bTakeDamage = false;
	}

}

void Boss::Update(float delta) {
	if (IsDead())return;
	Enemy::Update(delta);
	if (currentState != NULL) {
		//Check state in vector is ready and choose one of them start the action
		if (currentState->IsReady()) {
			currentState->StartAction();
		}
		//Update current state
		bool isStateFin = currentState->Update(delta);
		//if state return true
		//find the next state by asking other state cd is ready or not
		if (isStateFin) {
			currentState = states[Random::GetRand((int)states.size() - 1)];
		}
	}
}

Boss::Boss(Player* player, int damage, int health, vec3 initPos, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) :Enemy(player, ENEMY, damage, health) {
#pragma region -- POINT&COLOR --
	_points[0] = point4(-3.0f, -29.0f, 0.0f, 1.0f);
	_points[1] = point4(-26.0f, -18.0f, 0.0f, 1.0f);
	_points[2] = point4(-3.0f, -19.0f, 0.0f, 1.0f);
	_points[3] = point4(-26.0f, -18.0f, 0.0f, 1.0f);
	_points[4] = point4(-26.0f, -8.0f, 0.0f, 1.0f);
	_points[5] = point4(-3.0f, -19.0f, 0.0f, 1.0f);
	_points[6] = point4(-3.0f, -29.0f, 0.0f, 1.0f);
	_points[7] = point4(-3.0f, -19.0f, 0.0f, 1.0f);
	_points[8] = point4(16.0f, -19.0f, 0.0f, 1.0f);
	_colors[0] = color4(0.8431372549019608f, 0.30980392156862746f, 0.25882352941176473f, 1.0f);
	_colors[1] = color4(0.8431372549019608f, 0.30980392156862746f, 0.25882352941176473f, 1.0f);
	_colors[2] = color4(0.8431372549019608f, 0.30980392156862746f, 0.25882352941176473f, 1.0f);
	_colors[3] = color4(0.8431372549019608f, 0.30980392156862746f, 0.25882352941176473f, 1.0f);
	_colors[4] = color4(0.8431372549019608f, 0.30980392156862746f, 0.25882352941176473f, 1.0f);
	_colors[5] = color4(0.8431372549019608f, 0.30980392156862746f, 0.25882352941176473f, 1.0f);
	_colors[6] = color4(0.8431372549019608f, 0.30980392156862746f, 0.25882352941176473f, 1.0f);
	_colors[7] = color4(0.8431372549019608f, 0.30980392156862746f, 0.25882352941176473f, 1.0f);
	_colors[8] = color4(0.8431372549019608f, 0.30980392156862746f, 0.25882352941176473f, 1.0f);
	_points[9] = point4(-18.0f, 14.0f, 0.0f, 1.0f);
	_points[10] = point4(-26.0f, -4.0f, 0.0f, 1.0f);
	_points[11] = point4(-26.0f, 20.0f, 0.0f, 1.0f);
	_points[12] = point4(-18.0f, 14.0f, 0.0f, 1.0f);
	_points[13] = point4(6.0f, 24.0f, 0.0f, 1.0f);
	_points[14] = point4(-26.0f, 20.0f, 0.0f, 1.0f);
	_points[15] = point4(6.0f, 24.0f, 0.0f, 1.0f);
	_points[16] = point4(-3.0f, 30.0f, 0.0f, 1.0f);
	_points[17] = point4(-26.0f, 20.0f, 0.0f, 1.0f);
	_colors[9] = color4(0.09803921568627451f, 0.615686274509804f, 0.3607843137254902f, 1.0f);
	_colors[10] = color4(0.09803921568627451f, 0.615686274509804f, 0.3607843137254902f, 1.0f);
	_colors[11] = color4(0.09803921568627451f, 0.615686274509804f, 0.3607843137254902f, 1.0f);
	_colors[12] = color4(0.09803921568627451f, 0.615686274509804f, 0.3607843137254902f, 1.0f);
	_colors[13] = color4(0.09803921568627451f, 0.615686274509804f, 0.3607843137254902f, 1.0f);
	_colors[14] = color4(0.09803921568627451f, 0.615686274509804f, 0.3607843137254902f, 1.0f);
	_colors[15] = color4(0.09803921568627451f, 0.615686274509804f, 0.3607843137254902f, 1.0f);
	_colors[16] = color4(0.09803921568627451f, 0.615686274509804f, 0.3607843137254902f, 1.0f);
	_colors[17] = color4(0.09803921568627451f, 0.615686274509804f, 0.3607843137254902f, 1.0f);
	_points[18] = point4(8.0f, 22.0f, 0.0f, 1.0f);
	_points[19] = point4(25.0f, 13.0f, 0.0f, 1.0f);
	_points[20] = point4(16.0f, 8.0f, 0.0f, 1.0f);
	_points[21] = point4(25.0f, 13.0f, 0.0f, 1.0f);
	_points[22] = point4(19.0f, -17.0f, 0.0f, 1.0f);
	_points[23] = point4(16.0f, 8.0f, 0.0f, 1.0f);
	_points[24] = point4(19.0f, -17.0f, 0.0f, 1.0f);
	_points[25] = point4(28.0f, -12.0f, 0.0f, 1.0f);
	_points[26] = point4(25.0f, 13.0f, 0.0f, 1.0f);
	_colors[18] = color4(0.9725490196078431f, 0.7843137254901961f, 0.2627450980392157f, 1.0f);
	_colors[19] = color4(0.9725490196078431f, 0.7843137254901961f, 0.2627450980392157f, 1.0f);
	_colors[20] = color4(0.9725490196078431f, 0.7843137254901961f, 0.2627450980392157f, 1.0f);
	_colors[21] = color4(0.9725490196078431f, 0.7843137254901961f, 0.2627450980392157f, 1.0f);
	_colors[22] = color4(0.9725490196078431f, 0.7843137254901961f, 0.2627450980392157f, 1.0f);
	_colors[23] = color4(0.9725490196078431f, 0.7843137254901961f, 0.2627450980392157f, 1.0f);
	_colors[24] = color4(0.9725490196078431f, 0.7843137254901961f, 0.2627450980392157f, 1.0f);
	_colors[25] = color4(0.9725490196078431f, 0.7843137254901961f, 0.2627450980392157f, 1.0f);
	_colors[26] = color4(0.9725490196078431f, 0.7843137254901961f, 0.2627450980392157f, 1.0f);
	_points[27] = point4(-3.0f, -13.0f, 0.0f, 1.0f);
	_points[28] = point4(-19.0f, -5.0f, 0.0f, 1.0f);
	_points[29] = point4(-13.0f, 9.0f, 0.0f, 1.0f);
	_points[30] = point4(11.0f, -13.0f, 0.0f, 1.0f);
	_points[31] = point4(-3.0f, -13.0f, 0.0f, 1.0f);
	_points[32] = point4(-13.0f, 9.0f, 0.0f, 1.0f);
	_points[33] = point4(9.0f, 6.0f, 0.0f, 1.0f);
	_points[34] = point4(11.0f, -13.0f, 0.0f, 1.0f);
	_points[35] = point4(-13.0f, 9.0f, 0.0f, 1.0f);
	_points[36] = point4(3.0f, 16.0f, 0.0f, 1.0f);
	_points[37] = point4(9.0f, 6.0f, 0.0f, 1.0f);
	_points[38] = point4(-13.0f, 9.0f, 0.0f, 1.0f);
	_colors[27] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[28] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[29] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[30] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[31] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[32] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[33] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[34] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[35] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[36] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[37] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
	_colors[38] = color4(0.29411764705882354f, 0.5333333333333333f, 0.9372549019607843f, 1.0f);
#pragma endregion
	transform = new Transform();
	transform->Init(_points, _colors, BOSS_NUM, matModelView, matProjection, shaderHandle);
	transform->position = initPos;
	transform->scale = vec3(BOSS_INIT_SCALE);
	states.push_back(new TraceState(this, (int)Boss::ACTION_TIME::TRACE, (int)Boss::CD::TRACE, transform));
	states.push_back(new ShotGunState(this, (int)Boss::ACTION_TIME::SHOTGUN, (int)Boss::CD::SHOTGUN, transform));
	states.push_back(new SinState(this, (int)Boss::ACTION_TIME::SIN, (int)Boss::CD::SIN, transform));
	states.push_back(new ParellelState(this, (int)Boss::ACTION_TIME::PARALLEL, (int)Boss::CD::PARALLEL, transform));
	currentState = states[Random::GetRand((int)states.size() - 1)];
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//MUST SET ORIGINAL COLORS
	originColor = std::vector<color4>(_colors, _colors + (int)(sizeof(_colors) / sizeof(_colors[0])));
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	collider = new CircleCollider(BOSS_RADIUS, this->transform->position);
}

Boss::~Boss() {
	for (int i = 0; i < (int)states.size(); i++) {
		if (states[i] != NULL)
			delete states[i];
	}
	states.clear();
}