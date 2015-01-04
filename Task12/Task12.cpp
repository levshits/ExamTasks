// Task11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include "List.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	List<int> *arr = new List<int>();
	for (int i = 0; i < 10; i++)
	{
		arr->Add(rand());
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr->ReadAt(i));
	}
	for (int i = 0; i < arr->Length(); i++)
	{
		if (rand()%2==0)
			arr->RemoveAt(i);
	}
	for (int i = 0; i < arr->Length(); i++)
	{
		printf("%d\n", arr->ReadAt(i));
	}
	system("pause");
	return 0;
}

