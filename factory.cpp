//
// Created by istimaldar on 18/06/2017.
//

#include "factory.h"

Factory::Factory() {
    commands["run"] = &Context::run;
    commands["hide"] = &Context::hide;
    commands["stop"] = &Context::stop;
    commands["reload"] = &Context::reload;
    commands["exit"] = &Context::exit;
}

int Factory::execute(string command) {
    function com = commands[command];
    return (context.*com)();
}

Factory *Factory::getInstance() {
    static Factory instance;
    return &instance;
}
