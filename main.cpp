#include <iostream>
#include <Windows.h>
#include "factory.h"

using namespace std;
int main()
{
    int exit = 0;
    while (!exit) {
        string command;
        cin >> command;
        exit = Factory::getInstance()->execute(command);
    }
    return 0;
}