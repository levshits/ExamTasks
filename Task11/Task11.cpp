// Task11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include "Array.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	Array<int> *arr = new Array<int>(10);
	for (int i = 0; i < 10; i++)
	{
		arr->WriteAt(i, rand());
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n",arr->ReadAt(i));
	}
	system("pause");
	return 0;
}

