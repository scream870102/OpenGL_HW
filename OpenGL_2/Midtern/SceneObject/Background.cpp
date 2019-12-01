#include "Background.h"

void Background::Draw() {
	std::vector<Star*>* usingStars = _starPool.GetUsingObjs();
	for (int i = 0; i < (int)usingStars->size(); i++) {
		usingStars[0][i]->Draw();
	}
}

void Background::Update(float delta) {
	GenerateStar();
	//Update Using Star
	std::vector<Star*>* usingStars = _starPool.GetUsingObjs();
	for (int i = 0; i < (int)usingStars->size(); i++) {
		usingStars[0][i]->Update(delta);
	}
}

void Background::StartBossFight() {
	bBossFight = true;
}

void Background::GenerateStar() {
	std::vector<Star*>* usingStars = _starPool.GetUsingObjs();
	//if star at playGround is lower than MAX_NUM get it and set random position and speed for i
	if ((int)usingStars->size() < MAX_STAR_NUM) {
		Star* tmp = _starPool.GetPoolObject();
		if (tmp != NULL) {
			tmp->Init(vec3(Random::GetRand((float)WIDTH),
				Random::GetRand(HEIGHT / 1.5f), 0.0f),
				bBossFight ? (Random::GetRand(MAX_STAR_BOSS_SPEED, MIN_STAR_BOSS_SPEED)) : (Random::GetRand(MAX_STAR_SPEED, MIN_STAR_SPEED)),
				vec3(Random::GetRand(MAX_STAR_SCALE, MIN_STAR_SCALE)));
			tmp->SetColor(vec4(1.0f, 1.0f, 1.0f, Random::GetRand(MAX_STAR_ALPHA, MIN_STAR_ALPHA)));
			tmp->SetRotation(Random::GetRand(MAX_STAR_ROTATE_SPEED, MIN_STAR_ROTATE_SPEED), Random::GetRandBool());
		}
	}
}

Background::Background(int number, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	for (int i = 0; i < number; i++) {
		Star* pStar = new Star(MIN_STAR_SPEED, MIN_STAR_ROTATE_SPEED, false, matModelView, matProjection, shaderHandle);
		pStar->poolParent = &_starPool;
		_starPool.Init(pStar);
	}
	bBossFight = false;
}

Background::~Background() {}
