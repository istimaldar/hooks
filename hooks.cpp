//
// Created by istimaldar on 15.06.2017.
//

#include "hooks.h"
#include "config.h"

using namespace std;

DWORD ThreadProc(CONST LPVOID lpParam) {
    unsigned long code = *((unsigned long*)lpParam);
    system(Config::getInstance()->getCommand(code));
    return 0;
}

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
    ControlKeys keys = getControlKeys();
    bool next = true;
    if (wParam == WM_KEYDOWN) {
        if (checkControl(keys)) {
            if (Config::getInstance()->hasAction(p->vkCode)) {
                next = false;
            }
        }
        if (checkShow(keys, p->vkCode)) {
            next = false;
            ShowWindow (GetConsoleWindow(), SW_SHOW);
        }
    }
    if (wParam == WM_KEYUP) {
        if (checkControl(keys)) {
            if (Config::getInstance()->hasAction(p->vkCode)) {
                next = false;
                CreateThread(NULL, 0, &ThreadProc, &p->vkCode, 0, NULL);

            }
        }
//        if (checkShow(keys, p->vkCode)) {
//            next = false;
//        }
    }
    return (next ? CallNextHookEx(NULL, nCode, wParam, lParam) : -1);
}

ControlKeys getControlKeys() {
    ControlKeys controlKeys;
    controlKeys.leftAlt = getKeyState(VK_LMENU);
    controlKeys.rightAlt = getKeyState(VK_RMENU);
    controlKeys.leftCtrl = getKeyState(VK_LCONTROL);
    controlKeys.rightCtrl = getKeyState(VK_RCONTROL);
    controlKeys.leftShift = getKeyState(VK_LSHIFT);
    controlKeys.rightShift = getKeyState(VK_RSHIFT);
    return controlKeys;
}

OneKey getKeyState(int vkCode) {
    OneKey oneKey;
    auto t_code = GetKeyState(vkCode);
    oneKey.pressed = ((t_code & 0x8000) != 0);
    oneKey.toggled = ((t_code & 0x0001) != 0);
    return oneKey;
}

ostream &operator<<(ostream &os, const OneKey &oneKey) {
    return os << oneKey.pressed << oneKey.toggled;
}

ostream &operator<<(ostream &os, const ControlKeys &controlKeys) {
    return os << controlKeys.leftShift << " " << controlKeys.rightShift << " " << controlKeys.leftCtrl << " "
              << controlKeys.rightCtrl << " " << controlKeys.leftAlt << " " << controlKeys.rightAlt;
}

bool checkControl(ControlKeys keys) {
    return  keys.leftCtrl.pressed && keys.rightCtrl.pressed;
}

bool checkShow(ControlKeys keys, unsigned long pressed) {
    return keys.leftCtrl.pressed && keys.rightCtrl.pressed && pressed == 0x39;
}
