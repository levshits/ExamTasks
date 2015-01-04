// TestForTask17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include "stdlib.h"
__declspec(dllimport) void* Create(int size);
__declspec(dllimport) void Destroy(void* obj);
__declspec(dllimport) void* ReadAt(void* obj, int index);
__declspec(dllimport) void WriteAt(void* obj, int index, void* data);



int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	void *arr = Create(10);
	for (int i = 0; i < 10; i++)
	{
		WriteAt(arr,i, (void*)(rand()));
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", (int)ReadAt(arr,i));
	}
	Destroy(arr);
	system("pause");
	return 0;
}
