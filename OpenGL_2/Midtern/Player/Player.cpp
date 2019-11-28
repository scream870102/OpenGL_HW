#include "Player.h"
#include "../CharacterController.h"
void Player::Update(float delta) {
	Character::Update(delta);
	//Modify player position due to mouse position
	this->transform->position.x = (GLfloat)Mathf::Clamp((float)input->mouseX, (float)WIDTH);
	this->transform->position.y = (GLfloat)Mathf::Clamp((float)input->mouseY, (float)HEIGHT, HEIGHT * (1.0f - PLAYER_Y_RANGE));
	NormalShot(delta);
	ShotGun(delta);
	TraceShot(delta);
	UpdateGuards(delta);
}

void Player::Draw() {
	Character::Draw();
	for (size_t i = 0; i < guards.size(); i++) {
		guards[i]->Draw();
	}
}

void Player::SetCharacterController(CharacterController* pCC) {
	this->pCC = pCC;
}

std::vector<Guard*> Player::GetEnableGuards() {
	std::vector<Guard*> res;
	for (size_t i = 0; i < guards.size(); i++) {
		if (guards[i]->IsEnable)res.push_back(guards[i]);
	}
	return res;
}

void Player::Dead() {
	Character::Dead();
	//Print("HEYHEYHEY");
}

void Player::ShotGun(float delta) {
	if (input->IsGetKey('f') && shotGunTimer->IsFinished()) {
		float offset = (180.0f - SHOUT_GUN_OFFSET * (SHOUT_GUN_NUM - 1)) / 2.0f;
		for (int i = 0; i < SHOUT_GUN_NUM; i++) {
			float degree = i * SHOUT_GUN_OFFSET + offset;
			vec3 direction = Angel::normalize(Mathf::ConvertToVec3FromDeg(degree, -180.0f));
			BulletPool::GetInstance()->Fire(PLAYER, transform->GetGlobalPosition(), direction, SHOT_GUN_SPEED, damage);
		}
		shotGunTimer->Reset();
	}
}

void Player::TraceShot(float delta) {
	if (input->IsGetKey('g') && traceTimer->IsFinished()) {
		std::vector<Enemy*>* enemies = pCC->GetActiveEnemies();
		for (int i = 0; i < TRACE_NUM; i++) {
			if ((int)enemies->size() > 0) {
				int index = Random::GetRand((int)enemies->size() - 1, 0);
				BulletPool::GetInstance()->Fire(PLAYER, transform->GetGlobalPosition(), vec3(), TRACE_SPEED, damage, enemies[0][index]->transform, TRACE_TIME);
			}
		}
		traceTimer->Reset();
	}
}

void Player::UpdateGuards(float delta) {
	//Check if gurad is not enable and timer is finished
	if (guardTimer->IsFinished()) {
		for (size_t i = 0; i < guards.size(); i++) {
			if (!guards[i]->IsEnable) {
				guards[i]->IsEnable = true;
				guardTimer->Reset();
				break;
			}
		}
	}

	//Calc the guard position and radius
	guardRotOffset += delta * GUARD_ROTATE_VEL;
	if (guardRotOffset > 360.0f)guardRotOffset = 0.0f;
	float offset = 360.0f / GUARD_MAX_NUM;
	for (size_t i = 0; i < guards.size(); i++) {
		if (!guards[i]->IsEnable)break;
		float degree = offset * i + guardRotOffset;
		vec3 normalVec = Mathf::ConvertToVec3FromDeg(degree);
		guards[i]->transform->position = normalVec * GUARD_DISTANCE;
		guards[i]->transform->rotation.z = degree + 90.0f;
		guards[i]->Update(delta);
	}
}

void Player::NormalShot(float delta) {
	if (shootTimer->IsFinished() && input->IsGetMouse(LEFT_MOUSE)) {
		shootTimer->Reset();
		BulletPool::GetInstance()->Fire(PLAYER, this->transform->position, vec3(0.0f, -1.0f, 0.0f), NORMAL_BULLET_SPEED, damage);
	}
}

Player::Player(int damage, int health, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) :Character(PLAYER, damage, health) {
	_points[0] = point4(0.0f, -41.0f, 0.0f, 1.0f);
	_points[1] = point4(-40.0f, -28.0f, 0.0f, 1.0f);
	_points[2] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[3] = point4(-40.0f, -28.0f, 0.0f, 1.0f);
	_points[4] = point4(-40.0f, 29.0f, 0.0f, 1.0f);
	_points[5] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[6] = point4(0.0f, 42.0f, 0.0f, 1.0f);
	_points[7] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[8] = point4(-40.0f, 29.0f, 0.0f, 1.0f);
	_points[9] = point4(39.0f, 29.0f, 0.0f, 1.0f);
	_points[10] = point4(39.0f, -28.0f, 0.0f, 1.0f);
	_points[11] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[12] = point4(39.0f, -28.0f, 0.0f, 1.0f);
	_points[13] = point4(0.0f, -41.0f, 0.0f, 1.0f);
	_points[14] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[15] = point4(39.0f, 29.0f, 0.0f, 1.0f);
	_points[16] = point4(0.0f, 0.0f, 0.0f, 1.0f);
	_points[17] = point4(0.0f, 42.0f, 0.0f, 1.0f);
	_colors[0] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[1] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[2] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[3] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[4] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[5] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[6] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[7] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[8] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[9] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[10] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[11] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[12] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[13] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[14] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[15] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[16] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_colors[17] = color4(0.9098039215686274f, 0.21568627450980393f, 0.21176470588235294f, 1.0f);
	_points[18] = point4(-21.0f, -17.0f, 0.0f, 1.0f);
	_points[19] = point4(-27.0f, -20.0f, 0.0f, 1.0f);
	_points[20] = point4(-30.0f, -13.0f, 0.0f, 1.0f);
	_points[21] = point4(-30.0f, -13.0f, 0.0f, 1.0f);
	_points[22] = point4(-11.0f, 21.0f, 0.0f, 1.0f);
	_points[23] = point4(-6.0f, 13.0f, 0.0f, 1.0f);
	_points[24] = point4(-6.0f, 13.0f, 0.0f, 1.0f);
	_points[25] = point4(-21.0f, -17.0f, 0.0f, 1.0f);
	_points[26] = point4(-30.0f, -13.0f, 0.0f, 1.0f);
	_points[27] = point4(-6.0f, 13.0f, 0.0f, 1.0f);
	_points[28] = point4(10.0f, 14.0f, 0.0f, 1.0f);
	_points[29] = point4(-11.0f, 21.0f, 0.0f, 1.0f);
	_points[30] = point4(-11.0f, 21.0f, 0.0f, 1.0f);
	_points[31] = point4(2.0f, 30.0f, 0.0f, 1.0f);
	_points[32] = point4(11.0f, 23.0f, 0.0f, 1.0f);
	_points[33] = point4(10.0f, 14.0f, 0.0f, 1.0f);
	_points[34] = point4(-11.0f, 21.0f, 0.0f, 1.0f);
	_points[35] = point4(11.0f, 23.0f, 0.0f, 1.0f);
	_points[36] = point4(10.0f, 18.0f, 0.0f, 1.0f);
	_points[37] = point4(21.0f, -1.0f, 0.0f, 1.0f);
	_points[38] = point4(11.0f, 23.0f, 0.0f, 1.0f);
	_points[39] = point4(10.0f, 18.0f, 0.0f, 1.0f);
	_points[40] = point4(21.0f, -1.0f, 0.0f, 1.0f);
	_points[41] = point4(10.0f, 14.0f, 0.0f, 1.0f);
	_points[42] = point4(14.0f, 9.0f, 0.0f, 1.0f);
	_points[43] = point4(25.0f, -14.0f, 0.0f, 1.0f);
	_points[44] = point4(17.0f, -20.0f, 0.0f, 1.0f);
	_points[45] = point4(17.0f, -20.0f, 0.0f, 1.0f);
	_points[46] = point4(12.0f, -11.0f, 0.0f, 1.0f);
	_points[47] = point4(14.0f, 9.0f, 0.0f, 1.0f);
	_points[48] = point4(25.0f, -14.0f, 0.0f, 1.0f);
	_points[49] = point4(14.0f, 9.0f, 0.0f, 1.0f);
	_points[50] = point4(21.0f, -1.0f, 0.0f, 1.0f);
	_colors[18] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[19] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[20] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[21] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[22] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[23] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[24] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[25] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[26] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[27] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[28] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[29] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[30] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[31] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[32] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[33] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[34] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[35] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[36] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[37] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[38] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[39] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[40] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[41] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[42] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[43] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[44] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[45] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[46] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[47] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[48] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[49] = color4(1.0f, 1.0f, 1.0f, 1.0f);
	_colors[50] = color4(1.0f, 1.0f, 1.0f, 1.0f);

	input = NULL;
	transform = new Transform();
	transform->Init(_points, _colors, P_NUM, matModelView, matProjection, shaderHandle);
	collider = new CircleCollider(PLAYER_RADIUS, this->transform->position);
	shootTimer = new CountDownTimer(PLAYER_SHOOT_CD);
	shotGunTimer = new CountDownTimer(SHOT_GUN_CD);
	bShotGun = false;
	pCC = NULL;
	traceTimer = new CountDownTimer(TRACE_CD);
	bTrace = false;
	//!!!!!!!!!!!!!!!!!
	//SECTION GUARDS
	for (int i = 0; i < GUARD_MAX_NUM; i++) {
		guards.push_back(new Guard(matModelView, matProjection, shaderHandle));
		guards[i]->transform->pParent = this->transform;
	}
	guardRotOffset = 0.0f;
	guardTimer = new CountDownTimer(GUARD_CD);
}

Player::~Player() {
	if (shootTimer != NULL)delete shootTimer;
	if (shotGunTimer != NULL)delete shotGunTimer;
	if (traceTimer != NULL)delete traceTimer;
	//!!!!!!!!!!!!!!!!!!
	//DELETE FOR GUARD
}

Player::Player(const Player& p) :Character(p) {
	memcpy(_points, p._points, sizeof(p._points));
	memcpy(_colors, p._colors, sizeof(p._colors));
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TOFIX:CHECK IF THIS RIGHT WAY
	shootTimer = new CountDownTimer(*p.shootTimer);
	shotGunTimer = new CountDownTimer(*p.shotGunTimer);
	traceTimer = new CountDownTimer(*p.traceTimer);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	input = p.input;
	bShotGun = p.bShotGun;
	pCC = p.pCC;
	bTrace = p.bTrace;
	//!!!!!!!!!!!!!!!!!!
	//DELETE FOR GUARD

}

const Player& Player::operator=(const Player& p) {
	if (&p != this) {
		if (shootTimer != NULL)delete shootTimer;
		memcpy(_points, p._points, sizeof(p._points));
		memcpy(_colors, p._colors, sizeof(p._colors));
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//TOFIX:CHECK IF THIS RIGHT WAY
		shootTimer = new CountDownTimer(*p.shootTimer);
		shotGunTimer = new CountDownTimer(*p.shotGunTimer);
		traceTimer = new CountDownTimer(*p.traceTimer);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		input = p.input;
		bShotGun = false;
		pCC = p.pCC;
		bTrace = p.bTrace;
		//!!!!!!!!!!!!!!!!!!
		//DELETE FOR GUARD
	}
	return *this;
}


