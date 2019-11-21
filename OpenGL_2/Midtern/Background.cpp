#include "Background.h"

Background::Background(int number, mat4& matModelView, mat4& matProjection, GLuint shaderHandle){
	for (int i = 0; i < number; i++)	{
		Star* pStar = new Star(STAR_SPEED,matModelView, matProjection, shaderHandle);
		pStar->poolParent = &_starPool;
		_starPool.Init(pStar);
	}
}

Background::~Background(){}

void Background::Draw(){
	std::vector<Star*>* usingStars = _starPool.GetUsingObjs();
	for (int i = 0; i < (int)usingStars->size(); i++) {
		usingStars[0][i]->Draw();
	}
}

void Background::Update(float delta){
	std::vector<Star*>* usingStars = _starPool.GetUsingObjs();
	//if star at playGround is lower than MAX_NUM get it and set random position and speed for i
	if ((int)usingStars->size() < MAX_STAR_NUM) {
		Star* tmp = _starPool.GetPoolObject();
		if (tmp != NULL)
			tmp->Init(vec3(Random::GetRand(WIDTH),Random::GetRand(HEIGHT), 0.0f));
	}
	for (int i = 0; i < (int)usingStars->size(); i++) {
		usingStars[0][i]->Update(delta);
	}
}
