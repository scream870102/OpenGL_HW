#include "Shushu.h"

void Shushu::Update(float delta) {
	Enemy::Update(delta);
	this->transform->position = move->GetNextPos(delta);
	AutoRotation(delta);
	if (shootTimer->IsFinished()) {
		this->transform->scale = vec3(1.0f);
		shootTimer->Reset();
		BulletPool::GetInstance()->Fire(ENEMY, this->transform->position, vec3(0.0f, 1.0f, 0.0f), BULLET_SPEED, this->damage, this->pPlayer->transform, BULLET_TRACING_TIME);
	}
}

void Shushu::AutoRotation(float delta) {
	vec3 tmp = this->transform->scale;
	tmp += SCALE_VEL * delta;
	this->transform->scale = tmp;
}

Shushu::Shushu(Player* player, int damage, int health, vec3 initPos, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) :Enemy(player, ENEMY, damage, health) {
	_points[0] = point4(0.0f, -14.0f, 0.0f, 1.0f);
	_points[1] = point4(-23.0f, -2.0f, 0.0f, 1.0f);
	_points[2] = point4(0.0f, 19.0f, 0.0f, 1.0f);
	_points[3] = point4(0.0f, -14.0f, 0.0f, 1.0f);
	_points[4] = point4(0.0f, 19.0f, 0.0f, 1.0f);
	_points[5] = point4(19.0f, 6.0f, 0.0f, 1.0f);
	_colors[0] = color4(0.0392156862745098f, 0.5019607843137255f, 0.9725490196078431f, 1.0f);
	_colors[1] = color4(0.0392156862745098f, 0.5019607843137255f, 0.9725490196078431f, 1.0f);
	_colors[2] = color4(0.0392156862745098f, 0.5019607843137255f, 0.9725490196078431f, 1.0f);
	_colors[3] = color4(0.0392156862745098f, 0.5019607843137255f, 0.9725490196078431f, 1.0f);
	_colors[4] = color4(0.0392156862745098f, 0.5019607843137255f, 0.9725490196078431f, 1.0f);
	_colors[5] = color4(0.0392156862745098f, 0.5019607843137255f, 0.9725490196078431f, 1.0f);
	_points[6] = point4(-13.0f, -21.0f, 0.0f, 1.0f);
	_points[7] = point4(-18.0f, -14.0f, 0.0f, 1.0f);
	_points[8] = point4(-12.0f, -13.0f, 0.0f, 1.0f);
	_points[9] = point4(-19.0f, -14.0f, 0.0f, 1.0f);
	_points[10] = point4(-5.0f, -7.0f, 0.0f, 1.0f);
	_points[11] = point4(-12.0f, -13.0f, 0.0f, 1.0f);
	_points[12] = point4(-19.0f, -14.0f, 0.0f, 1.0f);
	_points[13] = point4(-28.0f, -1.0f, 0.0f, 1.0f);
	_points[14] = point4(-17.0f, -3.0f, 0.0f, 1.0f);
	_points[15] = point4(-17.0f, -3.0f, 0.0f, 1.0f);
	_points[16] = point4(-16.0f, 3.0f, 0.0f, 1.0f);
	_points[17] = point4(-23.0f, 11.0f, 0.0f, 1.0f);
	_points[18] = point4(-25.0f, -16.0f, 0.0f, 1.0f);
	_points[19] = point4(-21.0f, -22.0f, 0.0f, 1.0f);
	_points[20] = point4(-19.0f, -14.0f, 0.0f, 1.0f);
	_points[21] = point4(-16.0f, 3.0f, 0.0f, 1.0f);
	_points[22] = point4(-12.0f, 19.0f, 0.0f, 1.0f);
	_points[23] = point4(-23.0f, 11.0f, 0.0f, 1.0f);
	_points[24] = point4(-17.0f, -3.0f, 0.0f, 1.0f);
	_points[25] = point4(-23.0f, 11.0f, 0.0f, 1.0f);
	_points[26] = point4(-28.0f, -1.0f, 0.0f, 1.0f);
	_points[27] = point4(-19.0f, -14.0f, 0.0f, 1.0f);
	_points[28] = point4(-5.0f, -7.0f, 0.0f, 1.0f);
	_points[29] = point4(-17.0f, -3.0f, 0.0f, 1.0f);
	_points[30] = point4(-25.0f, -16.0f, 0.0f, 1.0f);
	_points[31] = point4(-19.0f, -14.0f, 0.0f, 1.0f);
	_points[32] = point4(-28.0f, -1.0f, 0.0f, 1.0f);
	_points[33] = point4(-16.0f, 3.0f, 0.0f, 1.0f);
	_points[34] = point4(3.0f, 21.0f, 0.0f, 1.0f);
	_points[35] = point4(-12.0f, 19.0f, 0.0f, 1.0f);
	_points[36] = point4(19.0f, 13.0f, 0.0f, 1.0f);
	_points[37] = point4(-6.0f, 13.0f, 0.0f, 1.0f);
	_points[38] = point4(3.0f, 21.0f, 0.0f, 1.0f);
	_points[39] = point4(26.0f, 2.0f, 0.0f, 1.0f);
	_points[40] = point4(5.0f, 13.0f, 0.0f, 1.0f);
	_points[41] = point4(19.0f, 13.0f, 0.0f, 1.0f);
	_points[42] = point4(26.0f, -8.0f, 0.0f, 1.0f);
	_points[43] = point4(15.0f, 8.0f, 0.0f, 1.0f);
	_points[44] = point4(26.0f, 2.0f, 0.0f, 1.0f);
	_points[45] = point4(24.0f, -16.0f, 0.0f, 1.0f);
	_points[46] = point4(15.0f, 8.0f, 0.0f, 1.0f);
	_points[47] = point4(26.0f, -8.0f, 0.0f, 1.0f);
	_points[48] = point4(17.0f, -24.0f, 0.0f, 1.0f);
	_points[49] = point4(10.0f, -7.0f, 0.0f, 1.0f);
	_points[50] = point4(25.0f, -3.0f, 0.0f, 1.0f);
	_points[51] = point4(10.0f, -7.0f, 0.0f, 1.0f);
	_points[52] = point4(15.0f, 8.0f, 0.0f, 1.0f);
	_points[53] = point4(20.0f, -5.0f, 0.0f, 1.0f);
	_colors[6] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[7] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[8] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[9] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[10] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[11] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[12] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[13] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[14] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[15] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[16] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[17] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[18] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[19] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[20] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[21] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[22] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[23] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[24] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[25] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[26] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[27] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[28] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[29] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[30] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[31] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[32] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[33] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[34] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[35] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[36] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[37] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[38] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[39] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[40] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[41] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[42] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[43] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[44] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[45] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[46] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[47] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[48] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[49] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[50] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[51] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[52] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	_colors[53] = color4(0.9725490196078431f, 0.5725490196078431f, 0.00784313725490196f, 1.0f);
	transform = new Transform();
	transform->Init(_points, _colors, SHUSHU_NUM, matModelView, matProjection, shaderHandle);
	transform->position = initPos;
	shootTimer = new CountDownTimer(SHUSHU_SHOOT_CD, Random::GetRand(SHUSHU_SHOOT_CD));
	move = new PingPongMove(this->transform, SHUSHU_MOVE_SPEED, (float)WIDTH, 0.0f);
	collider = new CircleCollider(SHUSHU_RADIUS, this->transform->position);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//MUST SET ORIGINAL COLORS
	originColor = std::vector<color4>(_colors, _colors + (int)(sizeof(_colors) / sizeof(_colors[0])));
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

Shushu::~Shushu() {
	if (move != NULL)delete move;
}

Shushu::Shushu(const Shushu& s) :Enemy(s) {
	memcpy(_points, s._points, sizeof(s._points));
	memcpy(_colors, s._colors, sizeof(s._colors));
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TOFIX:CHECK IF THIS RIGHT WAY
	move = new PingPongMove(*s.move);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

Shushu& Shushu::operator=(const Shushu& s) {
	if (&s != this) {
		if (move != NULL)delete move;
		memcpy(_points, s._points, sizeof(s._points));
		memcpy(_colors, s._colors, sizeof(s._colors));
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//TOFIX:CHECK IF THIS RIGHT WAY
		move = new PingPongMove(*s.move);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	return *this;
}
