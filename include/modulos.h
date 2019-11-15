#ifndef MODULOS_H
#define MODULOS_H


class MAA;
class MAU;
class MAC;
class MAR;

class MSA;
class MSU;
class MSC;
class MSR;

#include <string>
#include <vector>
#include "interfaces.h"
#include "builder.h"
#include "dominios.h"

//////////////////Modulos de Apresentacao//////////////

class MAA : public IAA {
    friend class Builder;
public:
    void executar() override;
private:
    void autenticar() override;
};


class MAU : public IAU {
    friend class Builder;
public:
    void executar() override;
    void verPerfil() override;
    void verCaronas() override;
};



class MAC : public IAC {
    friend class Builder;
public:
    void executar() override;
    void criarCarona() override;
};



class MAR : public IAR {
    friend class Builder;
public:
    void executar() override;
};



//////////////////Modulos de Servico//////////////
class MSA : public ISA {
    friend class Builder;
public:
    bool autenticar(Email&, Senha&) override;
};


class MSU : public ISU {
    friend class Builder;
public:
    bool cadastrar(Usuario&, Conta&) override;
    bool descadastrar(Email&) override;
    Usuario infoLoggedUser(std::string) override;
};

////////sadadasdasdasdasdasdasdasdasd
class MSC : public ISC {
    friend class Builder;
public:
    bool cadastrarCarona(Email&, Carona&, std::vector<Reserva>&) override;
    bool descadastrarCarona(CodigoDeCarona&) override;
    std::vector<Carona> pesquisarCarona(Cidade, Estado, Cidade, Estado, Data) override;
private:
    int dateToInt(std::string data);
};


class MSR : public ISR {
    friend class Builder;
public:
    bool reservar(Reserva&) override;
    bool cancelarReserva(Reserva&) override;
    Reserva listarReservas(CodigoDeReserva&) override;
};

#endif // MODULOS_H
