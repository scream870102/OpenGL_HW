#pragma once
#include <queue>
template <class T>
class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();
	ObjectPool(const ObjectPool& o);
	T* GetPoolObject();
	void Recycle(T* object);
	void Init(T* object);
	bool IsEmpty();
private:
	std::queue<T*> q;
};

template<class T>
inline ObjectPool<T>::ObjectPool() {
}

template<class T>
inline ObjectPool<T>::~ObjectPool() {
	while (!q.empty())
	{
		T* obj = q.front();
		if (obj != NULL) {
			q.pop();
			delete obj;
		}
	}
}

template<class T>
inline ObjectPool<T>::ObjectPool(const ObjectPool& o) {
	q = o.q;
}

template<class T>
T* ObjectPool<T>::GetPoolObject() {
	if (q.empty())return NULL;
	T* obj = q.front();
	q.pop();
	return obj;
}


template<class T>
void ObjectPool<T>::Recycle(T* object) {
	q.push(object);
}

template<class T>
inline void ObjectPool<T>::Init(T* object){
	q.push(object);
}

template<class T>
bool ObjectPool<T>::IsEmpty() {
	return q.empty();
}