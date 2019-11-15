/**
 * @file dominios.h
 * @author Henrique Carrer e Guilherme Fleury
 * @brief Biblioteca simples de dominios
 * @version 0.1
 * @date 2019-09-27
 *
 * @copyright Copyright (Henrique e Guilherme) 2019
 *
 */
#ifndef DOMINIOS_H
#define DOMINIOS_H
#include <iostream>

/**
 * @class Assento.
 *
 * @brief Codigo destinado a identificar um Assento.
 *
 * @details A validacao deste codigo apenas valida assentos do tipo 'D' ou 'T'.
 */
class Assento
{
private:
    std::string assento;
    /**
     * @brief Validacao do Assento.
     *
     * Verifica se o char de entrada representa um caracter igual a 'D' ou 'T'.
     *
     * @param char a ser validado como Assento.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
    void validarAssento(std::string assento) throw(std::invalid_argument);
public:
 /**
  * @brief Set basico da classe Assento.
  *
  * @param char a ser inserido no objeto.
  *
  * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
  *  a sua) lanca um objeto explicando o erro.
  *
  */
    void setAssento(std::string assento) throw(std::invalid_argument);
 /**
  * @brief Get padrao.
  *
  * @return char Retorna o tipo de assento do objeto.
  */
    std::string getAssento();
};



/**
 * @class Bagagem.
 *
 * @brief Codigo destinado a identificar uma Bagagem.
 *
 * @details A validacao deste codigo apenas valida quantidades de bagagem entre 0 e 4.
 */
class Bagagem
{
private:
    int bagagem;
    /**
     * @brief Validacao da Bagagem.
     *
     * Verifica se o int de entrada representa um numero entre 0 e 4.
     *
     * @param int a ser validado como Bagagem.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
    void validarBagagem(int bagagem) throw(std::invalid_argument);
public:
    /**
     * @brief Set basico da classe Bagagem.
     *
     * @param int a ser inserido no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
    void setBagagem(int bagagem) throw(std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return int Retorna a quantidade de bagagem do objeto.
     */
    int getBagagem();
};



/**
 * @class CodigoDeBanco.
 *
 * @brief Codigo destinado a identificar um CodigoDeBanco.
 *
 * @details A validacao deste codigo apenas valida codigos no formato XXX, onde X e um digito de 0 a 9.
 */
class CodigoDeBanco
{
private:
    std::string codigoDeBanco;
    /**
     * @brief Validacao do CodigoDeBanco.
     *
     * Verifica se a string de entrada e do formato XXX, onde X e um digito de 0 a 9.
     *
     * @param string a ser validada como CodigoDeBanco.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
    void validarCodigoDeBanco(std::string codigoDeBanco) throw(std::invalid_argument);
public:
    /**
     * @brief Set basico da classe CodigoDeBanco.
     *
     * @param string a ser inserida no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
    void setCodigoDeBanco(std::string codigoDeBanco) throw(std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return string Retorna o codigo de banco no formato XXX, onde X e um um digito de 0 a 9.
     */
    std::string getCodigoDeBanco();
};



/**
 * @class CodigoDeCarona.
 *
 * @brief Codigo destinado a identificar um CodigoDeCarona.
 *
 * @details A validacao deste codigo apenas valida codigos no formato XXXX, onde X e um digito de 0 a 9.
 */
class CodigoDeCarona
{
private:
    std::string codigoDeCarona;
    /**
     * @brief Validacao do CodigoDeCarona.
     *
     * Verifica se a string de entrada e do formato XXXX, onde X e um digito de 0 a 9.
     *
     * @param string a ser validada como CodigoDeCarona.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
    void validarCodigoDeCarona(std::string codigoDeCarona) throw(std::invalid_argument);
public:
    /**
     * @brief Set basico da classe CodigoDeCarona.
     *
     * @param string a ser inserida no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
    void setCodigoDeCarona(std::string codigoDeCarona) throw(std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return string Retorna o codigo de carona no formato XXXX, onde X e um um digito de 0 a 9.
     */
    std::string getCodigoDeCarona();
};



/**
 * @class CodigoDeReserva.
 *
 * @brief Codigo destinado a identificar um CodigoDeReserva.
 *
 * @details A validacao deste codigo apenas valida codigos no formato XXXXX, onde X e um digito de 0 a 9.
 */
 class CodigoDeReserva
 {
 private:
    std::string CodigoDeReserva;
    /**
     * @brief Validacao do CodigoDeReserva.
     *
     * Verifica se a string de entrada e do formato XXXXX, onde X e um digito de 0 a 9.
     *
     * @param string a ser validada como CodigoDeReserva.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
    void validarCodigoDeReserva(std::string codigoDeReserva) throw(std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe CodigoDeReserva.
     *
     * @param string a ser inserida no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
    void setCodigoDeReserva(std::string codigoDeReserva) throw(std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return string Retorna o codigo de carona no formato XXXXX, onde X e um um digito de 0 a 9.
     */
    std::string getCodigoDeReserva();
 };



 /**
 * @class Cidade.
 *
 * @brief Codigo destinado a identificar uma Cidade.
 *
 * @details A validacao deste codigo apenas valida codigos de 1 a 10 caracteres(ponto, letra ou numero), onde pelo menos
 *          um caracter e letra, antes do ponto deve haver letra e nao ha espacos em sequencia.
 */
 class Cidade
 {
 private:
    std::string cidade;
    /**
     * @brief Validacao da Cidade.
     *
     * Verifica se a string de entrada tem entre 1 e 10 caracteres(ponto, letra ou numero), onde pelo menos
     * um caracter e letra, antes do ponto deve haver letra e nao ha espacos em sequencia.
     *
     * @param string a ser validada como CodigoDeReserva.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
    void validarCidade(std::string cidade) throw(std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Cidade.
     *
     * @param string a ser inserida no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
    void setCidade(std::string cidade) throw(std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return string Retorna o nome da cidade.
     */
    std::string getCidade();
 };



 /**
 * @class CPF.
 *
 * @brief Codigo destinado a identificar um CPF.
 *
 * @details A validacao deste codigo apenas valida codigos de 11 caracteres (de 0 a 9) que compõem um CPF valido.
 */
 class CPF
 {
 private:
    std::string cpf;
    /**
     * @brief Validacao do CPF.
     *
     * Verifica se a string de entrada tem 11 digitos (de 0 a 9) e compõem um CPF valido.
     *
     * @param string a ser validada como CPF.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
    void validarCPF(std::string cpf) throw(std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe CPF.
     *
     * @param string a ser inserida no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
    void setCPF(std::string cpf) throw(std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return string Retorna o CPF.
     */
    std::string getCPF();
 };



 /**
 * @class Data.
 *
 * @brief Codigo destinado a identificar uma Data.
 *
 * @details A validacao deste codigo apenas valida codigos no formato DD/MM/AAAA com datas validas, incluindo a ocorrencia de anos bissextos.
 */
 class Data
 {
 private:
     std::string data;
    /**
     * @brief Validacao da Data.
     *
     * Verifica se a string de entrada corresponde ao formato DD/MM/AAAA com datas validas, incluindo a ocorrencia de anos bissextos.
     *
     * @param string a ser validada como data.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void validarData(std::string data) throw(std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Data.
     *
     * @param string a ser inserida no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
    void setData(std::string data) throw(std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return string Retorna a data.
     */
    std::string getData();
 };



/**
 * @class Duracao.
 *
 * @brief Codigo destinado a identificar uma Duracao.
 *
 * @details A validacao deste codigo apenas valida codigos entre 1 e 48 horas.
 */
 class Duracao
 {
 private:
     int duracao;
    /**
     * @brief Validacao da Duracao.
     *
     * Verifica se o numero de entrada e um numero entre 1 e 48 horas.
     *
     * @param int a ser validado como Duracao.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void validarDuracao(int duracao) throw(std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Duracao.
     *
     * @param int a ser inserido no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setDuracao(int duracao) throw(std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return int Retorna a duracao.
     */
    int getDuracao();
 };



/**
 * @class Estado.
 *
 * @brief Codigo destinado a identificar um Estado.
 *
 * @details A validacao deste codigo apenas valida Estados correspondentes aos ja existentes em territorio Brasileiro.
 */
 class Estado
 {
 private:
     std::string estado;
    /**
     * @brief Validacao do Estado.
     *
     * Verifica se o estado inserido corresponde a um ja existente.
     *
     * @param string a ser validada como um Estado.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void validarEstado(std::string estado) throw(std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Estado.
     *
     * @param string a ser inserido no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setEstado(std::string estado) throw(std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return string Retorna o estado.
     */
     std::string getEstado();
 };



/**
 * @class Email.
 *
 * @brief Codigo destinado a identificar um Email.
 *
 * @details A validacao deste codigo apenas valida codigos seguindo o modelo local@dominio,
 *          onde local pode ter no maximo 20 caracteres (letra ou ponto) e nao pode ser
 *          iniciada ou terminada por ponto. Ja o dominio nao pode ser iniciado por ponto.
 *          Nao se pode haver 2 pontos ou mais em sequencia.
 */
 class Email
 {
 private:
     std::string email;
    /**
     * @brief Validacao do Email.
     *
     * Verifica se o Email inserido segue o padrao local@dominio com suas respectivas caracteristicas.
     *
     * @param string a ser validada como um Email.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void validarEmail(std::string email) throw(std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Email.
     *
     * @param string a ser inserido no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setEmail(std::string email) throw(std::invalid_argument);
    /**
     *@brief Get padrao.
     *
     *@return string Retorna o email.
     */
     std::string getEmail();
 };



/**
 * @class Nome.
 *
 * @brief Codigo destinado a identificar um Nome.
 *
 * @details A validacao deste codigo apenas valida codigos entre 1 e 20 caracteres,
 *          podendo ser letra, ponto ou espaco. Pelo menos um caracter deve ser letra,
 *          antes do ponto deve haver letra e nao ha espacos em sequencia.
 */
 class Nome
 {
 private:
    std::string nome;
    /**
     * @brief Validacao do Nome.
     *
     * Verifica se o Nome inserido segue de fato as regras de sua composicao.
     *
     * @param string a ser validada como um Nome.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void validarNome(std::string nome) throw (std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Nome.
     *
     * @param string a ser inserido no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setNome(std::string nome) throw (std::invalid_argument);
     /**
     * @brief Get padrao.
     *
     *@return string Retorna o nome.
     *
     */
     std::string getNome();
 };



/**
 * @class NumeroDeAgencia.
 *
 * @brief Codigo destinado a identificar um NumeroDeAgencia.
 *
 * @details A validacao deste codigo apenas valida codigos no formato XXXX-Y, onde
 *          X e um digito de 0 a 9 e Y e um digito verificador calculado por meio
 *          do algoritmo de Luhn.
 */
 class NumeroDeAgencia
 {
 private:
    std::string numeroDeAgencia;
    /**
     * @brief Validacao do NumeroDeAgencia.
     *
     * Verifica se o NumeroDeAgencia e valido com base no algoritmo de Luhn.
     *
     * @param string a ser validada como um NumeroDeAgencia.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void  validarNumeroDeAgencia(std::string numeroDeAgencia) throw (std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe NumeroDeAgencia.
     *
     * @param string a ser inserido no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setNumeroDeAgencia(std::string numeroDeAgencia) throw (std::invalid_argument);
     /**
     * @brief Get padrao.
     *
     *@return string Retorna o numeroDeAgencia.
     *
     */
     std::string getNumeroDeAgencia();
 };



/**
 * @class NumeroDeConta.
 *
 * @brief Codigo destinado a identificar um NumeroDeConta.
 *
 * @details A validacao deste codigo apenas valida codigos no formato XXXXXX-Y, onde
 *          X e um digito de 0 a 9 e Y e um digito verificador calculado por meio
 *          do algoritmo de Luhn.
 */
 class NumeroDeConta
 {
 private:
    std::string numeroDeConta;
    /**
     * @brief Validacao do NumeroDeConta.
     *
     * Verifica se o NumeroDeConta e valido com base no algoritmo de Luhn.
     *
     * @param string a ser validada como um NumeroDeConta.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void  validarNumeroDeConta(std::string numeroDeConta) throw (std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe NumeroDeConta.
     *
     * @param string a ser inserido no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setNumeroDeConta(std::string numeroDeConta) throw (std::invalid_argument);
     /**
     * @brief Get padrao.
     *
     *@return string Retorna o numeroDeConta.
     *
     */
     std::string getNumeroDeConta();
 };



/**
 * @class Preco.
 *
 * @brief Codigo destinado a identificar um Preco.
 *
 * @details A validacao deste codigo apenas valida precos entre 1 e 5000 reais.
 *
 */
 class Preco
 {
 private:
    double preco;
    /**
     * @brief Validacao do Preco.
     *
     * Verifica se o Preco e um numero entre 1 e 5000.
     *
     * @param double a ser validado como um Preco.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void validarPreco(double preco) throw (std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Preco.
     *
     * @param double a ser inserido no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setPreco(double preco) throw (std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     *@return double Retorna o preco.
     *
     */
     double getPreco();
 };



/**
 * @class Telefone.
 *
 * @brief Codigo destinado a identificar um Telefone.
 *
 * @details A validacao deste codigo apenas valida numeros de telefone no formato XX-YY-ZZZZZZZZZ,
 *          onde X, Y e Z sao digitos de 0 a 9. Tanto XX, quanto YY, quanto ZZZZZZZZZ nao podem ser
 *          totalmente preenchidos por '0'.
 *
 */
 class Telefone
 {
 private:
    std::string telefone;
    /**
     * @brief Validacao do Telefone.
     *
     * Verifica se o Telefone segue o formato XX-YY-ZZZZZZZZZ,
     * onde X, Y e Z sao digitos de 0 a 9. Tanto XX, quanto YY,
     * quanto ZZZZZZZZZ nao podem ser totalmente preenchidos
     * por '0'..
     *
     * @param string a ser validada como um Telefone.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void validarTelefone(std::string telefone) throw (std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Telefone.
     *
     * @param string a ser inserida no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setTelefone(std::string telefone) throw (std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     *@return string Retorna o telefone.
     *
     */
     std::string getTelefone();
 };



/**
 * @class Senha.
 *
 * @brief Codigo destinado a identificar uma Senha.
 *
 * @details A validacao deste codigo apenas valida codigos no formato XXXXX onde X pode ser
 *          ser letra, digito, #, $, % ou &. Deve-se haver pelo menos uma letra e um digito.
 *          Nao se pode haver caracteres repetidos.
 *
 */
 class Senha
 {
 private:
    std::string senha;
    /**
     * @brief Validacao da Senha.
     *
     * Verifica se a Senha esta no formato XXXXX onde X pode ser letra,
     * numero, #, $, % ou &. É necessario que haja ao menos uma letra e
     * um numero. Nao se e permitido a repeticao de caracteres.
     *
     * @param string a ser validada como uma Senha.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void validarSenha(std::string senha) throw (std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Senha.
     *
     * @param string a ser inserida no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setSenha(std::string senha) throw (std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return string Retorna a senha.
     *
     */
     std::string getSenha();
 };



 /**
 * @class Vaga.
 *
 * @brief Codigo destinado a identificar uma Vaga.
 *
 * @details A validacao deste codigo apenas valida numeros inteiros entre 0 e 4.
 *
 */
 class Vaga
 {
 private:
    int vaga;
    /**
     * @brief Validacao da Vaga.
     *
     * Verifica se a vaga e um numero inteiro entre 0 e 4.
     *
     * @param int a ser validado como uma Vaga.
     *
     * @throw std::invalid_argument com a devida mensagem de erro .
     *
     */
     void validarVaga(int vaga) throw (std::invalid_argument);
 public:
    /**
     * @brief Set basico da classe Vaga.
     *
     * @param int a ser inserida no objeto.
     *
     * @throw std::invalid_argument Caso a validacao de errado (Cada classe possui
     *  a sua) lanca um objeto explicando o erro.
     *
     */
     void setVaga(int vaga) throw (std::invalid_argument);
    /**
     * @brief Get padrao.
     *
     * @return int Retorna a senha.
     *
     */
     int getVaga();
 };
#endif // DOMINIOS_H
