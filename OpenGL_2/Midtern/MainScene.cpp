#include "MainScene.h"

void MainScene::Update(float delta) {
	pPlayer->Update(delta);
	pBulletPool->Update(delta);
	input.Update();
}

void MainScene::Draw() {
	pPlayer->Draw();
	pBulletPool->Draw();
}

MainScene::MainScene() {
	//  ���� projection �x�}�A���B�����ͥ���v�x�}
	matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f);
	matModelView = mat4(1.0f);
	//���ͪ��a �øj�w Input
	pPlayer = new Player(matModelView, matProjection);
	pPlayer->input = &input;
	pBulletPool = BulletPool::Create(MAX_BULLET_NUM, matModelView, matProjection);
}

MainScene::~MainScene() {
	if (pPlayer != NULL)delete pPlayer;
	pBulletPool->Destroy();
}

void MainScene::OnWinKeyboard(unsigned char key, int x, int y) {
	input.KeyPressed(key);
}

void MainScene::OnWinSpecialKeyboard(int key, int x, int y) {
	input.KeyPressed(key);
}

void MainScene::OnWinMouse(int button, int state, int x, int y) {
	input.MousePressed(button, state, x, y);
}

void MainScene::OnWinPassiveMouse(int x, int y) {
	input.MouseMove(x, y);
}


