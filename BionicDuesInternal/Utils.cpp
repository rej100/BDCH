#include "stdafx.h"

DWORD Utils::calcPointer(int pointerLevel, DWORD baseAddress, DWORD offsets[])
{
	DWORD ptr = *(DWORD*)(baseAddress);
	if (ptr == 0)
		return NULL;
	for (int i = 0; i < pointerLevel; ++i)
	{
		if (i == pointerLevel - 1)
		{
			ptr = (DWORD)(ptr + offsets[i]);
			if (ptr == 0)
				return NULL;
			return ptr;
		}
		else
		{
			ptr = *(DWORD*)(ptr + offsets[i]);
			if (ptr == 0)
				return NULL;
		}
	}
	return ptr;
}

MODULEINFO Utils::GetModuleInfo(char *szModule)
{
	MODULEINFO modinfo = { 0 };
	HMODULE hModule = GetModuleHandle(szModule);
	if (hModule == 0)
		return modinfo;
	GetModuleInformation(GetCurrentProcess(), hModule, &modinfo, sizeof(MODULEINFO));
	return modinfo;
}

void Utils::WriteToMemory(uintptr_t addressToWrite, char* valueToWrite, int byteNum)
{
	unsigned long OldProtection;
	VirtualProtect((LPVOID)(addressToWrite), byteNum, PAGE_EXECUTE_READWRITE, &OldProtection);

	memcpy((LPVOID)addressToWrite, valueToWrite, byteNum);

	VirtualProtect((LPVOID)(addressToWrite), byteNum, OldProtection, NULL);
}

DWORD Utils::FindPattern(char *module, char *pattern, char *mask)
{
	MODULEINFO mInfo = GetModuleInfo(module);

	DWORD base = (DWORD)mInfo.lpBaseOfDll;
	DWORD size = (DWORD)mInfo.SizeOfImage;

	DWORD patternLength = (DWORD)strlen(mask);

	for (DWORD i = 0; i < size - patternLength; i++)
	{
		bool found = true;
		for (DWORD j = 0; j < patternLength; j++)
		{
			found &= mask[j] == '?' || pattern[j] == *(char*)(base + i + j);
		}
		if (found)
		{
			return base + i;
		}
	}

	return NULL;
}