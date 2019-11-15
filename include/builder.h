#ifndef BUILDER_H
#define BUILDER_H

class Builder;

#include "interfaces.h"
// #include "controller.h"

class Builder {
public:
    static Controller* buildSistema();
    static void destroySistema(Controller*);
};

#endif // BUILDER_H
