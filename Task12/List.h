#pragma once
#include <Windows.h>
#include <vector>
using namespace std;
template <class T>
class List
{
public:

	List();
	virtual ~List(){};
	T ReadAt(int index);
	void WriteAt(int index, T obj);
	void Add(T obj);
	void RemoveAt(int index);
	unsigned Length();
private:
	CRITICAL_SECTION section;
	vector<T> stdvector;
};

template <class T>
List<T>::List()
{
	InitializeCriticalSectionAndSpinCount(&section, 1000);
}

template <class T>
T List<T>::ReadAt(int index)
{
	T temp;
	EnterCriticalSection(&section);
	temp = stdvector.at(index);
	LeaveCriticalSection(&section);
	return temp;
}

template <class T>
void List<T>::WriteAt(int index, T obj)
{
	EnterCriticalSection(&section);
	stdvector.at(index) = obj;
	LeaveCriticalSection(&section);
}

template <class T>
void List<T>::Add(T obj)
{
	EnterCriticalSection(&section);
	stdvector.push_back(obj);
	LeaveCriticalSection(&section);
}
template <class T>
void List<T>::RemoveAt(int index)
{
	EnterCriticalSection(&section);
	stdvector.erase(stdvector.begin() + index);
	LeaveCriticalSection(&section);
}
template <class T>
unsigned List<T>::Length()
{
	unsigned temp = 0;
	EnterCriticalSection(&section);
	temp = stdvector.size();
	LeaveCriticalSection(&section);
	return temp;
}