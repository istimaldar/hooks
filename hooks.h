//
// Created by istimaldar on 15.06.2017.
//

#ifndef HOOKS_HOOKS_H
#define HOOKS_HOOKS_H
#include <Windows.h>
#include <iostream>

typedef struct OneKey {
    bool pressed;
    bool toggled;
} OneKey;

typedef struct ControlKeys {

} ControlKeys;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);


#endif //HOOKS_HOOKS_H
