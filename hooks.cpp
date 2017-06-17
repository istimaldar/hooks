//
// Created by istimaldar on 15.06.2017.
//

#include "hooks.h"
using namespace std;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
    static bool isLeftShiftPressed = false;
    static bool isRightShiftPressed = false;
    static bool isAltPressed = false;
    static bool isCtrlPressed = false;
    bool next = true;
    auto t_code = GetKeyState(VK_LSHIFT);
    if (wParam == WM_KEYDOWN) {
        switch (p->vkCode) {
            case 0x44:
                next = false;
                break;
            default:
                //cout << p->vkCode  << endl;
                break;
        }
    }
    if (wParam == WM_KEYUP) {
        switch (p->vkCode) {
            case 0x44:
                cout << ((t_code & 0x8000) != 0) << ((t_code & 0x0001) != 0) << endl;
                next = false;
                break;
            default:
                //cout << p->vkCode  << endl;
                break;
        }
    }
    return (next ? CallNextHookEx(NULL, nCode, wParam, lParam) : -1);
}
