//
// Created by istimaldar on 15.06.2017.
//

#ifndef HOOKS_HOOKS_H
#define HOOKS_HOOKS_H
#include <Windows.h>
#include <iostream>
#include <ostream>

using namespace std;

typedef struct OneKey {
    bool pressed;
    bool toggled;
    friend ostream& operator<<(ostream& os, const OneKey& oneKey);
} OneKey;

typedef struct ControlKeys {
    OneKey leftShift;
    OneKey rightShift;
    OneKey leftCtrl;
    OneKey rightCtrl;
    OneKey leftAlt;
    OneKey rightAlt;
    friend ostream& operator<<(ostream& os, const ControlKeys& controlKeys);
} ControlKeys;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
ControlKeys getControlKeys();
OneKey getKeyState(int vkCode);
bool checkControl(ControlKeys keys);
bool checkShow(ControlKeys keys, unsigned long pressed);

#endif //HOOKS_HOOKS_H
