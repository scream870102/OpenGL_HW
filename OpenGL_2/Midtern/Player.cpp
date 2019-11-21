#include "Player.h"
Player::Player(mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	_points[0] = point4(0.0f, -30.0f, 0.0f, 1.0f);
	_points[1] = point4(-10.0f, -12.0f, 0.0f, 1.0f);
	_points[2] = point4(10.0f, -12.0f, 0.0f, 1.0f);
	_points[3] = point4(-51.0f, -13.0f, 0.0f, 1.0f);
	_points[4] = point4(-36.0f, 12.0f, 0.0f, 1.0f);
	_points[5] = point4(0.0f, 15.0f, 0.0f, 1.0f);
	_points[6] = point4(7.0f, 20.0f, 0.0f, 1.0f);
	_points[7] = point4(-7.0f, 20.0f, 0.0f, 1.0f);
	_points[8] = point4(0.0f, 53.0f, 0.0f, 1.0f);
	_points[9] = point4(0.0f, 15.0f, 0.0f, 1.0f);
	_points[10] = point4(51.0f, -13.0f, 0.0f, 1.0f);
	_points[11] = point4(36.0f, 12.0f, 0.0f, 1.0f);
	_points[12] = point4(-39.0f, -13.0f, 0.0f, 1.0f);
	_points[13] = point4(-14.0f, -10.0f, 0.0f, 1.0f);
	_points[14] = point4(0.0f, 12.0f, 0.0f, 1.0f);
	_points[15] = point4(13.0f, -10.0f, 0.0f, 1.0f);
	_points[16] = point4(39.0f, -13.0f, 0.0f, 1.0f);
	_points[17] = point4(0.0f, 12.0f, 0.0f, 1.0f);
	_points[18] = point4(10.0f, 20.0f, 0.0f, 1.0f);
	_points[19] = point4(29.0f, 66.0f, 0.0f, 1.0f);
	_points[20] = point4(2.0f, 56.0f, 0.0f, 1.0f);
	_points[21] = point4(-10.0f, -12.0f, 0.0f, 1.0f);
	_points[22] = point4(10.0f, -12.0f, 0.0f, 1.0f);
	_points[23] = point4(0.0f, 6.0f, 0.0f, 1.0f);
	_points[24] = point4(-29.0f, 66.0f, 0.0f, 1.0f);
	_points[25] = point4(-10.0f, 20.0f, 0.0f, 1.0f);
	_points[26] = point4(-2.0f, 56.0f, 0.0f, 1.0f);
	_colors[0] = color4(0.9099312546088323f, 0.8658456441194392f, 0.7637422342385652f, 1.0f);
	_colors[1] = color4(0.9811738639902003f, 0.7595056032531191f, 0.8024661498270882f, 1.0f);
	_colors[2] = color4(0.8587138231316165f, 0.8981577870381722f, 0.7628545893718714f, 1.0f);
	_colors[3] = color4(0.9879270534648469f, 0.8473888249213098f, 0.808741175754832f, 1.0f);
	_colors[4] = color4(0.9507417675972624f, 0.89705567474343f, 0.9230607582059067f, 1.0f);
	_colors[5] = color4(0.9443259988096081f, 0.8058041574736291f, 0.9841460641336566f, 1.0f);
	_colors[6] = color4(0.8491486747944369f, 0.7783093786941417f, 0.8291182143995542f, 1.0f);
	_colors[7] = color4(0.8492372271614717f, 0.9852722932938801f, 0.9661979715530267f, 1.0f);
	_colors[8] = color4(0.8026653677408511f, 0.7534817306439753f, 0.943156683799408f, 1.0f);
	_colors[9] = color4(0.8713044338915821f, 0.8650116194830613f, 0.9415218567246679f, 1.0f);
	_colors[10] = color4(0.9337346701780015f, 0.8996899422510214f, 0.887667524431818f, 1.0f);
	_colors[11] = color4(0.7518518846736804f, 0.862707774196625f, 0.9684532234277026f, 1.0f);
	_colors[12] = color4(0.8806562315170136f, 0.9518831117648097f, 0.8665515681699674f, 1.0f);
	_colors[13] = color4(0.8786314911227235f, 0.8739787965879714f, 0.9015680865321072f, 1.0f);
	_colors[14] = color4(0.9914515202334456f, 0.9814394602364698f, 0.834627843467969f, 1.0f);
	_colors[15] = color4(0.8452444928752638f, 0.8970215752474888f, 0.9224395541413011f, 1.0f);
	_colors[16] = color4(0.8105516070954035f, 0.7897920981612175f, 0.932449079498953f, 1.0f);
	_colors[17] = color4(0.86004872562867f, 0.903483688978697f, 0.7897167185131739f, 1.0f);
	_colors[18] = color4(0.8007234759064085f, 0.9270034800444833f, 0.8103167049808927f, 1.0f);
	_colors[19] = color4(0.973595010581028f, 0.9378260873749149f, 0.8476533107586135f, 1.0f);
	_colors[20] = color4(0.7706991996650137f, 0.8608714352099041f, 0.9853247813525605f, 1.0f);
	_colors[21] = color4(0.7987424517246242f, 0.7690790128552953f, 0.8755979006220204f, 1.0f);
	_colors[22] = color4(0.9496810471878238f, 0.9577606009297338f, 0.8907229730634064f, 1.0f);
	_colors[23] = color4(0.8928003788161281f, 0.9612531841079072f, 0.9396544620662455f, 1.0f);
	_colors[24] = color4(0.8339279563742212f, 0.9029766440824398f, 0.9770839169051371f, 1.0f);
	_colors[25] = color4(0.956410196467498f, 0.9359492260520559f, 0.9526516267995727f, 1.0f);
	_colors[26] = color4(0.9595336435425172f, 0.8790594347152512f, 0.9377534316165966f, 1.0f);
	//_currentBullets.clear();
	input = NULL;
	transform = new Transform();
	transform->Init(_points, _colors, P_NUM, matModelView, matProjection, shaderHandle);
	shootTimer = new CountDownTimer(SHOOT_CD);
	//Section for Init bullet to bulletPool
	for (int i = 0; i < BULLETS_NUM; i++)
	{
		Bullet* pBullet = new Bullet(matModelView, matProjection, shaderHandle);
		pBullet->poolParent = &_bulletPool;
		_bulletPool.Init(pBullet);
	}
}

Player::~Player() {
	if (transform != NULL)delete transform;
	if (shootTimer != NULL)delete shootTimer;
	//if (!_currentBullets.empty()) {
	//	for (int i = 0; i < _currentBullets.size(); i++)
	//	{
	//		if (_currentBullets[i] != NULL)delete _currentBullets[i];
	//	}
	//}
}

Player::Player(const Player& p) {
	memcpy(_points, p._points, sizeof(p._points));
	memcpy(_colors, p._colors, sizeof(p._colors));
	_bulletPool = p._bulletPool;
	//_currentBullets = p._currentBullets;
	input = p.input;
	transform = p.transform;
	shootTimer = p.shootTimer;
}

void Player::SetShader(mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	transform->SetShader(matModelView, matProjection, shaderHandle);
}


void Player::Draw() {
	transform->Draw();
	//Print(_bulletPool.GetUsingObjs()->size());
	BVectorP usingBullets=_bulletPool.GetUsingObjs();
	for (int i = 0; i < (int)usingBullets->size(); i++)
	{
		usingBullets[0][i]->Draw();
	}
	//for (int i = 0; i < (int)_currentBullets.size(); i++) {
	//	_currentBullets[i]->Draw();
	//}
}

void Player::Update(float delta) {
	//Modify player position due to mouse position
	this->transform->position.x = (GLfloat)input->mouseX;
	this->transform->position.y = (GLfloat)input->mouseY;
	if (shootTimer->IsFinished()&&input->IsGetMouse(LEFT_MOUSE)) {
		shootTimer->Reset();
		Bullet* tmp = _bulletPool.GetPoolObject();
		if (tmp != NULL) {
			tmp->Fire(PLAYER, this->transform->position, NORMAL_BULLET_SPEED);
			//tmp->poolParent = &_bulletPool;
			//_currentBullets.push_back(tmp);
		}
	}
	BVectorP usingBullets = _bulletPool.GetUsingObjs();
	for (int i = 0; i < (int)usingBullets->size(); i++)
	{
		usingBullets[0][i]->Update(delta);
	}
	//for (int i = 0; i < (int)_currentBullets.size(); i++) {
	//	_currentBullets[i]->Update(delta);
	//}

}
