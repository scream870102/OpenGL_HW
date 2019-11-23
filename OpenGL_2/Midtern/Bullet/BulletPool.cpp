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

Bullet* BulletPool::Fire(int type, vec3 position, float speed, int damage) {
	Bullet* tmp = _bulletPool.GetPoolObject();
	if (tmp != NULL) {
		tmp->Fire(type, position, speed, damage);
		return tmp;
	}
	return NULL;
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


void BulletPool::CheckCollisionWithCharacter(const std::vector<Character*> characters) {
	std::vector<Bullet*>* usingBullets = _bulletPool.GetUsingObjs();
	for (int i = 0; i < (int)characters.size(); i++)
	{
		for (int j = 0; j < (int)usingBullets->size(); j++) {
			if (characters[i]->type != usingBullets[0][j]->GetType()) {
				bool bCollide = characters[i]->IsCollide(usingBullets[0][j]->GetCollider());
				if (bCollide) {
					characters[i]->TakeDamage(usingBullets[0][j]->GetDamage());
					usingBullets[0][j]->poolParent->Recycle(usingBullets[0][j]);
				}
			}
		}
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


