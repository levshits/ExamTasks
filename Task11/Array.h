#pragma once
#include "windows.h"
template <class T>
class Array
{
private:
	T* data;
	int size = 0;
	CRITICAL_SECTION section;
public:
	Array(int size);
	virtual ~Array<T>();
	T ReadAt(int index);
	void WriteAt(int index, T obj);
};

template <class T>
Array<T>::Array(int size)
{
	data = (T*)malloc(sizeof(T)*size);
	this->size = size;
	InitializeCriticalSectionAndSpinCount(&section, 1000);
}

template <class T>
Array<T> ::~Array()
{
	free(data);
}

template <class T>
T Array<T> ::ReadAt(int index)
{
	T temp;
	if (index < size)
	{
		EnterCriticalSection(&section);
		temp = data[index];
		LeaveCriticalSection(&section);
	}
	return temp;
	// стоило бы добавить порождение исключения
}
template <class T>
void Array<T>::WriteAt(int index, T obj)
{
	if (index < size)
	{
		EnterCriticalSection(&section);
		data[index] = obj;
		LeaveCriticalSection(&section);
	}
	// стоило бы добавить порождение исключения
}

