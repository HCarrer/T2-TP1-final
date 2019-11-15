#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller;

#include "curses.h"
#include <string>
#include "interfaces.h"
#include "builder.h"

class Controller {
    friend class Builder;
public:
    void executar();
    void login(bool, char*);
    std::string getEmail();
    Controller();
    ~Controller();
private:
    IAA* maa;
    IAU* mau;
    IAC* mac;
    IAR* mar;
    bool isLogged;
    std::string email;
};

#endif // CONTROLLER_H
