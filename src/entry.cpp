#include "includes.hpp"
#include "overlay.hpp"
#include "menu.hpp"

void main()
{
	//AllocConsole();
	//freopen("CONOUT$", "w", stdout);

	Sleep(2000);

	if (!Overlay::Begin())
	{
		std::cerr << "Failed to start overlay." << std::endl;
	
		return;
	}

	Sleep(2000);

	while (Overlay::StartRender())
	{
		if (GetAsyncKeyState(VK_SHIFT) & 1)
			Menu::open = !Menu::open;

		if (Menu::open)
		{
			SetForegroundWindow(Overlay::hwnd);
			Menu::Draw();
		}

		Overlay::EndRender();
		
		if (GetAsyncKeyState(VK_CONTROL))
			break;
	}

	Overlay::StartRender();
	Overlay::EndRender();
	Overlay::Destroy();
}

bool DllMain(void* hModule, int ul_reason_for_call, void* lpReserved) {

	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0,0);
	}
	return true;
}