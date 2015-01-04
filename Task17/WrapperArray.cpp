#include "stdafx.h"
#include "WrapperArray.h"
#include "Array.h"
void* Create(int size)
{
	return (void*)(new Array(size));
}
void Destroy(void* obj)
{
	delete (Array*)(obj);
}
void* ReadAt(void* obj, int index)
{
	return ((Array*)(obj))->ReadAt(index);
}
void WriteAt(void* obj, int index, void* data)
{
	((Array*)(obj))->WriteAt(index, data);
}