//
// Created by istimaldar on 16/06/2017.
//

#ifndef HOOKS_PARSER_H
#define HOOKS_PARSER_H

#include <map>

using namespace std;

class Config {
    map<unsigned long, char*> commands;
public:
    static Config* getInstance();
    void load();
    char* getCommand(unsigned long key);
    bool hasAction(unsigned long key);
private:
    Config();
};


#endif //HOOKS_PARSER_H
