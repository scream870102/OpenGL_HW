#pragma once
#ifndef _OBJECT_POOL_H_
#define _OBJECT_POOL_H_


#include <queue>
#include <vector>
#include <algorithm>
template <class T>
class ObjectPool
{
private:
public:
	ObjectPool();
	~ObjectPool();
	ObjectPool(const ObjectPool& o);
	const ObjectPool& operator=(const ObjectPool& b);
	T* GetPoolObject();
	void Recycle(T* object);
	void Init(T* object);
	bool IsEmpty();
	std::vector<T*>* GetUsingObjs();
private:
	std::queue<T*> q;
	std::vector<T*> v;
public:
};
//#include "ObjectPool.cpp"
//#endif

template<class T>
T* ObjectPool<T>::GetPoolObject() {
	if (q.empty())return NULL;
	T* obj = q.front();
	q.pop();
	v.push_back(obj);
	return obj;
}


template<class T>
void ObjectPool<T>::Recycle(T* object) {
	std::vector<T*>::iterator it = std::find(v.begin(), v.end(), object);
	if (it != v.end()) {
		//Get the index by using distance
		int index = std::distance(v.begin(), it);
		v.erase(v.begin() + index);
		q.push(object);
	}
}

template<class T>
void ObjectPool<T>::Init(T* object) {
	q.push(object);
}

template<class T>
bool ObjectPool<T>::IsEmpty() {
	return q.empty();
}

template<class T>
std::vector<T*>* ObjectPool<T>::GetUsingObjs() {
	return &v;
}

template<class T>
ObjectPool<T>::ObjectPool() {}

template<class T>
ObjectPool<T>::~ObjectPool() {
	while (!q.empty())
	{
		T* obj = q.front();
		if (obj != NULL) {
			q.pop();
			delete obj;
		}
	}
	for (int i = 0; i < (int)v.size(); i++)
	{
		if (v[i] != NULL) {
			delete v[i];
		}
	}
	v.clear();
}

template<class T>
ObjectPool<T>::ObjectPool(const ObjectPool& o) {
	q = new std::queue<T*>(o.q);
	v = new std::vector<T*>(o.v);
}

template<class T>
const ObjectPool<T>& ObjectPool<T>::operator=(const ObjectPool& b) {
	if (&b != this) {
		while (!q.empty())
		{
			T* obj = q.front();
			if (obj != NULL) {
				q.pop();
				delete obj;
			}
		}
		for (int i = 0; i < (int)v.size(); i++)
		{
			if (v[i] != NULL) {
				delete v[i];
			}
		}
		v.clear();
		q = new std::queue<T*>(o.q);
		v = new std::vector<T*>(o.v);
	}
	return *this;
}
#endif // !_OBJECT_POOL_H_