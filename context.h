//
// Created by istimaldar on 16/06/2017.
//

#ifndef HOOKS_CONTEXT_H
#define HOOKS_CONTEXT_H


class Context {
public:
    Context& getInstance();
    void run();
private:
    Context();
};


#endif //HOOKS_CONTEXT_H
