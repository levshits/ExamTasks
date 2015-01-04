#include "stdafx.h"
#include "Array.h"


Array::Array(int size)
{
	this->size = size;
	data = (void**)malloc(sizeof(void*)*size);
}


Array::~Array()
{
	free(data);
}

void* Array::ReadAt(int index)
{
	if (index < size)
		return data[index];
	else 
		return nullptr;
}
void Array::WriteAt(int index, void* obj)
{
	if (index < size)
		data[index] = obj;
}
