//Copyright Henrique Carrer e Guilherme Fleury

#ifndef TESTES_H
#define TESTES_H
#include "dominios.h"


#define SUCESSO 1
#define FALHA 0

class TUAssento {
private:
    const std::string VALOR_VALIDO   = "D";
    const std::string VALOR_INVALIDO = "K";

    Assento *codigo;         // Referencia para o objeto a ser testado.

    int estado;             // Estado do teste.

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUBagagem
{
private:
    const int VALOR_VALIDO = 2;
    const int VALOR_INVALIDO = 7;

    Bagagem *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUCodigoDeBanco
{
    private:
    const std::string VALOR_VALIDO = "123";
    const std::string VALOR_INVALIDO = "123456";

    CodigoDeBanco *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUCodigoDeCarona
{
    private:
    const std::string VALOR_VALIDO = "1234";
    const std::string VALOR_INVALIDO = "1234567";

    CodigoDeCarona *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUCodigoDeReserva
{
    private:
    const std::string VALOR_VALIDO = "12345";
    const std::string VALOR_INVALIDO = "12345678";

    CodigoDeReserva *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUCidade
{
private:
    const std::string VALOR_VALIDO = "Brasilia";
    const std::string VALOR_INVALIDO = "Sao   Paulo";

    Cidade *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUCPF
{
private:
    const std::string VALOR_VALIDO = "03221975112";
    const std::string VALOR_INVALIDO = "06923697152";

    CPF *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUData
{
private:
    const std::string VALOR_VALIDO = "31/10/2019";
    const std::string VALOR_INVALIDO = "42/13/2010";

    Data *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUDuracao
{
private:
    const int VALOR_VALIDO = 20;
    const int VALOR_INVALIDO = 2500;

    Duracao *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUEstado
{
private:
    const std::string VALOR_VALIDO = "DF";
    const std::string VALOR_INVALIDO = "NY";

    Estado *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUEmail
{
private:
    const std::string VALOR_VALIDO = "local@dominio";
    const std::string VALOR_INVALIDO = "emailsemdominio";

    Email *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUNome
{
private:
    const std::string VALOR_VALIDO = "Fernando Chacon";
    const std::string VALOR_INVALIDO = "J.  K.  Rowling";

    Nome *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUNumeroDeAgencia
{
private:
    const std::string VALOR_VALIDO = "12344";
    const std::string VALOR_INVALIDO = "12340";

    NumeroDeAgencia *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUNumeroDeConta
{
private:
    const std::string VALOR_VALIDO = "1234566";
    const std::string VALOR_INVALIDO = "1234560";

    NumeroDeConta *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUPreco
{
private:
    const double VALOR_VALIDO = 2500.32;
    const double VALOR_INVALIDO = 100000;

    Preco *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUTelefone
{
private:
    const std::string VALOR_VALIDO = "5561981419871";
    const std::string VALOR_INVALIDO = "0032123456789";

    Telefone *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUSenha
{
private:
    const std::string VALOR_VALIDO = "a1#$%";
    const std::string VALOR_INVALIDO = "aa##2";

    Senha *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};



class TUVaga
{
private:
    const int VALOR_VALIDO = 2;
    const int VALOR_INVALIDO = 31;

    Vaga *codigo;

    int estado;

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    int run();
};
#endif // TESTES_H
