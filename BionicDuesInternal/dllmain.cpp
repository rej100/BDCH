#include "stdafx.h"

void mainHack();

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)mainHack, NULL, NULL, NULL);
	}
	else if (dwReason == DLL_PROCESS_DETACH) {

	}
	return TRUE;
}


//"SUPERDITROXXL (32-bit, PCD3D_SM5)"
void mainHack()
{
	HMODULE hModule = GetModuleHandle("BionicDuesInternal.dll");
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	SetConsoleTitle("BDCH v0.02");

	CichyGDI cGDI(FindWindow(0, "Bionic Dues"));
	cGDI.Initialize();

	FreeConsole();
	FreeLibraryAndExitThread(hModule, 0);
}