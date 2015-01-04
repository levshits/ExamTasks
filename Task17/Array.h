#pragma once
#include "stdlib.h"
class Array
{
public:
	Array(int size);
	virtual ~Array();
	void WriteAt(int index, void* data);
	void* ReadAt(int index);
private:
	void** data;
	int size;
};

