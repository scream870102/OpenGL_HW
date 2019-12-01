#include "MainScene.h"

void MainScene::Update(float delta) {
	pBg->Update(delta);
	pCc->Update(delta);
	pBulletPool->Update(delta);
	pSmokePool->Update(delta);
	if (!bBossFight&&pCc->HowManyEnemyDie() >= ENEMY_NUM_TO_KILL) {
		bBossFight = true;
		pCc->StartBossFight();
		pBg->StartBossFight();
	}

	//INPUT MUST BE LAST ONE
	input.Update();
}

void MainScene::Draw() {
	pBg->Draw();
	pSmokePool->Draw();
	pCc->Draw();
	pBulletPool->Draw();
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

MainScene::MainScene() {
	//  產生 projection 矩陣，此處為產生正投影矩陣
	matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f);
	matModelView = mat4(1.0f);
	pBg = new Background(MAX_BG_NUM, matModelView, matProjection);
	pCc = new CharacterController(MAX_ENEMY_NUM, &(this->input), matModelView, matProjection);
	pBulletPool = BulletPool::Create(MAX_BULLET_NUM, matModelView, matProjection);
	pSmokePool = SmokePool::Create(MAX_SMOKE_NUM, matModelView, matProjection);
	bBossFight = false;
}

MainScene::~MainScene() {
	pBulletPool->Destroy();
	pSmokePool->Destroy();
	if (pBg != NULL) delete pBg;
	if (pCc != NULL)delete pCc;
}

