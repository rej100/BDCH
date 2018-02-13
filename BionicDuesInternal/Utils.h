#include <Windows.h>
#include <Psapi.h>

namespace Utils
{
	DWORD calcPointer(int pointerLevel, DWORD baseAddress, DWORD offsets[]);
	MODULEINFO GetModuleInfo(char *szModule);
	void WriteToMemory(uintptr_t addressToWrite, char* valueToWrite, int byteNum);
	DWORD FindPattern(char *module, char *pattern, char *mask);
}