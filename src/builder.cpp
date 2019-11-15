#include "builder.h"
#include "modulos.h"

Controller* Builder::buildSistema() {
    Controller* controller = new Controller();

    IAA* maa = new MAA();
    IAU* mau = new MAU();
    IAC* mac = new MAC();
    IAR* mar = new MAR();

    ISA* msa = new MSA();
    ISU* msu = new MSU();
    ISC* msc = new MSC();
    ISR* msr = new MSR();

    msa->iaa = maa;
    msu->iau = mau;
    msc->iac = mac;
    msr->iar = mar;

    maa->controller = controller;
    mau->controller = controller;
    mac->controller = controller;
    mar->controller = controller;

    maa->servico = msa;
    mau->servico = msu;
    mac->servico = msc;
    mar->servico = msr;

    controller->maa = maa;
    controller->mau = mau;
    controller->mac = mac;
    controller->mar = mar;

    controller->isLogged = false;

    return controller;
}

void Builder::destroySistema(Controller* controller) {

    delete controller->maa->servico;
    delete controller->mau->servico;
    delete controller->mac->servico;
    delete controller->mar->servico;


    delete controller->maa;
    delete controller->mau;
    delete controller->mac;
    delete controller->mar;
}
