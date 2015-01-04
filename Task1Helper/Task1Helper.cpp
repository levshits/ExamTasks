// Task1Helper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <Tlhelp32.h>

int _tmain(int argc, _TCHAR* argv[])
{
	printf("%d %ls\n", argc, argv[0]);
	if (argc==1)
	{
		DWORD Pid = _wtoi(argv[0]);
		TCHAR* filename = (TCHAR*)malloc(sizeof(TCHAR)*MAX_PATH + 1);
		HANDLE hTH = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, Pid);

		if (hTH != INVALID_HANDLE_VALUE)
		{
			MODULEENTRY32 me = { sizeof(MODULEENTRY32) };
			if (Module32First(hTH, &me))
			{
				_stprintf(filename, L"%ls", me.szExePath);
			}
			CloseHandle(hTH);
		}
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, 0, Pid);
		WaitForSingleObject(handle, INFINITE);
		CloseHandle(handle);
		printf("%ls\n", filename);
		STARTUPINFO cif;
		ZeroMemory(&cif, sizeof(STARTUPINFO));
		PROCESS_INFORMATION pi;
		TCHAR* params = (TCHAR*)malloc(10);
		_stprintf(params, L"%d", GetCurrentProcessId());
		CreateProcess(filename, params, NULL, false, NORMAL_PRIORITY_CLASS, NULL, NULL, NULL, &cif, &pi);
		ExitProcess(0);
	}
	system("pause");
}

