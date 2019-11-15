//Copyright Henrique Carrer e Guilherme Fleury

#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "testes.h"
#include "curses.h"
#include <string.h>
#include "interfaces.h"
#include "modulos.h"
#include "builder.h"
#include "controller.h"

//#include "sqlite3.h"

using namespace std;

int main()
{
    auto controller = Builder::buildSistema();

    controller->executar();

    Builder::destroySistema(controller);
    delete controller;




    /*
    char opcoes[]="Digite o numero corresponde a sua opção:";
    char campo1[]="Digite o CPF  : ";
    char campo2[]="Digite a senha: ";
    char dado1[80];
    char dado2[80];
    int linha,coluna;

    initscr();                                                                      // Inicia curses.
    getmaxyx(stdscr,linha,coluna);                                                  // Armazena quantidade de linhas e de colunas.
    mvprintw(linha/2 - 5,(coluna-strlen(opcoes))/2,"%s",opcoes);
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);                        // Imprime nome do campo.
    getstr(dado1);                                                                  // Lê dado.
    mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"%s",campo2);                    // Imprime nome do campo.
    getstr(dado2);                                                                  // Lê dado.
    clear();                                                                        // Limpa janela.
    mvprintw(linha/2,(coluna-strlen(campo1))/2,"Digitado CPF   : %s",dado1);        // Imprime dado.
    mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"Digitada senha : %s",dado2);    // Imprime dado.
    noecho();                                                                       // Desabilita eco.
    getch();                                                                        // Lê caracter digitado.
    echo();                                                                         // Habilita eco.
    endwin();                                                                       // Finaliza curses.
    */

    return 0;
}
