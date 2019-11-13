#include "MainScene.h"

void MainScene::Update(float delta) {
	pPlayer->Update(delta);
	input.Update();
}

void MainScene::Draw() {
	pPlayer->Draw();
}

MainScene::MainScene() {
	//���ͪ��a �øj�w Input
	pPlayer = new Player();
	pPlayer->i = &input;
	//  ���� projection �x�}�A���B�����ͥ���v�x�}
	matProjection = Ortho(-225.0f, 225.0f, -400.0f, 400.0f, -2.0f, 2.0f);
	matModelView = mat4(1.0f);
	pPlayer->SetShader(matModelView, matProjection);
}

MainScene::~MainScene() {
	delete pPlayer;
}

void MainScene::OnWinKeyboard(unsigned char key, int x, int y) {
	input.KeyPressed(key);
}

void MainScene::OnWinSpecialKeyboard(int key, int x, int y) {
	input.KeyPressed(key);
}

void MainScene::OnWinMouse(int button, int state, int x, int y){
	input.MousePressed(button, state, x, y);
}

void MainScene::OnWinPassiveMouse(int x, int y){
	input.MouseMove(x, y);
}


