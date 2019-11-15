//Copyright Henrique Carrer e Guilherme Fleury

#include "entidades.h"

/////////////Metodos da Classe Usuario///////////
void Usuario::setNome(Nome nome)
{
    this->nome = nome;
}

Nome Usuario::getNome()
{
    return nome;
}

void Usuario::setTelefone(Telefone telefone)
{
    this->telefone = telefone;
}

Telefone Usuario::getTelefone()
{
    return telefone;
}

void Usuario::setEmail(Email email)
{
    this->email = email;
}

Email Usuario::getEmail()
{
    return email;
}

void Usuario::setSenha(Senha senha)
{
    this->senha = senha;
}

Senha Usuario::getSenha()
{
    return senha;
}

void Usuario::setCPF(CPF cpf)
{
    this->cpf = cpf;
}

CPF Usuario::getCPF()
{
    return cpf;
}



/////////////Metodos da Classe Reserva////////

void Reserva::setData(Data data) {
    this->data = data;
}

Data Reserva::getData(){
    return data;
}


void Reserva::setCodigoDeReserva(CodigoDeReserva codigo)
{
    this->codigo = codigo;
}

CodigoDeReserva Reserva::getCodigoDeReserva()
{
    return codigo;
}

void Reserva::setAssento(Assento assento)
{
    this->assento = assento;
}

Assento Reserva::getAssento()
{
    return assento;
}

void Reserva::setBagagem(Bagagem bagagem)
{
    this->bagagem = bagagem;
}

Bagagem Reserva::getBagagem()
{
    return bagagem;
}



/////////////Metodos da Classe Carona/////////
void Carona::setCodigoDeCarona(CodigoDeCarona codigo)
{
    this->codigo = codigo;
}

CodigoDeCarona Carona::getCodigoDeCarona()
{
    return codigo;
}

void Carona::setCidadeDestino(Cidade cidadeDestino)
{
    this->cidadeDestino = cidadeDestino;
}

Cidade Carona::getCidadeDestino()
{
    return cidadeDestino;
}

void Carona::setCidadeOrigem(Cidade cidadeOrigem)
{
    this->cidadeOrigem = cidadeOrigem;
}

Cidade Carona::getCidadeOrigem()
{
    return cidadeOrigem;
}

void Carona::setEstadoDestino(Estado estadoDestino)
{
    this->estadoDestino = estadoDestino;
}

Estado Carona::getEstadoDestino()
{
    return estadoDestino;
}

void Carona::setEstadoOrigem(Estado estadoOrigem)
{
    this->estadoOrigem = estadoOrigem;
}

Estado Carona::getEstadoOrigem()
{
    return estadoOrigem;
}

void Carona::setData(Data data)
{
    this->data = data;
}

Data Carona::getData()
{
    return data;
}

void Carona::setDuracao(Duracao duracao)
{
    this->duracao = duracao;
}

Duracao Carona::getDuracao()
{
    return duracao;
}

void Carona::setVaga(Vaga vaga)
{
    this->vaga = vaga;
}

Vaga Carona::getVaga()
{
    return vaga;
}

void Carona::setPreco(Preco preco)
{
    this->preco = preco;
}

Preco Carona::getPreco()
{
    return preco;
}



////////////Metodos da Classe Conta/////////
void Conta::setCodigoDeBanco(CodigoDeBanco banco)
{
    this->banco = banco;
}

CodigoDeBanco Conta::getCodigoDeBanco()
{
    return banco;
}

void Conta::setNumeroDeAgencia(NumeroDeAgencia agencia)
{
    this->agencia = agencia;
}

NumeroDeAgencia Conta::getNumeroDeAgencia()
{
    return agencia;
}

void Conta::setNumeroDeConta(NumeroDeConta conta)
{
    this->conta = conta;
}

NumeroDeConta Conta::getNumeroDeConta()
{
    return conta;
}
