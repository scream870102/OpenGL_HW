#include "BulletPool.h"
BulletPool* BulletPool::_instance = NULL;

BulletPool::BulletPool(int number, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	//Section for Init bullet to bulletPool
	for (int i = 0; i < number; i++)
	{
		Bullet* pBullet = new Bullet(matModelView, matProjection, shaderHandle);
		pBullet->poolParent = &_bulletPool;
		_bulletPool.Init(pBullet);
	}
}

BulletPool::~BulletPool() {}

BulletPool* BulletPool::Create(int number, mat4& matModelView, mat4& matProjection, GLuint shaderHandle){
	if (_instance == NULL) {
		_instance = new (std::nothrow)BulletPool(number,matModelView,matProjection,shaderHandle);
	}
	return _instance;
}

BulletPool* BulletPool::GetInstance() {
	if (_instance == NULL) {
		_instance = new (std::nothrow)BulletPool();
	}
	return _instance;
}

void BulletPool::Destroy() {
	if (_instance != NULL)delete _instance;
}

bool BulletPool::Fire(int type,vec3 position,float speed){
	Bullet* tmp = _bulletPool.GetPoolObject();
	if (tmp != NULL) {
		tmp->Fire(type, position, speed);
		return true;
	}
	return false;
}

void BulletPool::Draw() {
	std::vector<Bullet*>* usingBullets = _bulletPool.GetUsingObjs();
	for (int i = 0; i < (int)usingBullets->size(); i++) {
		usingBullets[0][i]->Draw();
	}
}

void BulletPool::Update(float delta) {
	std::vector<Bullet*>* usingBullets = _bulletPool.GetUsingObjs();
	for (int i = 0; i < (int)usingBullets->size(); i++)
	{
		usingBullets[0][i]->Update(delta);
	}
}
