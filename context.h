//
// Created by istimaldar on 16/06/2017.
//

#ifndef HOOKS_CONTEXT_H
#define HOOKS_CONTEXT_H


#include <Windows.h>

class Context {
    static HHOOK hhkLowLevelKybd;
    static HANDLE event;
    HANDLE thread;
public:
    int run();
    int stop();
    int reload();
    int hide();
    int exit();
    Context();
private:
    static DWORD WINAPI ThreadProc(CONST LPVOID lpParam);
};


#endif //HOOKS_CONTEXT_H
