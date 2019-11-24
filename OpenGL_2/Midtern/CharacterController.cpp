#include "CharacterController.h"

CharacterController::CharacterController(int maxEnemyNum, Input* input, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	//Spawn Player
	pPlayer = new Player(INIT_PLAYER_DAMAGE, INIT_PLAYER_HEALTH, matModelView, matProjection, shaderHandle);
	pPlayer->input = input;
	enemyDie = 0;
	bBossFight = false;
	this->maxEnemyNum = maxEnemyNum;
	//Spawn enemy
	for (int i = 0; i < maxEnemyNum / (float)ENEMY_TYPE_NUM * 1.2f; i++) {
		//SECTION SHUSHU
		Enemy* shuShu = new Shushu(pPlayer,SHUSHU_DAMAGE, SHUSHU_HEALTH,
			vec3(Random::GetRand((float)WIDTH), Random::GetRand(HEIGHT / 3.0f), 0.0f)
			, matModelView, matProjection, shaderHandle
		);
		enemies.Init(shuShu);
		shuShu->poolParent = &enemies;
		//END SECTION SHUHSU

		//SECTION HAKURUMA
		Enemy* hakuruma = new Hakuruma(pPlayer, SHUSHU_DAMAGE, SHUSHU_HEALTH,
			vec3(Random::GetRand((float)WIDTH), Random::GetRand(HEIGHT / 3.0f), 0.0f)
			, matModelView, matProjection, shaderHandle
		);
		enemies.Init(hakuruma);
		hakuruma->poolParent = &enemies;
		//END SECTION HAKURUMA

		//SECTION SYABON
		Enemy* syabon = new Syabon(pPlayer, SHUSHU_DAMAGE, SHUSHU_HEALTH,
			vec3(50.0f, 50.0f, 0.0f)
			, matModelView, matProjection, shaderHandle
		);
		enemies.Init(syabon);
		syabon->poolParent = &enemies;
		//END SECTION SYABON
	}


}

CharacterController::~CharacterController() {
	if (pPlayer != NULL)delete pPlayer;
}

void CharacterController::Update(float delta) {
	std::vector<Enemy*>* usingEs = enemies.GetUsingObjs();
	//if not enter boss fight  keep sapwning enemy
	if (!bBossFight) {
		//if active enemy num is smaller than maxEnemyNum
		//spawn it from objectPool
		while ((int)usingEs->size() < maxEnemyNum) {
			Enemy* tmp = enemies.GetPoolObject();
			tmp->Init(vec3(Random::GetRand((float)WIDTH), Random::GetRand(HEIGHT / 2.0f), 0.0f), &(this->enemies));
		}
	}
	//Check Active Enemy with bullet hit
	//if getting hit recycle it
	for (int i = 0; i < (int)usingEs->size(); i++) {
		usingEs[0][i]->Update(delta);
		if (BulletPool::GetInstance()->CheckCollisionWithCharacter(usingEs[0][i])) {
			//RECYCLE THE ENEMY
			if (usingEs[0][i]->IsDead()) {
				enemyDie++;
				usingEs[0][i]->poolParent->Recycle(usingEs[0][i]);
			}
		}
	}
	//Check if bullet collision with player
	BulletPool::GetInstance()->CheckCollisionWithCharacter(pPlayer);
	//Update Player
	pPlayer->Update(delta);

}

void CharacterController::Draw() {
	//Draw Active Enemy
	std::vector<Enemy*>* usingEs = enemies.GetUsingObjs();
	for (int i = 0; i < (int)usingEs->size(); i++) {
		usingEs[0][i]->Draw();
	}
	//Draw Player
	pPlayer->Draw();

}

const int CharacterController::HowManyEnemyDie(){
	return enemyDie;
}

void CharacterController::StartBossFight(){
	Print("BOSS FIGHT");
	bBossFight = true;
}

