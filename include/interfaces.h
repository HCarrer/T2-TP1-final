#ifndef INTERFACES_H
#define INTERFACES_H

class IAA;
class IAU;
class IAC;
class IAR;

class ISA;
class ISU;
class ISC;
class ISR;


#include <string>
#include <iostream>
#include <vector>

#include "dominios.h"
#include "entidades.h"
#include "controller.h"
#include "builder.h"


class IAA {
    friend class Builder;
public:
    virtual void executar() = 0;
    virtual ~IAA() {}
private:

    virtual void autenticar() = 0;
protected:
    Controller* controller = nullptr;
    ISA* servico = nullptr;
};


class IAU {
    friend class Builder;
public:
    virtual void executar() = 0;
    virtual void verPerfil() = 0;
    virtual void verCaronas() = 0;
    virtual ~IAU(){}
protected:
    Controller* controller = nullptr;
    ISU* servico = nullptr;
};

class IAC {
    friend class Builder;
public:
    virtual void executar() = 0;
    virtual void criarCarona() = 0;
    virtual ~IAC(){}
protected:
    Controller* controller = nullptr;
    ISC* servico = nullptr;
};

class IAR {
    friend class Builder;
public:
    virtual void executar() = 0;
    virtual ~IAR(){}
protected:
    Controller* controller = nullptr;
    ISR* servico = nullptr;
};





class ISA {
    friend class Builder;
public:
    virtual bool autenticar(Email&, Senha&) = 0;
    virtual ~ISA(){}
protected:
    IAA* iaa = nullptr;
};

class ISU {
    friend class Builder;
public:
    virtual bool cadastrar(Usuario&, Conta&) = 0;
    virtual bool descadastrar(Email&) = 0;
    virtual Usuario infoLoggedUser(std::string) = 0;
    virtual ~ISU(){}
protected:
    IAU* iau = nullptr;
};

class ISC {
    friend class Builder;
public:
    virtual bool cadastrarCarona(Email&, Carona&, std::vector<Reserva>&) = 0;
    virtual bool descadastrarCarona(CodigoDeCarona&) = 0;
    virtual std::vector<Carona> pesquisarCarona(Cidade, Estado, Cidade, Estado, Data) = 0;
    virtual ~ISC(){}
protected:
    IAC* iac = nullptr;
};

class ISR {
    friend class Builder;
public:
    virtual bool reservar(Reserva&) = 0;
    virtual bool cancelarReserva(Reserva&) = 0;
    virtual Reserva listarReservas(CodigoDeReserva&) = 0;
    virtual ~ISR(){}
protected:
    IAR* iar = nullptr;
};

#endif // INTERFACES_H
