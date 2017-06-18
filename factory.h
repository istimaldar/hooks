//
// Created by istimaldar on 18/06/2017.
//

#ifndef HOOKS_FACTORY_H
#define HOOKS_FACTORY_H

#include <map>
#include <string>
#include "context.h"

using namespace std;

typedef int(Context::*function)();

class Factory {
    map<string, function> commands;
    Context context;
public:
    static Factory* getInstance();
    int execute(string command);
private:
    Factory();
};


#endif //HOOKS_FACTORY_H
