//
// Created by istimaldar on 16/06/2017.
//

#include <fstream>
#include <rpc.h>
#include "config.h"
#include <iostream>

using namespace std;

Config::Config() {

}

Config *Config::getInstance() {
    static Config instance;
    return &instance;
}

void Config::load() {
    fstream file;
    unsigned long key;
    file.open("config", ios::in | ios::binary);
    char *res;
    while (!file.eof()) {
        file.read((char *) (&key), sizeof(unsigned long));
        if (hasAction(key + 0x30) && key > 8) {
            continue;
        }
        char buf;
        string result;
        do {
            file.read(&buf, sizeof(char));
            result += buf;
        } while (buf != '\n');
        res = new char[result.length() + 1];
        strcpy(res, (char *) result.c_str());
        commands[key + 0x30] = res;
    }
    file.close();
}

bool Config::hasAction(unsigned long key) {
    auto iterator = commands.find(key);
    return (iterator != commands.end());
}

char *Config::getCommand(unsigned long key) {
    return commands[key];
}
