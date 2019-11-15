//Copyright Henrique Carrer e Guilherme Fleury

#include "dominios.h"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>

////////////////////////Metodos Classe Assento///////////////////////////////
void Assento::validarAssento(std::string assento) throw(std::invalid_argument)
{
    assento[0] = toupper(assento[0]);
    if(assento[0] != 'D' && assento[0] != 'T')
    {
        throw std::invalid_argument ("Assento deve ser um caracter 'D' ou 'T'.");
    }
    if(assento.size() != 1)
    {
        throw std::invalid_argument ("Assento deve ser um caracter 'D' ou 'T'.");
    }
}

void Assento::setAssento(std::string assento) throw(std::invalid_argument)
{
    validarAssento(assento);                    //padroniza todos os assentos como uma letra maiuscula
    assento[0] = toupper(assento[0]);           //independente se for digitada como maiscula ou minus-
    this->assento = assento;                    //la na entrada
}

std::string Assento::getAssento()
{
    return assento;
}



////////////////////////Metodos Classe Bagagem///////////////////////////////
void Bagagem::validarBagagem(int bagagem) throw(std::invalid_argument)
{
    if(bagagem < 0 || bagagem > 4)
    {
        throw std::invalid_argument ("O numero de bagagem inserido deve estar entre 0 e 4");
    }
}

void Bagagem::setBagagem(int bagagem) throw(std::invalid_argument)
{
    validarBagagem(bagagem);
    this->bagagem = bagagem;
}

int Bagagem::getBagagem()
{
    return bagagem;
}



////////////////////////Metodos Classe CodigoDeBanco///////////////////////////////
void CodigoDeBanco::validarCodigoDeBanco(std::string codigoDeBanco) throw(std::invalid_argument)
{
    if(codigoDeBanco.size() != 3)
    {
        throw std::invalid_argument ("O codigo de banco deve ser composto de 3 digitos entre 0 e 9");
    }
    for (int i=0; i<3; i++)
    {
        if (!isdigit(codigoDeBanco[i]))   //checa se o caracter de indice 'i' do codigoDeBanco
        {                                   //e de fato um numero decimal. Caso nao seja, retorna 0
            throw std::invalid_argument ("O codigo de banco deve ser composto somente por digitos entre 0 e 9");
            break;
        }
    }
}

void CodigoDeBanco::setCodigoDeBanco(std::string codigoDeBanco) throw(std::invalid_argument)
{
    validarCodigoDeBanco(codigoDeBanco);
    this->codigoDeBanco = codigoDeBanco;
}

std::string CodigoDeBanco::getCodigoDeBanco()
{
    return codigoDeBanco;
}



////////////////////////Metodos Classe CodigoDeCarona///////////////////////////////
void CodigoDeCarona::validarCodigoDeCarona(std::string codigoDeCarona) throw(std::invalid_argument)
{
    for (int i=0; i<4; i++)
    {
        if (!isdigit(codigoDeCarona[i]))    //checa se o caracter de indice 'i' do codigoDeCarona
        {                                   //e de fato um numero decimal. Caso nao seja, retorna 0
            throw std::invalid_argument ("O codigo de carona deve ser composto somente por digitos entre 0 e 9");
            break;
        }
    }
    if(codigoDeCarona.size() != 4)
    {
        throw std::invalid_argument ("O codigo de carona deve ser composto de 4 digitos entre 0 e 9");
    }
}

void CodigoDeCarona::setCodigoDeCarona(std::string codigoDeCarona) throw (std::invalid_argument)
{
    validarCodigoDeCarona(codigoDeCarona);
    this->codigoDeCarona = codigoDeCarona;
}

std::string CodigoDeCarona::getCodigoDeCarona()
{
    return codigoDeCarona;
}



////////////////////////Metodos Classe CodigoDeReserva///////////////////////////////
void CodigoDeReserva::validarCodigoDeReserva(std::string codigoDeReserva) throw(std::invalid_argument)
{
    if(codigoDeReserva.size() != 5)
    {
        throw std::invalid_argument ("O codigo de reserva deve ser composto de 5 digitos entre 0 e 9");
    }
    for (int i=0; i<5; i++)
    {
        if (!isdigit(codigoDeReserva[i]))   //checa se o caracter de indice 'i' do codigoDeReserva
        {                                    //e de fato um numero decimal. Caso nao seja, retorna 0
            throw std::invalid_argument ("O codigo de reserva deve ser composto somente por digitos entre 0 e 9");
            break;
        }
    }
}

void CodigoDeReserva::setCodigoDeReserva(std::string codigoDeReserva) throw(std::invalid_argument)
{
    validarCodigoDeReserva(codigoDeReserva);
    this->CodigoDeReserva = codigoDeReserva;
}

std::string CodigoDeReserva::getCodigoDeReserva()
{
    return CodigoDeReserva;
}



////////////////////////Metodos Classe Cidade////////////////////
void Cidade::validarCidade(std::string cidade) throw(std::invalid_argument)
{
    bool valido = false;
    for(int i=0; i<cidade.size(); i++)
    {
        if(isdigit(cidade[i]))
        {
            throw std::invalid_argument ("O nome da cidade so pode conter letras, espacos ou pontos.");
            break;
        }
    }
    for(int i=0; i<cidade.size(); i++)
    {
        if(isalpha(cidade[i]))                          //loop que checa se ao menos um digito e letra,
        {                                               //caso contrario, o erro e gerado no if seguinte a esse loop
            valido = true;
            break;
        }
    }
    if(valido==false)
    {
        throw std::invalid_argument ("O nome da cidade deve conter ao menos uma letra.");
    }
    for(int j=0; j<cidade.size(); j++)
    {
        if(cidade[j]=='.' && !isalpha(cidade[j-1]))
        {
            throw std::invalid_argument ("Deve-se haver uma letra antes do ponto.");
            break;
        }
        if(cidade[j]==' ' && cidade[j+1]==' ')
        {
            throw std::invalid_argument ("Nao se pode haver dois espacos em sequencia");
            break;
        }
    }
    if(cidade.size() < 1 || cidade.size() > 10)
    {
        throw std::invalid_argument("O nome da cidade deve ter entre 1 e 10 digitos.");
    }
}

void Cidade::setCidade(std::string cidade) throw(std::invalid_argument)
{
    validarCidade(cidade);
    this->cidade = cidade;
}

std::string Cidade::getCidade()
{
    return cidade;
}



////////////////////////Metodos Classe CPF////////////////////
void CPF::validarCPF(std::string cpf) throw(std::invalid_argument)
{
    for(int i=0; i<cpf.size(); i++)
    {
        if(!isdigit(cpf[i]))
        {
            throw std::invalid_argument ("O CPF deve conter apenas digitos de 0 a 9.");
            break;
        }
    }
    int digitoVerificador, somaCpf=0, digito11=0, digito12=0;
    for(int i=0; i<9; i++)
    {
        somaCpf+=(cpf[i]-'0')*(i+1);                                //este pedaco de código valida um CPF
    }                                                               //com base no uso de 2 digitos verificadores
    digito11 = somaCpf % 11;                                        //calculados como em um CPF oficial gerado
    if(digito11 != (cpf[9]-'0'))                                    //pelo Ministerio da Fazenda.
    {                                                               //
        throw std::invalid_argument("CPF invalido.");               //
    }                                                               //
    somaCpf = 0;
    for(int i=0; i<10; i++)
    {
        somaCpf+=(cpf[i]-'0')*(i);
    }
    digito12 = somaCpf % 11;
    if(digito12 != (cpf[10]-'0'))
    {
        throw std::invalid_argument("CPF invalido.");
    }
    if(cpf.size()!=11)
    {
        throw std::invalid_argument ("O CPF deve conter exatamente 11 digitos de 0 a 9.");
    }
}

void CPF::setCPF(std::string cpf) throw(std::invalid_argument)
{
    validarCPF(cpf);
    this->cpf = cpf;
}

std::string CPF::getCPF()
{
    return cpf;
}



///////////////////////Metodos da Classe Data///////////
void Data::validarData(std::string data) throw(std::invalid_argument)
{
    bool bissexto = false;
    if(data[2] != '/' || data[5] != '/' || data.size() != 10)
    {
        throw std::invalid_argument ("O formato de entrada da data deve ser 'DD/MM/AAAA'");
    }
    int dia, mes, ano;
    dia = (10*(data[0] - '0') + (data[1] - '0'));
    mes = (10*(data[3] - '0') + (data[4] - '0'));
    ano = (1000*(data[6] - '0') + 100*(data[7] - '0') + 10*(data[8] - '0') + (data[9] - '0'));
    int diaMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 31, 30};
    if(ano % 4 == 0)
    {
        if(ano % 100 != 0)
        {
            bissexto = true;
        }
    }
    else
    {
        if(ano % 400 == 0)
        {
            bissexto = true;
        }
    }
    if(bissexto == false)
    {
        if(dia < 1 || dia > diaMes[mes-1])
        {
            throw std::invalid_argument ("O dia  inserido nao e valido.");
        }
    }
    else
    {
        diaMes[1]++;
        if(dia < 1 || dia > diaMes[mes-1])
        {
            throw std::invalid_argument ("O dia  inserido nao e valido.");
        }
    }
    if(mes < 1 || mes > 12)
    {
        throw std::invalid_argument ("O mes inserido nao e valido.");
    }
    if(ano < 2000 || ano > 2099)
    {
        throw std::invalid_argument ("O ano inserido nao e valido.");
    }
}

void Data::setData(std::string data) throw(std::invalid_argument)
{
    validarData(data);
    this->data = data;
}

std::string Data::getData()
{
    return data;
}



/////////////////////Metódos da Classe Duracao/////////////////
void Duracao::validarDuracao(int duracao) throw(std::invalid_argument)
{
    if(duracao < 1 || duracao > 48)
    {
        throw std::invalid_argument ("A duracao deve ser um numero entre 1 e 48 horas");
    }
}

void Duracao::setDuracao(int duracao) throw(std::invalid_argument)
{
    validarDuracao(duracao);
    this->duracao = duracao;
}

int Duracao::getDuracao()
{
    return duracao;
}



///////////////////Metodos da Classe Estado///////////////////
void Estado::validarEstado(std::string estado) throw(std::invalid_argument)
{
    bool valido = false;
    for(int i=0; i<estado.size();i++)
    {
        estado[i] = toupper(estado[i]);
    }
    if(estado.size() != 2)
    {
        throw std::invalid_argument ("A sigla correpondente ao Estado deve conter apenas 2 caracteres.");
    }

    if(estado == "AC")
    {
        valido = true;
    }
    if(estado == "AL")
    {
        valido = true;
    }
    if(estado == "AP")
    {
        valido = true;
    }
    if(estado == "AM")
    {
        valido = true;
    }
    if(estado == "BA")
    {
        valido = true;
    }
    if(estado == "CE")
    {
        valido = true;
    }
    if(estado == "DF")
    {
        valido = true;
    }
    if(estado == "ES")
    {
        valido = true;
    }
    if(estado == "GO")
    {
        valido = true;
    }
    if(estado == "MA")
    {
        valido = true;
    }
    if(estado == "MT")
    {
        valido = true;
    }
    if(estado == "MS")
    {
        valido = true;
    }
    if(estado == "MG")
    {
        valido = true;
    }
    if(estado == "PA")
    {
        valido = true;
    }
    if(estado == "PB")
    {
        valido = true;
    }
    if(estado == "PR")
    {
        valido = true;
    }
    if(estado == "PE")
    {
        valido = true;
    }
    if(estado == "PI")
    {
        valido = true;
    }
    if(estado == "RJ")
    {
        valido = true;
    }
    if(estado == "RN")
    {
        valido = true;
    }
    if(estado == "RS")
    {
        valido = true;
    }
    if(estado == "RO")
    {
        valido = true;
    }
    if(estado == "RR")
    {
        valido = true;
    }
    if(estado == "SC")
    {
        valido = true;
    }
    if(estado == "SP")
    {
        valido = true;
    }
    if(estado == "SE")
    {
        valido = true;
    }
    if(estado == "TO")
    {
        valido = true;
    }

    if(valido == false)
    {
        throw std::invalid_argument ("O Estado digitado nao e valido.");
    }
}

void Estado::setEstado(std::string estado) throw(std::invalid_argument)
{
    validarEstado(estado);
    for(int i=0; i<estado.size();i++)                   //bloco de código usado
    {                                                   //para settar os Estados
        estado[i] = toupper(estado[i]);                 //de maneira padronizada
    }                                                   //para facilitar seu manuseio
    this->estado = estado;                              //no futuro
}

std::string Estado::getEstado()
{
    return estado;
}



//////////////////////Metodos da Classe Email//////////////////
void Email::validarEmail(std::string email) throw(std::invalid_argument)
{
    int tamanhoLocal=0, tamanhoDominio=0;
    bool valido = true;
    for(int i=0; i<email.size(); i++)
    {
        if(email[i] != '@')
        {
            tamanhoLocal++;
            if(!isalpha(email[i]) && email[i] != '.')
            {
                throw std::invalid_argument ("O email deve conter apenas letras ou pontos antes do '@'.");
                break;
            }
        }
        else
        {
            break;
        }
    }
    if(email[tamanhoLocal] != '@')
    {
        throw std::invalid_argument ("O email deve seguir o padrao local@dominio.");
    }
    for(int i=email.size()-1; i>tamanhoLocal; i--)
    {
        tamanhoDominio++;
        if(!isalpha(email[i]) && email[i] != '.')
            {
                throw std::invalid_argument ("O email deve conter apenas letras ou pontos depois do '@'.");
                break;
            }
    }
    if(tamanhoDominio < 1 || tamanhoDominio > 20)
    {
        valido = false;
        throw std::invalid_argument ("O email pode ter ate 20 caracteres depois do '@'.");
    }
    if(tamanhoLocal < 1 || tamanhoLocal > 20)
    {
        valido = false;
        throw std::invalid_argument ("O email pode ter ate 20 caracteres antes do '@'.");
    }
    if(email[0] == '.' || email[tamanhoLocal-1] == '.')
    {
        throw std::invalid_argument ("O email nao pode ser iniciado ou terminado por ponto em sua parte local (local@dominio)");
    }
    if(email[tamanhoLocal+1] == '.')
    {
        throw std::invalid_argument ("O dominio nao deve ser iniciado por ponto (local@dominio).");
    }
    for(int i=0; i<email.size(); i++)
    {
        if(email[i] == '.' && email[i+1] == '.')
        {
            throw std::invalid_argument ("Nao se pode haver dois pontos em sequencia no email.");
            break;
        }
    }
}

void Email::setEmail(std::string email) throw(std::invalid_argument)
{
    validarEmail(email);
    this->email = email;
}

std::string Email::getEmail()
{
    return email;
}



/////////////////////Metodos da Classe Nome///////////////////
void Nome::validarNome(std::string nome) throw(std::invalid_argument)
{
    bool valido = false;
    if(nome.size() < 1 || nome.size() > 20)
    {
        throw std::invalid_argument ("O nome deve conter de 1 a 20 caracteres.");
    }
    for(int i=0; i<nome.size(); i++)
    {
        if(isalpha(nome[i]))
        {
            valido = true;
        }
        if(!isalpha(nome[i]) && nome[i] != '.' && nome[i] != ' ')
        {
            throw std::invalid_argument ("O nome deve conter apenas letras, pontos ou espacos.");
            break;
        }
        if(nome[i] == '.' && !isalpha(nome[i-1]))
        {
            throw std::invalid_argument ("Antes do ponto deve haver letra.");
            break;
        }
        if(nome[i] == ' ' & nome[i+1] == ' ')
        {
            throw std::invalid_argument ("Nao se pode haver espacos em sequencia.");
            break;
        }
    }
    if(valido == false)
    {
        throw std::invalid_argument ("Pelo menos um caracter do nome deve ser letra.");
    }
}

void Nome::setNome(std::string nome) throw (std::invalid_argument)
{
    validarNome(nome);
    this->nome = nome;
}

std::string Nome::getNome()
{
    return nome;
}



////////////////////////Metodos da Classe Numero de Agencia/////////////////
void NumeroDeAgencia::validarNumeroDeAgencia(std::string numeroDeAgencia) throw (std::invalid_argument)
{
    bool valido = false;
    int numero[4] = {0}, soma=0, digitoVerificador=0;
    if(numeroDeAgencia.size() != 5)
    {                                                                                       //este pedaco de código gera um
        throw std::invalid_argument ("O numero de agencia deve conter 5 digitos.");         //erro caso o numeroo de agencia
    }                                                                                       //passado nao possua 5 digitos
    for(int i=0; i < numeroDeAgencia.size() - 1; i++)       //aqui comeca o calculo do
    {                                                       //algoritmo de Luhn
        if(i % 2 == 0)
        {
            numero[i] = numeroDeAgencia[i] - '0';
        }
        if(i % 2 == 1)
        {
            numero[i] = 2 * (numeroDeAgencia[i] - '0');
        }
        if(numero[i] > 10)
        {
            numero[i] = numero[i] % 9;
        }
        soma += numero[i];
    }
    soma = soma * 9;
    digitoVerificador = soma % 10;
    if(digitoVerificador == (numeroDeAgencia[numeroDeAgencia.size()-1] - '0'))
    {
        valido = true;
    }
    if(valido == false)
    {
        throw std::invalid_argument ("Numero de Agencia invalido.");
    }
}

void NumeroDeAgencia::setNumeroDeAgencia(std::string numeroDeAgencia) throw (std::invalid_argument)
{
    validarNumeroDeAgencia(numeroDeAgencia);
    this->numeroDeAgencia = numeroDeAgencia;
}

std::string NumeroDeAgencia::getNumeroDeAgencia()
{
    return numeroDeAgencia;
}



/////////////////////////Metodos da Classe NumeroDeConta////////////////
void NumeroDeConta::validarNumeroDeConta(std::string numeroDeConta) throw (std::invalid_argument)
{
    bool valido = false;
    int numero[6] = {0}, soma=0, digitoVerificador=0;
    if(numeroDeConta.size() != 7)
    {                                                                                     //este pedaco de código gera um
        throw std::invalid_argument ("O numero de conta deve conter 7 digitos.");         //erro caso o numero de conta
    }                                                                                     //passado nao possua 7 digitos
    for(int i=0; i < numeroDeConta.size() - 1; i++)       //aqui comeca o calculo do
    {                                                       //algoritmo de Luhn
        if(i % 2 == 0)
        {
            numero[i] = numeroDeConta[i] - '0';
        }
        if(i % 2 == 1)
        {
            numero[i] = 2 * (numeroDeConta[i] - '0');
        }
        if(numero[i] > 10)
        {
            numero[i] = numero[i] % 9;
        }
        soma += numero[i];
    }
    soma = soma * 9;
    digitoVerificador = soma % 10;
    if(digitoVerificador == (numeroDeConta[numeroDeConta.size()-1] - '0'))
    {
        valido = true;
    }
    if(valido == false)
    {
        throw std::invalid_argument ("Numero de Conta invalido.");
    }
}

void NumeroDeConta::setNumeroDeConta(std::string numeroDeConta) throw (std::invalid_argument)
{
    validarNumeroDeConta(numeroDeConta);
    this->numeroDeConta = numeroDeConta;
}

std::string NumeroDeConta::getNumeroDeConta()
{
    return numeroDeConta;
}



//////////////////////Metodos da Classe Preco/////////////////
void Preco::validarPreco(double preco) throw (std::invalid_argument)
{
    if(preco < 1 || preco > 5000)
    {
        throw std::invalid_argument ("O preco deve ser um valor entre 1 e 5000 reais.");
    }
}

void Preco::setPreco(double preco) throw (std::invalid_argument)
{
    validarPreco(preco);
    this->preco = preco;
}

double Preco::getPreco()
{
    return preco;
}



////////////////////Metodos da Classe Telefone/////////////
void Telefone::validarTelefone(std::string telefone) throw (std::invalid_argument)
{
    bool valido = false;
    int x=0, y=0, z=0;
    x = (telefone[0] - '0') * 10 + (telefone[1] - '0');
    y = (telefone[2] - '0') * 10 + (telefone[3] - '0');
    for(int i=4; i < telefone.size(); i++)
    {
        z += (telefone[i] - '0') * (pow(10,telefone.size()-i));
    }
    if(telefone.size() != 13)
    {
        throw std::invalid_argument ("O numero de telefone deve ser composto por 13 digitos de 0 a 9.");
    }
    if(x==0)
    {
        throw std::invalid_argument ("O numero de telefone deve ser do formato XXYYZZZZZZZZZ, em que XX nao pode ser 00.");
    }
    if(y==0)
    {
        throw std::invalid_argument ("O numero de telefone deve ser do formato XXYYZZZZZZZZZ, em que YY nao pode ser 00.");
    }
    if(z==0)
    {
        throw std::invalid_argument ("O numero de telefone deve ser do formato XXYYZZZZZZZZZ, em que ZZ nao pode ser 000000000.");
    }
}

void Telefone::setTelefone(std::string telefone) throw (std::invalid_argument)
{
    validarTelefone(telefone);
    this->telefone = telefone;
}

std::string Telefone::getTelefone()
{
    return telefone;
}



////////////////////////Metodos da Classe Senha///////////////////
void Senha::validarSenha(std::string senha) throw (std::invalid_argument)
{
    bool valido = false;
    if(senha.size() != 5)
    {
        throw std::invalid_argument ("A senha deve ter 5 caracteres.");
    }
    for(int i=0; i < senha.size(); i++)
    {
        if(!isalnum(senha[i]) && senha[i] != '#' && senha[i] != '$' && senha[i] != '%' && senha[i] != '&')
        {
            throw std::invalid_argument ("A senha so pode conter letras, numeros, '#', '$', '%' ou '&'.");
            break;
        }
        for(int j=i; j<senha.size(); j++)
        {
            if(senha[i] == senha[j+1])
            {
                throw std::invalid_argument ("Cada digito da senha deve ser diferente dos demais.");
                break;
            }
            if(isalpha(senha[i]) && isdigit(senha[j]))
            {
                valido = true;
            }
            if(isalpha(senha[j]) && isdigit(senha[i]))
            {
                valido = true;
            }
        }
    }
    if(valido == false)
    {
        throw std::invalid_argument ("A senha deve conter pelo menos uma letra e um digito.");
    }
}

void Senha::setSenha(std::string senha) throw (std::invalid_argument)
{
    validarSenha(senha);
    this->senha = senha;
}

std::string Senha::getSenha()
{
    return senha;
}



/////////////////////Metodos da Classe Vaga//////////////////
void Vaga::validarVaga(int vaga) throw (std::invalid_argument)
{
    if(vaga < 0 || vaga > 4)
    {
        throw std::invalid_argument ("A vaga deve ser um numero inteiro entre 0 e 4.");
    }
}

void Vaga::setVaga(int vaga) throw (std::invalid_argument)
{
    validarVaga(vaga);
    this->vaga = vaga;
}

int Vaga::getVaga()
{
    return vaga;
}
