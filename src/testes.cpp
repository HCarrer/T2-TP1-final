//Copyright Henrique Carrer e Guilherme Fleury

#include <string>
#include <iostream>
#include "testes.h"

/////////////Metodos da classe TUAssento//////////////
void TUAssento::setUp()
{
    codigo = new Assento();
    estado = SUCESSO;
}

void TUAssento::tearDown()
{
    delete codigo;
}

void TUAssento::testarCenarioSucesso()
{
    try{
        codigo->setAssento(VALOR_VALIDO);
        if (codigo->getAssento() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Assento" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Assento" << std::endl;
        estado = FALHA;
    }
}

void TUAssento::testarCenarioFalha()
{
    try{
        codigo->setAssento(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Assento" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUAssento::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUBagagem//////////////
void TUBagagem::setUp()
{
    codigo = new Bagagem();
    estado = SUCESSO;
}

void TUBagagem::tearDown()
{
    delete codigo;
}

void TUBagagem::testarCenarioSucesso()
{
    try{
        codigo->setBagagem(VALOR_VALIDO);
        if (codigo->getBagagem() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Bagagem" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Bagagem" << std::endl;
        estado = FALHA;
    }
}

void TUBagagem::testarCenarioFalha()
{
    try{
        codigo->setBagagem(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Bagagem" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUBagagem::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUCodigoDeBanco//////////////
void TUCodigoDeBanco::setUp()
{
    codigo = new CodigoDeBanco;
    estado = SUCESSO;
}

void TUCodigoDeBanco::tearDown()
{
    delete codigo;
}

void TUCodigoDeBanco::testarCenarioSucesso()
{
    try{
        codigo->setCodigoDeBanco(VALOR_VALIDO);
        if (codigo->getCodigoDeBanco() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Codigo de Banco" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Codigo de Banco" << std::endl;
        estado = FALHA;
    }
}

void TUCodigoDeBanco::testarCenarioFalha()
{
    try{
        codigo->setCodigoDeBanco(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Codigo de Banco" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUCodigoDeBanco::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUCodigoDeCarona//////////////
void TUCodigoDeCarona::setUp()
{
    codigo = new CodigoDeCarona;
    estado = SUCESSO;
}

void TUCodigoDeCarona::tearDown()
{
    delete codigo;
}

void TUCodigoDeCarona::testarCenarioSucesso()
{
    try{
        codigo->setCodigoDeCarona(VALOR_VALIDO);
        if (codigo->getCodigoDeCarona() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Codigo de Carona" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Codigo de Carona" << std::endl;
        estado = FALHA;
    }
}

void TUCodigoDeCarona::testarCenarioFalha()
{
    try{
        codigo->setCodigoDeCarona(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Codigo de Carona" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUCodigoDeCarona::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUCodigoDeReserva//////////////
void TUCodigoDeReserva::setUp()
{
    codigo = new CodigoDeReserva;
    estado = SUCESSO;
}

void TUCodigoDeReserva::tearDown()
{
    delete codigo;
}

void TUCodigoDeReserva::testarCenarioSucesso()
{
    try{
        codigo->setCodigoDeReserva(VALOR_VALIDO);
        if (codigo->getCodigoDeReserva() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Codigo de Reserva" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Codigo de Reserva" << std::endl;
        estado = FALHA;
    }
}

void TUCodigoDeReserva::testarCenarioFalha()
{
    try{
        codigo->setCodigoDeReserva(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Codigo de Reserva" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUCodigoDeReserva::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUCidade//////////////
void TUCidade::setUp()
{
    codigo = new Cidade;
    estado = SUCESSO;
}

void TUCidade::tearDown()
{
    delete codigo;
}

void TUCidade::testarCenarioSucesso()
{
    try{
        codigo->setCidade(VALOR_VALIDO);
        if (codigo->getCidade() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Cidade" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Cidade" << std::endl;
        estado = FALHA;
    }
}

void TUCidade::testarCenarioFalha()
{
    try{
        codigo->setCidade(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Cidade" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUCidade::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUCPF//////////////
void TUCPF::setUp()
{
    codigo = new CPF;
    estado = SUCESSO;
}

void TUCPF::tearDown()
{
    delete codigo;
}

void TUCPF::testarCenarioSucesso()
{
    try{
        codigo->setCPF(VALOR_VALIDO);
        if (codigo->getCPF() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de CPF" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de CPF" << std::endl;
        estado = FALHA;
    }
}

void TUCPF::testarCenarioFalha()
{
    try{
        codigo->setCPF(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de CPF" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUCPF::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUData//////////////
void TUData::setUp()
{
    codigo = new Data;
    estado = SUCESSO;
}

void TUData::tearDown()
{
    delete codigo;
}

void TUData::testarCenarioSucesso()
{
    try{
        codigo->setData(VALOR_VALIDO);
        if (codigo->getData() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Data" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Data" << std::endl;
        estado = FALHA;
    }
}

void TUData::testarCenarioFalha()
{
    try{
        codigo->setData(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Data" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUData::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUDuracao//////////////
void TUDuracao::setUp()
{
    codigo = new Duracao;
    estado = SUCESSO;
}

void TUDuracao::tearDown()
{
    delete codigo;
}

void TUDuracao::testarCenarioSucesso()
{
    try{
        codigo->setDuracao(VALOR_VALIDO);
        if (codigo->getDuracao() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Duracao" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Duracao" << std::endl;
        estado = FALHA;
    }
}

void TUDuracao::testarCenarioFalha()
{
    try{
        codigo->setDuracao(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Duracao" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUDuracao::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUEstado//////////////
void TUEstado::setUp()
{
    codigo = new Estado;
    estado = SUCESSO;
}

void TUEstado::tearDown()
{
    delete codigo;
}

void TUEstado::testarCenarioSucesso()
{
    try{
        codigo->setEstado(VALOR_VALIDO);
        if (codigo->getEstado() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Estado" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Estado" << std::endl;
        estado = FALHA;
    }
}

void TUEstado::testarCenarioFalha()
{
    try{
        codigo->setEstado(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Estado" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUEstado::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUEmail//////////////
void TUEmail::setUp()
{
    codigo = new Email;
    estado = SUCESSO;
}

void TUEmail::tearDown()
{
    delete codigo;
}

void TUEmail::testarCenarioSucesso()
{
    try{
        codigo->setEmail(VALOR_VALIDO);
        if (codigo->getEmail() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Email" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Email" << std::endl;
        estado = FALHA;
    }
}

void TUEmail::testarCenarioFalha()
{
    try{
        codigo->setEmail(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Email" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUEmail::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUNome//////////////
void TUNome::setUp()
{
    codigo = new Nome;
    estado = SUCESSO;
}

void TUNome::tearDown()
{
    delete codigo;
}

void TUNome::testarCenarioSucesso()
{
    try{
        codigo->setNome(VALOR_VALIDO);
        if (codigo->getNome() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Nome" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Nome" << std::endl;
        estado = FALHA;
    }
}

void TUNome::testarCenarioFalha()
{
    try{
        codigo->setNome(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Nome" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUNome::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUNumeroDeAgencia//////////////
void TUNumeroDeAgencia::setUp()
{
    codigo = new NumeroDeAgencia;
    estado = SUCESSO;
}

void TUNumeroDeAgencia::tearDown()
{
    delete codigo;
}

void TUNumeroDeAgencia::testarCenarioSucesso()
{
    try{
        codigo->setNumeroDeAgencia(VALOR_VALIDO);
        if (codigo->getNumeroDeAgencia() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Numero de Agencia" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Numero de Agencia" << std::endl;
        estado = FALHA;
    }
}

void TUNumeroDeAgencia::testarCenarioFalha()
{
    try{
        codigo->setNumeroDeAgencia(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Numero de Agencia" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUNumeroDeAgencia::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUNumeroDeConta//////////////
void TUNumeroDeConta::setUp()
{
    codigo = new NumeroDeConta;
    estado = SUCESSO;
}

void TUNumeroDeConta::tearDown()
{
    delete codigo;
}

void TUNumeroDeConta::testarCenarioSucesso()
{
    try{
        codigo->setNumeroDeConta(VALOR_VALIDO);
        if (codigo->getNumeroDeConta() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Numero de Conta" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Numero de Conta" << std::endl;
        estado = FALHA;
    }
}

void TUNumeroDeConta::testarCenarioFalha()
{
    try{
        codigo->setNumeroDeConta(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Numero de Conta" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUNumeroDeConta::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUPreco//////////////
void TUPreco::setUp()
{
    codigo = new Preco;
    estado = SUCESSO;
}

void TUPreco::tearDown()
{
    delete codigo;
}

void TUPreco::testarCenarioSucesso()
{
    try{
        codigo->setPreco(VALOR_VALIDO);
        if (codigo->getPreco() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Preco" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Preco" << std::endl;
        estado = FALHA;
    }
}

void TUPreco::testarCenarioFalha()
{
    try{
        codigo->setPreco(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Preco" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUPreco::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}




/////////////Metodos da classe TUTelefone//////////////
void TUTelefone::setUp()
{
    codigo = new Telefone;
    estado = SUCESSO;
}

void TUTelefone::tearDown()
{
    delete codigo;
}

void TUTelefone::testarCenarioSucesso()
{
    try{
        codigo->setTelefone(VALOR_VALIDO);
        if (codigo->getTelefone() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Telefone" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Telefone" << std::endl;
        estado = FALHA;
    }
}

void TUTelefone::testarCenarioFalha()
{
    try{
        codigo->setTelefone(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Telefone" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUTelefone::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUSenha//////////////
void TUSenha::setUp()
{
    codigo = new Senha;
    estado = SUCESSO;
}

void TUSenha::tearDown()
{
    delete codigo;
}

void TUSenha::testarCenarioSucesso()
{
    try{
        codigo->setSenha(VALOR_VALIDO);
        if (codigo->getSenha() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Senha" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Senha" << std::endl;
        estado = FALHA;
    }
}

void TUSenha::testarCenarioFalha()
{
    try{
        codigo->setSenha(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Senha" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUSenha::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



/////////////Metodos da classe TUVaga//////////////
void TUVaga::setUp()
{
    codigo = new Vaga;
    estado = SUCESSO;
}

void TUVaga::tearDown()
{
    delete codigo;
}

void TUVaga::testarCenarioSucesso()
{
    try{
        codigo->setVaga(VALOR_VALIDO);
        if (codigo->getVaga() != VALOR_VALIDO){
            std::cout << "Erro ao dar get no valor valido de Vaga" << std::endl;
            estado = FALHA;
        }
    }
    catch(std::invalid_argument ){
        std::cout << "Erro ao dar set no valor valido de Vaga" << std::endl;
        estado = FALHA;
    }
}

void TUVaga::testarCenarioFalha()
{
    try{
        codigo->setVaga(VALOR_INVALIDO);
        std::cout << "Erro no valor invalido de Vaga" << std::endl;
        estado = FALHA;
    }
    catch(std::invalid_argument){
        return;
    }
}

int TUVaga::run()
{
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}
