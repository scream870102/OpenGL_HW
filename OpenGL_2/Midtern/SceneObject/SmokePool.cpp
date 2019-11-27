#include "SmokePool.h"
SmokePool* SmokePool::instance = NULL;

Smoke* SmokePool::Bomb(const vec3 position) {
	Smoke* tmp = smokePool.GetPoolObject();
	if (tmp != NULL) {
		tmp->Bomb(position);
		return tmp;
	}
	return NULL;
}

void SmokePool::Draw() {
	std::vector<Smoke*>* usingSmoke = smokePool.GetUsingObjs();
	for (int i = 0; i < (int)usingSmoke->size(); i++) {
		usingSmoke[0][i]->Draw();
	}
}

void SmokePool::Update(float delta) {
	std::vector<Smoke*>* usingSmoke = smokePool.GetUsingObjs();
	for (int i = 0; i < (int)usingSmoke->size(); i++) {
		usingSmoke[0][i]->Update(delta);
	}
}

SmokePool* SmokePool::Create(int number, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	if (instance == NULL)
		instance = new (std::nothrow)SmokePool(number, matModelView, matProjection, shaderHandle);
	return instance;
}

SmokePool* SmokePool::GetInstance() {
	if (instance == NULL)
		instance = new (std::nothrow)SmokePool();
	return instance;
}

void SmokePool::Destroy() {
	if (instance != NULL)delete instance;
}

SmokePool::SmokePool(int number, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	//Section for Init bullet to bulletPool
	for (int i = 0; i < number; i++) {
		Smoke* pSmoke = new Smoke(matModelView, matProjection, shaderHandle);
		pSmoke->poolParent = &smokePool;
		smokePool.Init(pSmoke);
	}
}

SmokePool::~SmokePool() {}
