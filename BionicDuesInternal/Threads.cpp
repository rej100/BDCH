#include "stdafx.h"

namespace Threads
{
	bool killSwitch = true;
	void Toggle()
	{
		while (killSwitch)
		{
			if (GetAsyncKeyState(VK_F1))
			{
				std::cout << "f1clicked" << std::endl;
				Options::monies = !Options::monies;
				Sleep(100);
			}
			if (GetAsyncKeyState(VK_F2))
			{
				std::cout << "cya" << std::endl;
				killSwitch = false;
			}
		}
	}
	void DrawMenu(CichyGDI* cgdi)
	{
		while (killSwitch)
		{

		}
	}
	void Main()
	{
		while (killSwitch)
		{
			if (Options::monies)
			{
				if (!Options::patched)
				{
					Options::patched = true;
				}
			}
		}
	}
	int Initialize()
	{
		CichyGDI cGDI(FindWindow(0, "Bionic Dues"));
		cGDI.Initialize();

		std::thread toggleThread(Toggle);
		std::thread menuThread(DrawMenu, &cGDI);
		std::thread mainThread(Main);

		toggleThread.join();
		menuThread.join();
		mainThread.join();

		return 0;
	}
}
