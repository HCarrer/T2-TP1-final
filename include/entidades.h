/**
 * @file entidades.h
 * @author Henrique Carrer e Guilherme Fleury
 * @brief Biblioteca simples de Entidaes
 * @version 0.1
 * @date 2019-09-27
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "dominios.h"

#include <vector>

class Usuario;
class Carona;
class Reserva;
class Conta;


/**
 * @class Usuario
 *
 * @brief Classe que deve armazenar dados de um usuario
 *
 * Esta classe e a representacao de um usuario no programa e possui como
 * atributos um Nome, um Telefone, um Email, um CPF e uma Senha. A classe nao possui metodos de validacao
 * pois assume-se que os dominios ja estarao criados (e portato validados)
 *
 * @see Nome
 * @see Telefone
 * @see Email
 * @see Senha
 * @see CPF
 *
 */
class Usuario
{
private:
    Nome nome;/**< Nome do usuario*/
    Telefone telefone;/**< Telefone do usuario*/
    Email email;/**< Email do usuario*/
    Senha senha;/**< Senha do usuario*/
    CPF cpf;/**< CPF do usuario*/
public:
    Conta *conta;
    std::vector<Carona> vecCarona;
    /**
     * @brief Metodo set do Nome
     *
     * @return nome
     */
    void setNome(Nome nome);
    /**
     *@brief Metodo get do Nome
     *
     *@param Nome
     */
    Nome getNome();
    /**
     * @brief Metodo set do Telefone
     *
     * @return telefone
     */
    void setTelefone(Telefone telefone);
    /**
     *@brief Metodo get do Telefone
     *
     *@param Telefone
     */
    Telefone getTelefone();
    /**
     * @brief Metodo set do Email
     *
     * @return email
     */
    void setEmail(Email email);
    /**
     *@brief Metodo get do Email
     *
     *@param Email
     */
    Email getEmail();
    /**
     * @brief Metodo set da Senha
     *
     * @return senha
     */
    void setSenha(Senha senha);
    /**
     *@brief Metodo get da Senha
     *
     *@param Senha
     */
    Senha getSenha();
    /**
     * @brief Metodo set do Cpf
     *
     * @param cpf
     */
    void setCPF(CPF cpf);
    /**
     * @brief Metodo get do Cpf
     *
     * @return CPF
     */
    CPF getCPF();
};



/**
 * @class Reserva
 *
 * @brief Classe que deve armazenar dados de uma reserva
 *
 * Esta classe e a representacao de uma reserva no programa e possui como
 * atributos um Codigo de Reserva, um Assento e uma quantidade de Bagagem.
 * A classe nao possui metodos de validacao pois assume-se que os dominios
 * ja estarao criados (e portato validados)
 *
 * @see CodigoDeReserva
 * @see Assento
 * @see Bagagem
 *
 */
 class Reserva
 {
private:
    CodigoDeReserva codigo;/**< Codigo de Reserva da reserva*/
    Assento assento;/**< Assento da reserva*/
    Bagagem bagagem;/**< Bagagem da reserva*/
public:
    Data data;
    void setData(Data data);
    Data getData();


     /**
     * @brief Metodo set do CodigoDeReserva
     *
     * @param codigo
     */
    void setCodigoDeReserva(CodigoDeReserva codigo);
    /**
     * @brief Metodo get do CodigoDeReserva
     *
     * @return CodigoDeReserva
     */
    CodigoDeReserva getCodigoDeReserva();
    /**
     * @brief Metodo set do Assento
     *
     * @param assento
     */
    void setAssento(Assento assento);
    /**
     * @brief Metodo get do Assento
     *
     * @return Assento
     */
    Assento getAssento();
    /**
     * @brief Metodo set da Bagagem
     *
     * @param bagagem
     */
    void setBagagem(Bagagem bagagem);
    /**
     * @brief Metodo get do Bagagem
     *
     * @return Bagagem
     */
    Bagagem getBagagem();
 };



/**
 * @class Carona
 *
 * @brief Classe que deve armazenar dados de uma carona
 *
 * Esta classe e a representacao de uma carona no programa e possui como
 * atributos um Código de Carona, uma Cidade de origem, um Estado de origem, uma Cidade de destino, um Estado
 * de destino, uma Data, uma Duracao, a quantidade de Vagas e um Preco. A classe nao possui metodos de validacao
 * pois assume-se que os dominios ja estarao criados (e portato validados)
 *
 * @see CodigoDeCarona
 * @see Cidade
 * @see Estado
 * @see Data
 * @see Duracao
 * @see Vaga
 * @see Preco
 *
 */
 class Carona
 {
 private:
     CodigoDeCarona codigo;/**< Codigo de Carona da carona*/
     Cidade cidadeDestino, cidadeOrigem;/**< Cidade de Destino e de Origem da carona*/
     Estado estadoDestino, estadoOrigem;/**< Estado de Destino e de Origem da carona*/
     Data data;/**< Data da carona*/
     Duracao duracao;/**< Duracao da carona*/
     Vaga vaga;/**< Quantidade de vagas da carona*/
     Preco preco;/**< Preco da carona*/
 public:
     Email dono;
     std::vector<Reserva> vecRes;

    /**
     * @brief Metodo set do CodigoDeCarona
     *
     * @param codigoDeCarona
     */
    void setCodigoDeCarona(CodigoDeCarona codigo);
    /**
     * @brief Metodo get do CodigoDeCarona
     *
     * @return CodigoDeCarona
     */
    CodigoDeCarona getCodigoDeCarona();
    /**
     * @brief Metodo set da Cidade de Destino
     *
     * @param cidade de destino
     */
     void setCidadeDestino(Cidade cidadeDestino);
    /**
     * @brief Metodo get da Cidade de Destino
     *
     * @return Cidade
     */
     Cidade getCidadeDestino();
    /**
     * @brief Metodo set da Cidade de Origem
     *
     * @param cidade de origem
     */
     void setCidadeOrigem(Cidade cidadeOrigem);
    /**
     * @brief Metodo get da Cidade de Origem
     *
     * @return Cidade
     */
     Cidade getCidadeOrigem();
    /**
     * @brief Metodo set do Estado de Destino
     *
     * @param estado de destino
     */
     void setEstadoDestino(Estado estadoDestino);
    /**
     * @brief Metodo get do Estado de Destino
     *
     * @return Estado
     */
     Estado getEstadoDestino();
    /**
     * @brief Metodo set do Estado de Origem
     *
     * @param Estado de origem
     */
     void setEstadoOrigem(Estado estadoOrigem);
    /**
     * @brief Metodo get do Estado de Origem
     *
     * @return Estado
     */
     Estado getEstadoOrigem();
    /**
     * @brief Metodo set da Data
     *
     * @param data
     */
     void setData(Data data);
    /**
     * @brief Metodo get da Data
     *
     * @return Data
     */
     Data getData();
    /**
     * @brief Metodo set da Duracao
     *
     * @param duracao
     */
     void setDuracao(Duracao duracao);
    /**
     * @brief Metodo get da Duracao
     *
     * @return Duracao
     */
     Duracao getDuracao();
    /**
     * @brief Metodo set da Vaga
     *
     * @param vaga
     */
     void setVaga(Vaga vaga);
    /**
     * @brief Metodo get da Vaga
     *
     * @return Vaga
     */
     Vaga getVaga();
     /**
     * @brief Metodo set do Preco
     *
     * @param preco
     */
     void setPreco(Preco preco);
     /**
     * @brief Metodo get do Preco
     *
     * @return Preco
     */
     Preco getPreco();
 };


 /**
 * @class Conta
 *
 * @brief Classe que deve armazenar dados de uma conta bancaria
 *
 * Esta classe e a representacao de uma conta bancaria no programa e possui
 * como atributos um código de Banco, um numero de Agencia e um numero de
 * Conta. A classe nao possui metodos de validacao pois assume-se que os dominios
 * ja estarao criados (e portato validados)
 *
 * @see CodigoDeBanco
 * @see NumeroDeAgencia
 * @see NumeroDeConta
 *
 */
 class Conta
 {
 private:
    CodigoDeBanco banco;/**< Código de Banco da Conta*/
    NumeroDeAgencia agencia;/**< Numero de Agencia da Conta*/
    NumeroDeConta conta;/**< Numero de Conta da Conta*/
 public:
    /**
     * @brief Metodo set do CodigoDeBanco
     *
     * @param banco
     */
     void setCodigoDeBanco(CodigoDeBanco banco);
     /**
     * @brief Metodo get do CodigoDeBanco
     *
     * @return CodigoDeBanco
     */
     CodigoDeBanco getCodigoDeBanco();
    /**
     * @brief Metodo set do NumeroDeAgencia
     *
     * @param agencia
     */
     void setNumeroDeAgencia(NumeroDeAgencia agencia);
    /**
     * @brief Metodo get do NumeroDeAgencia
     *
     * @return NumeroDeAgencia
     */
     NumeroDeAgencia getNumeroDeAgencia();
    /**
     * @brief Metodo set do NumeroDeConta
     *
     * @param conta
     */
     void setNumeroDeConta(NumeroDeConta conta);
    /**
     * @brief Metodo get do NumeroDeConta
     *
     * @return NumeroDeConta
     */
     NumeroDeConta getNumeroDeConta();
 };
#endif // ENTIDADES_H
