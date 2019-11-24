#include "BulletPool.h"
BulletPool* BulletPool::_instance = NULL;

BulletPool::BulletPool(int number, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	//Section for Init bullet to bulletPool
	for (int i = 0; i < number; i++){
		Bullet* pBullet = new Bullet(matModelView, matProjection, shaderHandle);
		pBullet->poolParent = &_bulletPool;
		_bulletPool.Init(pBullet);
	}
	for (int i = 0; i < number/2; i++)	{
		TracingBullet* pTBullet = new TracingBullet(matModelView, matProjection, shaderHandle);
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//CHECK
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!
		pTBullet->poolParent = (ObjectPool<Bullet>*)&_tBulletPool;
		_tBulletPool.Init(pTBullet);
	}
}

BulletPool::~BulletPool() {}

Bullet* BulletPool::Fire(int type, vec3 position, vec3 direction, float speed, int damage) {
	Bullet* tmp = _bulletPool.GetPoolObject();
	if (tmp != NULL) {
		//cause 2d game make sure won't set z value
		vec3 nDirection = vec3(direction);
		nDirection.z = 0;
		tmp->Fire(type, position,nDirection, speed, damage);
		return tmp;
	}
	return NULL;
}

Bullet* BulletPool::FireTB(int type, vec3 position, vec3 direction, float speed, int damage, Transform* target,int tracingTime){
	TracingBullet* tmp = _tBulletPool.GetPoolObject();
	if (tmp != NULL) {
		tmp->Fire(type, position, direction, speed, damage,target,tracingTime);
		return tmp;
	}
	return NULL;
}

void BulletPool::Draw() {
	std::vector<Bullet*>* usingBullets = _bulletPool.GetUsingObjs();
	for (int i = 0; i < (int)usingBullets->size(); i++) {
		usingBullets[0][i]->Draw();
	}
	std::vector<TracingBullet*>* usingTBullets = _tBulletPool.GetUsingObjs();
	for (int i = 0; i < (int)usingTBullets->size(); i++) {
		usingTBullets[0][i]->Draw();
	}
}

void BulletPool::Update(float delta) {
	std::vector<Bullet*>* usingBullets = _bulletPool.GetUsingObjs();
	for (int i = 0; i < (int)usingBullets->size(); i++)	{
		usingBullets[0][i]->Update(delta);
	}
	std::vector<TracingBullet*>* usingTBullets = _tBulletPool.GetUsingObjs();
	for (int i = 0; i < (int)usingTBullets->size(); i++) {
		usingTBullets[0][i]->Update(delta);
	}
}


bool BulletPool::CheckCollisionWithCharacter(Character* character) {
	std::vector<Bullet*>* usingBullets = _bulletPool.GetUsingObjs();
	for (int j = 0; j < (int)usingBullets->size(); j++) {
		if (character->type != usingBullets[0][j]->GetType()) {
			bool bCollide = character->IsCollide(usingBullets[0][j]->GetCollider());
			if (bCollide) {
				character->TakeDamage(usingBullets[0][j]->GetDamage());
				usingBullets[0][j]->poolParent->Recycle(usingBullets[0][j]);
				return true;
			}
		}
	}
	std::vector<TracingBullet*>* usingTBullets = _tBulletPool.GetUsingObjs();
	for (int j = 0; j < (int)usingTBullets->size(); j++) {
		if (character->type != usingTBullets[0][j]->GetType()) {
			bool bCollide = character->IsCollide(usingTBullets[0][j]->GetCollider());
			if (bCollide) {
				character->TakeDamage(usingTBullets[0][j]->GetDamage());
				usingTBullets[0][j]->poolParent->Recycle(usingTBullets[0][j]);
				return true;
			}
		}
	}
	return false;
}

BulletPool* BulletPool::Create(int number, mat4& matModelView, mat4& matProjection, GLuint shaderHandle) {
	if (_instance == NULL) {
		_instance = new (std::nothrow)BulletPool(number, matModelView, matProjection, shaderHandle);
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

