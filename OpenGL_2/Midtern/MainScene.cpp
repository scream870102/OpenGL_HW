#include "MainScene.h"

void MainScene::Update(float delta) {
	//pPlayer->Update(delta);
	input.Update();
	pBulletPool->Update(delta);
	pBg->Update(delta);
	pCc->Update(delta);
	if (pCc->HowManyEnemyDie() >= ENEMY_NUM_TO_KILL) {
		pCc->StartBossFight();
	}
	//pShushu->Update(delta);
	//CheckBulletAndCharacter();
}

void MainScene::Draw() {
	pBg->Draw();
	//pPlayer->Draw();
	pCc->Draw();
	pBulletPool->Draw();
	//pShushu->Draw();
}

MainScene::MainScene() {
	//  產生 projection 矩陣，此處為產生正投影矩陣
	matProjection = Ortho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f);
	matModelView = mat4(1.0f);
	//產生玩家 並綁定 Input
	//pPlayer = new Player(INIT_PLAYER_DAMAGE, INIT_PLAYER_HEALTH, matModelView, matProjection);
	//pPlayer->input = &input;
	pBulletPool = BulletPool::Create(MAX_BULLET_NUM, matModelView, matProjection);
	pBg = new Background(MAX_BG_NUM, matModelView, matProjection);
	//pShushu = new Shushu(SHUSHU_DAMAGE, SHUSHU_HEALTH, vec3(Random::GetRand((float)WIDTH), Random::GetRand(HEIGHT / 2.0f), 0.0f), matModelView, matProjection);
	//activeCharacters.push_back(pPlayer);
	//activeCharacters.push_back(pShushu);
	pCc = new CharacterController(MAX_ENEMY_NUM, &(this->input), matModelView, matProjection);
}

MainScene::~MainScene() {
	//if (pPlayer != NULL)delete pPlayer;
	pBulletPool->Destroy();
	if (pBg != NULL) delete pBg;
	if (pCc != NULL)delete pCc;
	//if (pShushu != NULL)delete pShushu;
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

//void MainScene::CheckBulletAndCharacter() {
//	pBulletPool->CheckCollisionWithCharacter(activeCharacters);
//}


