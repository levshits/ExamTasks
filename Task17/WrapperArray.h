#pragma once
#include "windows.h"

__declspec(dllexport) void* Create(int size);
__declspec(dllexport) void Destroy(void* obj);
__declspec(dllexport) void* ReadAt(void* obj, int index);
__declspec(dllexport) void WriteAt(void* obj, int index, void* data);