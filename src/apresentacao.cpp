//#include "apresentacao.h"

#include "curses.h"
#include <string.h>
#include "modulos.h"

void MAA::executar() {

    int y_max, x_max;
    int wy_max, wx_max;


    std::string ops[] = { "Menu", "Confirmar"};
    std::string login = "Login";
    std::string emailLabel = "Email";
    std::string senhaLabel = "Senha";

    char email[50];
    std::string senha;

    getmaxyx(stdscr, y_max, x_max);
    WINDOW* win_erro = newwin(5, 45, 0, x_max/2-20);

    // static WINDOW* win = newwin(y_max-5, x_max-12, y_max-40, 5);
    // Janela principal do menu de login
    WINDOW* win = newwin(12, 50, y_max/2 - 6, x_max/2 - 15);
    getmaxyx(win, wy_max, wx_max);

    box(win, 0, 0);
    clear();
    refresh();

    // Campos que serão utilizados nos forms
    mvwprintw(win, 0, wx_max/2 - login.size()/2, login.c_str());
    mvwprintw(win, 3, 14 - emailLabel.size(), emailLabel.c_str());
    mvwprintw(win, 6, 14 - senhaLabel.size(), senhaLabel.c_str());
    wrefresh(win);

    // Janelas referentes aos campos email e senha no formulário
    WINDOW *emailForm, *senhaForm;
    emailForm = newwin(3, 33, win->_begy + 2, win->_begx + 15);
    senhaForm = newwin(3, 8, win->_begy + 5, win->_begx + 15);

    box(emailForm, 0, 0);
    wrefresh(emailForm);

    box(senhaForm, 0, 0);
    wrefresh(senhaForm);

    for (int i = 0; i < 2; i++) {
        int win_y, win_x;
        getmaxyx(win, win_y, win_x);
        mvwprintw(win, win_y-2, 2 + i*(ops[i-1].size()+11), ops[i].c_str());
    }
    wrefresh(win);

    keypad(win, true);

    // Objetos email e Senha que serão utilizados para a validação do formato
    Email u_email;
    Senha u_senha;

    bool digitou = false;
    int highlight = 0;
    int choice;

    // Lógica que desenha o menu
    while (true) {
        echo();
        curs_set(1);

        int16_t cont = 0;

        wmove(emailForm, 1, 1);

        // Previne o sistema de receber mais caracteres caso o usuário já tenha
        // digitado
        if (!digitou) {
            wgetstr(emailForm, email);
            cont++;
        }
        wmove(senhaForm, 1, 1);
        if (!digitou) {
            noecho();
            int p = 0;
            int x = 1;

            senha.clear();
            while (true) {
                wmove(senhaForm, 1, x);
                p = wgetch(senhaForm);
                if (p != 10 && x < 7) {
                    wmove(senhaForm, 1, x);
                    wprintw(senhaForm, "*");
                    senha += p;
                } else {
                    break;
                }
                x++;
            }
            enter:
            echo();
            cont++;
        }


        if (cont == 2) digitou = true;

        curs_set(0);
        // highlight na opção a ser selecionada
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                wattron(win, A_REVERSE);
            }
            int win_y, win_x;
            getmaxyx(win, win_y, win_x);
            mvwprintw(win, win_y-2, 2 + i*(ops[i-1].size()+11), ops[i].c_str());
            wattroff(win, A_REVERSE);
        }

        choice = wgetch(win);

        switch (choice) {
            case KEY_LEFT:
                highlight--;
                if (highlight == -1) {
                    highlight = 0;
                }
                break;
            case KEY_RIGHT:
                highlight++;
                if (highlight == 2) {
                    highlight = 1;
                }
                break;
            default:
                break;
        }

        if (choice == 10) {
            switch (highlight) {
                case 1:
                    // Tratamento dos erros que podem ser gerados por formato
                    // incorreto de input
                    try {
                        u_email.setEmail(email);

                        u_senha.setSenha(senha);
                    } catch (...) {
                        wmove(win_erro, 1, 0);
                        wprintw(win_erro,
                         "Erro no Formato, insira os dados novamente");

                        // Limpando os campos dos forms
                        mvwprintw(emailForm, 1, 1, "           ");
                        mvwprintw(senhaForm, 1, 1, "      ");

                        wrefresh(win_erro);
                        wrefresh(emailForm);
                        wrefresh(senhaForm);

                        digitou = false;
                        cont = 0;
                    }

                    if (servico->autenticar(u_email, u_senha)) {
                        controller->login(true, email);

                        wclear(win);
                        wrefresh(win);
                        delwin(win);

                        wclear(emailForm);
                        wrefresh(emailForm);
                        delwin(emailForm);

                        wclear(senhaForm);
                        wrefresh(senhaForm);
                        delwin(senhaForm);

                        wclear(win_erro);
                        wrefresh(win_erro);
                        delwin(win_erro);

                        return;
                    } else {
                        wmove(win_erro, 1, 0);
                        wprintw(win_erro, "Falha na autenticação");
                        wrefresh(win_erro);

                        // Limpando os campos dos forms
                        mvwprintw(emailForm, 1, 1, "           ");
                        mvwprintw(senhaForm, 1, 1, "      ");

                        wrefresh(win_erro);
                        wrefresh(emailForm);
                        wrefresh(senhaForm);

                        digitou = false;
                        cont = 0;
                    }
                    break;
                case 0:
                    wclear(win);
                    wrefresh(win);
                    delwin(win);

                    wclear(emailForm);
                    wrefresh(emailForm);
                    delwin(emailForm);

                    wclear(senhaForm);
                    wrefresh(senhaForm);
                    delwin(senhaForm);

                    wclear(win_erro);
                    wrefresh(win_erro);
                    delwin(win_erro);

                    return;
                    break;
            }
        }
    }

    wclear(win);
    wrefresh(win);
    delwin(win);

    wclear(emailForm);
    wrefresh(emailForm);
    delwin(emailForm);

    wclear(senhaForm);
    wrefresh(senhaForm);
    delwin(senhaForm);

    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

    noecho();
    curs_set(0);
}





void MAA::autenticar() {

    //metodo ja realizado dentro de MAA::executar()

}


/////////////////////////////////////
void MAU::executar() {
    // Inputs do usuário
    char email[20];
    char senha[20];
    char senha_rep[20];
    char telefone[20];
    char nome[20];
    char cpf[20];
    char codigo_de_banco[20];
    char numero_de_agencia[20];
    char numero_de_conta[20];

    const int NUM_FIELDS = 9;

    // Buttons
    std::string opcoes[2] = {"Menu", "Cadastrar"};

    // Cleaning up
    clear();
    resize_term(50, 120);
    refresh();

    // Screen boundaries
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    //std::cout << y_max << " " << x_max << std::endl;

    // Error window
    auto win_erro = newwin(5, 50, 0, x_max/2 - 20);


    // sign up window
    auto cad_win = newwin(32, 44, y_max/2 - 20, x_max/2 - 20);
    box(cad_win, 0, 0);
    keypad(cad_win, true);

    // Win name
    std::string cadastro = "Cadastro";
    mvwprintw(cad_win, 0, cad_win->_maxx / 2 - cadastro.size() / 2 + 1,
     cadastro.c_str());

    // Forms and labels
    WINDOW* form[NUM_FIELDS];
    std::string labels[NUM_FIELDS] = {"Email", "Senha", "Senha Novamente", "Nome", "Telefone", "CPF",
     "Codigo de Banco", "Numero de Agencia", "Numero de Conta"};

    //std::string labels[NUM_FIELDS] = {"Email", "Senha", "Senha Novamente", "Nome", "Telefone", "email",};

    // Form boxes
    for (int i = 0; i < NUM_FIELDS; i++) {
        form[i] = newwin(3, 18, cad_win->_begy + 3 + i * 3,
         cad_win->_begx + cad_win->_maxx - 19);
        box(form[i], 0, 0);
    }

    // Form Labels
    for (int i = 0; i < NUM_FIELDS; i++) {
        mvwprintw(cad_win, form[i]->_begy - cad_win->_begy + 1,
         form[i]->_begx - cad_win->_begx - labels[i].size() - 1,
         labels[i].c_str());
    }

    // Buttons
    for (int i = 0; i < 2; i++) {
        mvwprintw(cad_win,
         cad_win->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
         opcoes[i].c_str());
    }

    wrefresh(cad_win);
    // Refreshes
    for (int i = 0; i < NUM_FIELDS; i++) {
        wrefresh(form[i]);
    }

    // Form Loop
    int highlight = 0;
    int choice = 0;
    int cont = 0;
    bool deuRuim = false;
    bool manterCadWin = true;
    Email usr_email;
    Senha usr_senha;
    Senha usr_senha_rep;
    Nome usr_nome;
    Telefone usr_telefone;
    CPF usr_cpf;
    CodigoDeBanco usr_codigo_de_banco;
    NumeroDeAgencia usr_numero_de_agencia;
    NumeroDeConta usr_numero_de_conta;

    while (true) {
        echo();
        curs_set(1);

        wmove(form[0], 1, 1);
        wgetstr(form[0], email);

        // noecho();
        wmove(form[1], 1, 1);
        wgetstr(form[1], senha);

        wmove(form[2], 1, 1);
        wgetstr(form[2], senha_rep);
        // echo();

        wmove(form[3], 1, 1);
        wgetstr(form[3], nome);

        wmove(form[4], 1, 1);
        wgetstr(form[4], telefone);

        wmove(form[5], 1, 1);
        wgetstr(form[5], cpf);

        wmove(form[6], 1, 1);
        wgetstr(form[6], codigo_de_banco);

        wmove(form[7], 1, 1);
        wgetstr(form[7], numero_de_agencia);

        wmove(form[8], 1, 1);
        wgetstr(form[8], numero_de_conta);

        noecho();
        curs_set(0);

        if (deuRuim) {
            manterCadWin = true;
        }

        // Interaction Loop
        while (manterCadWin) {
            // opcoes
            for (int i = 0; i < 2; i++) {
                if (i == highlight) {
                    wattron(cad_win, A_REVERSE);
                }
                mvwprintw(cad_win,
                 cad_win->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
                 opcoes[i].c_str());
                wattroff(cad_win, A_REVERSE);
            }
            choice = wgetch(cad_win);

            // Selection
            switch (choice) {
                case KEY_LEFT:
                    highlight--;
                    if (highlight == -1) {
                        highlight = 0;
                    }
                    break;
                case KEY_RIGHT:
                    highlight++;
                    if (highlight == 2) {
                        highlight = 1;
                    }
                    break;
                default:
                    break;
            }
            // Action

            if (choice == 10) {
                switch (highlight) {
                    case 0:  // sair
                        for (int i = 0; i < NUM_FIELDS; i++) {
                            wclear(form[i]);
                            wrefresh(form[i]);
                            delwin(form[i]);
                        }
                        wclear(cad_win);
                        wrefresh(cad_win);
                        delwin(cad_win);

                        wclear(win_erro);
                        wrefresh(win_erro);
                        delwin(win_erro);

                        return;
                        break;
                    case 1: {  // cadastrar
                        // Trying to set the values
                        deuRuim = false;

                        try {
                            usr_email.setEmail(email);
                            mvwprintw(win_erro, 0, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 0, 0,
                              "Erro no formato do Email");
                            deuRuim = true;
                        }

                        try {
                            usr_senha.setSenha(senha);
                            mvwprintw(win_erro, 1, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 1, 0,
                             "Erro no formato da senha");
                            deuRuim = true;
                        }

                        try {
                            usr_senha_rep.setSenha(senha_rep);
                            mvwprintw(win_erro, 2, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 2, 0,
                             "Erro no formato da repetição da senha");
                            deuRuim = true;
                        }

                        if (usr_senha.getSenha() !=
                         usr_senha_rep.getSenha()) {
                            mvwprintw(win_erro, 3, 0,
                             "As duas senhas não coincidem");
                        }

                        try {
                            usr_nome.setNome(nome);
                            mvwprintw(win_erro, 4, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 4, 0,
                             "Erro no formato do Nome");
                            deuRuim = true;
                        }

                        try {
                            usr_telefone.setTelefone(telefone);
                            mvwprintw(win_erro, 5, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 5, 0,
                             "Erro no formato do Telefone");
                            deuRuim = true;
                        }

                        try {
                            usr_cpf.setCPF(cpf);
                            mvwprintw(win_erro, 6, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 6, 0,
                             "Erro no formato do CPF");
                            deuRuim = true;
                        }

                        try {
                            usr_codigo_de_banco.setCodigoDeBanco(codigo_de_banco);
                            mvwprintw(win_erro, 7, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 7, 0,
                             "Erro no formato do Código de Banco");
                            deuRuim = true;
                        }

                        try {
                            usr_numero_de_agencia.setNumeroDeAgencia(numero_de_agencia);
                            mvwprintw(win_erro, 8, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 8, 0,
                             "Erro no formato do Número de Agência");
                            deuRuim = true;
                        }

                        try {
                            usr_numero_de_conta.setNumeroDeConta(numero_de_conta);
                            mvwprintw(win_erro, 9, 0,
                             "                                              ");
                        } catch (...) {
                            mvwprintw(win_erro, 9, 0,
                             "Erro no formato do Número de Conta");
                            deuRuim = true;
                        }
                        wrefresh(win_erro);

                        manterCadWin = false;
                        if (deuRuim) {
                            for (int i = 0; i < NUM_FIELDS; i++) {
                                mvwprintw(form[i], 1, 1,
                                "                ");
                                wrefresh(form[i]);
                            }
                            break;
                        }

                        Usuario usuario;
                        Conta conta;

                        usuario.setEmail(usr_email);
                        usuario.setSenha(usr_senha);

                        conta.setNumeroDeConta(usr_numero_de_conta);
                        conta.setNumeroDeAgencia(usr_numero_de_agencia);
                        conta.setCodigoDeBanco(usr_codigo_de_banco);

                        if (servico->cadastrar(usuario, conta)) {
                            continue;
                        } else {
                            mvwprintw(win_erro, 1, 1,
                             "Erro ao cadastrar! Usuário já existe!");
                            wrefresh(win_erro);
                            deuRuim = true;
                            // Limpando os campos dos forms
                            for (int i = 0; i < NUM_FIELDS; i++) {
                                mvwprintw(form[i], 1, 1,
                                "                ");
                                wrefresh(form[i]);
                            }
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
        }
        if (!deuRuim) {  // Retornando ao menu principal caso tudo esteja bem
            break;
        }
    }
    for (int i = 0; i < NUM_FIELDS; i++) {
        wclear(form[i]);
        wrefresh(form[i]);
        delwin(form[i]);
    }

    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

    wclear(cad_win);
    wrefresh(cad_win);
    delwin(cad_win);
    return;
}

void MAU::verPerfil() {

    std::string firstOps[4] = {"Caronas Cadastradas", "Dados de Usuário", "Descadastrar", "Voltar"};
    std::string info = "Info Perfil";
    int y_max, x_max, wy_max, wx_max, i_wy_max, i_wx_max;
    int choice, highlight = 0;
    Usuario tmp;
    std::string email = controller->getEmail();
    getmaxyx(stdscr, y_max, x_max);

    auto perfWin = newwin(10, 30, y_max/2 - 5, x_max/2 - 15);
    auto infoWin = newwin(25, 80, y_max/2 - 6, x_max/2 - 40);
    keypad(perfWin, true);
    auto win_erro = newwin(5, 45, 0, x_max/2 - 20);

    clear();
    refresh();
    cbreak();
    noecho();
    curs_set(0);

    getmaxyx(perfWin, wy_max, wx_max);
    getmaxyx(infoWin, i_wy_max, i_wx_max);

    box(perfWin, 0, 0);
    mvwprintw(perfWin, 0, wx_max/2 - email.size()/2, email.c_str());
    wrefresh(perfWin);
    Email usuario;
    while (true) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight) {
                wattron(perfWin, A_REVERSE);
            }
            mvwprintw(perfWin, i + 3,
             wx_max/2 - firstOps[i].size()/2, firstOps[i].c_str());
            wattroff(perfWin, A_REVERSE);
        }
        choice = wgetch(perfWin);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight == -1) {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 4) {
                    highlight = 3;
                }
                break;
            default:
                break;
        }

        if (choice == 10) {
            switch (highlight) {
                case 0:  // Caronas cadastradas
                    verCaronas();
                    box(perfWin, 0, 0);
                    mvwprintw(perfWin, 0, wx_max/2 - email.size()/2, email.c_str());
                    wrefresh(perfWin);
                    break;
                case 1:  // Dados do usuário
                    wclear(perfWin);
                    wrefresh(perfWin);

                    tmp = servico->infoLoggedUser(controller->getEmail().c_str());

                    box(infoWin, 0, 0);
                    mvwprintw(infoWin, 0, i_wx_max/2 - info.size()/2, info.c_str());
                    wrefresh(infoWin);

                    mvwprintw(infoWin, 2, 2, "Email: %s", tmp.getEmail().getEmail().c_str());
                    mvwprintw(infoWin, 3, 2, "Código de Banco: %s", tmp.conta->getCodigoDeBanco().getCodigoDeBanco().c_str());
                    mvwprintw(infoWin, 4, 2, "Número de Agência: %s", tmp.conta->getNumeroDeAgencia().getNumeroDeAgencia().c_str());
                    mvwprintw(infoWin, 5, 2, "Número de Conta: %s", tmp.conta->getNumeroDeConta().getNumeroDeConta().c_str());
                    mvwprintw(infoWin, 6, 2, "Caronas Cadastradas: %d", tmp.vecCarona.size());
                    mvwprintw(infoWin, 10,2, "Pressione qualquer tecla para voltar");
                    wrefresh(infoWin);

                    getch();
                    wclear(infoWin);
                    wrefresh(infoWin);
                    box(perfWin, 0, 0);
                    mvwprintw(perfWin, 0, wx_max/2 - email.size()/2, email.c_str());
                    wrefresh(perfWin);
                    break;
                case 2:  // Descadastrar

                    usuario.setEmail(controller->getEmail());
                    if(servico->descadastrar(usuario)) {
                        wclear(perfWin);
                        wrefresh(perfWin);
                        delwin(perfWin);

                        wclear(infoWin);
                        wrefresh(infoWin);
                        delwin(infoWin);
                        controller->login(false, "");


                        return;
                    } else {
                        mvwprintw(win_erro, 0, 0, "Erro ao descadastrar");
                        wrefresh(win_erro);
                    }
                    break;
                default:  // Sair
                    wclear(infoWin);
                    wrefresh(infoWin);
                    delwin(infoWin);

                    wclear(perfWin);
                    wrefresh(perfWin);
                    delwin(perfWin);
                    return;
                    break;
            }
        }
        wrefresh(perfWin);
    }
    // getch();



    wclear(perfWin);
    wrefresh(perfWin);
    delwin(perfWin);
    return;
}


void MAU::verCaronas() {
    clear();
    refresh();
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);

    WINDOW* winCarona = newwin(y_max - 2, 40, 1, x_max/2 - 20);
    box(winCarona, 0, 0);
    mvwprintw(winCarona, 0, winCarona->_maxx/2 - 3, "Caronas");
    wrefresh(winCarona);
    keypad(winCarona, true);



    auto caronas = servico->infoLoggedUser(controller->getEmail().c_str()).vecCarona;

    bool manterTela = true;
    int highlight = 0, choice;
    while(manterTela) {
        for (int i = 0; i < caronas.size(); i++) {
            if (i == highlight) {
                wattron(winCarona, A_REVERSE);
            }
            int win_y, win_x;
            getmaxyx(winCarona, win_y, win_x);
            mvwprintw(winCarona, 2 + 1 * i , 2, caronas[i].getCodigoDeCarona().getCodigoDeCarona().c_str());
            wattroff(winCarona, A_REVERSE);
        }

        choice = wgetch(winCarona);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight == -1) {
                    highlight = 0;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == caronas.size()) {
                    highlight = caronas.size() - 1;
                }
                break;

            case 'q':
                return;
            default:
                break;
        }

        if(choice == 10) {
            manterTela = false;
        }
    }
    std::string opcoes[4] = {"Reservas", "Editar", "Remover", "Voltar"};
    int highlight2 = 0;
    while(true) {
        for (int i = 0; i < 4; i++) {
            if (i == highlight2) {
                wattron(winCarona, A_REVERSE);
            }
            int win_y, win_x;
            getmaxyx(winCarona, win_y, win_x);
            mvwprintw(winCarona, win_y - 2 , 2 + i * 10, opcoes[i].c_str());
            wattroff(winCarona, A_REVERSE);
        }

        choice = wgetch(winCarona);

        switch (choice) {
            case KEY_LEFT:
                highlight2--;
                if (highlight2 == -1) {
                    highlight2 = 0;
                }
                break;
            case KEY_RIGHT:
                highlight2++;
                if (highlight2 == 4) {
                    highlight2 = 3;
                }
                break;

            case 'q':
                clear();
                refresh();

                wclear(winCarona);
                wrefresh(winCarona);
                delwin(winCarona);
                return;

            default:
                break;
        }

        if(choice == 10) {
            switch(highlight2) {
                case 0: //Reservas
                    break;

                case 1: //Editar
                    break;

                case 2: //Remover
                    break;

                case 3: //Voltar
                    clear();
                    refresh();

                    wclear(winCarona);
                    wrefresh(winCarona);
                    delwin(winCarona);
                    return;
                    break;
            }
        }


    }
}


//////////////////////////////////

void MAC::executar() {
/* */
    // variaveis para guardar a info que entrar no form
    char cidadeO[20];
    char estadoO[20];
    char cidadeD[20];
    char estadoD[20];
    char data[20];

    // O que vai ter escrito nos botoes em baixo
    std::string opcoes[2] = {"Menu", "Buscar"};

    // limpando tela antes de começar
    clear();
    refresh();

    // pegando tamanhos da tela total
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);

    // aba para a seleção do evento desejado
    auto leftWin = newwin(y_max - 2, x_max / 2 - 2, 1, 1);
    box(leftWin, 0, 0);
    keypad(leftWin, true);

    // aba que mostra as apresentações da do evento selecionado na aba esquerda
    auto rightWin = newwin(y_max - 2, x_max / 2 - 2, 1,  x_max / 2 + 2);
    box(rightWin, 0, 0);


    // Janela de busca
    auto searchWin = newwin(26, 60, y_max/2 - 13, x_max /2 - 30);
    box(searchWin, 0, 0);
    keypad(searchWin, true);

    // Nome da janela
    std::string usr_email = controller->getEmail();
    std::string caronas;
    if (usr_email.size() > 0) {
        caronas = "Caronas " + usr_email;
    } else {
        caronas = "Caronas";
    }
    mvwprintw(searchWin, 0, searchWin->_maxx / 2 - caronas.size() / 2,
     caronas.c_str());

    // espaçoes para os form
    WINDOW* form[5];
    std::string labels[5] = {"Cidade de Origem", "Estado de Origem",
     "Cidade de Destino", "Estado de Destino", "Data"};

    // caixas dos forms
    for (int i = 0; i < 5; i++) {
        form[i] = newwin(3, 17, searchWin->_begy + 3 + i * 3,
         searchWin->_begx + searchWin->_maxx - 31);
        box(form[i], 0, 0);
        //wrefresh(form[i]);
    }


    // labels dos forms
    for (int i = 0; i < 5; i++) {
        mvwprintw(searchWin, form[i]->_begy - searchWin->_begy + 1,
         form[i]->_begx - searchWin->_begx - labels[i].size() - 1,
         labels[i].c_str());
    }
    // botoes em baixo
    for (int i = 0; i < 2; i++) {
        mvwprintw(searchWin,
         searchWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
         opcoes[i].c_str());
    }
    wrefresh(searchWin);

    // Refresh nas box's dos form's
    for (int i = 0; i < 5; i++) {
        wrefresh(form[i]);
    }

    // Janela para o log de erro
    auto win_erro = newwin(5, 40, 0, x_max/2 - 20);

    // loop do form
    bool manterBuscaWin = true;
    int highlight = 0;
    int choice = 0;
    Cidade cidadeOobj;
    Estado estadoOobj;
    Cidade cidadeDobj;
    Estado estadoDobj;
    Data dataobj;
    bool deuRuim = false;
    std::vector<Carona> vetor;
    while (true) {
        // Get dos forms
        echo();
        curs_set(1);
        wmove(form[0], 1, 1);
        wgetstr(form[0], cidadeO);
        wmove(form[1], 1, 1);
        wgetstr(form[1], estadoO);
        wmove(form[2], 1, 1);
        wgetstr(form[2], cidadeD);
        wmove(form[3], 1, 1);
        wgetstr(form[3], estadoD);
        wmove(form[4], 1, 1);
        wgetstr(form[4], data);
        noecho();
        curs_set(0);

        if (deuRuim) {
            manterBuscaWin = true;
        }
        // seleção entre o  botao menu e buscar
        while (manterBuscaWin) {
            // printando opções
            for (int i = 0; i < 2; i++) {
                if (i == highlight) {
                    wattron(searchWin, A_REVERSE);
                }

                mvwprintw(searchWin,
                 searchWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
                 opcoes[i].c_str());
                wattroff(searchWin, A_REVERSE);
            }
            choice = wgetch(searchWin);
            // seleção do opção
            switch (choice) {
                case KEY_LEFT:
                    highlight--;
                    if (highlight == -1) {
                        highlight = 0;
                    }
                    break;
                case KEY_RIGHT:
                    highlight++;
                    if (highlight == 2) {
                        highlight = 1;
                    }
                    break;
                default:
                    break;
            }
            // acao do menu de busca
            if (choice == 10) {
                switch (highlight) {
                    case 0:  // Menu
                        for (int i = 0; i < 4; i++) {
                            wclear(form[i]);
                            wrefresh(form[i]);
                            delwin(form[i]);
                        }
                        wclear(win_erro);
                        wrefresh(win_erro);
                        delwin(win_erro);

                        wclear(leftWin);
                        wrefresh(leftWin);
                        delwin(leftWin);

                        wclear(rightWin);
                        wrefresh(rightWin);
                        delwin(rightWin);

                        wclear(searchWin);
                        wrefresh(searchWin);
                        delwin(searchWin);
                        return;
                        break;
                    case 1:  // Buscar
                        deuRuim = false;

                        // verificação dos formatos
                        try {
                            dataobj.setData(data);
                            mvwprintw(win_erro, 0, 0,
                             "                                              ");
                        } catch(...) {
                            mvwprintw(win_erro, 0, 0,
                             "Erro no formato da data");
                            deuRuim = true;
                        }

                        try {
                            cidadeOobj.setCidade(cidadeO);
                            mvwprintw(win_erro, 1, 0,
                            "                         ");
                        } catch(...) {
                            mvwprintw(win_erro, 1, 0,
                            "Erro no formato da cidade de origem");
                            deuRuim = true;
                        }

                        try {
                            estadoOobj.setEstado(estadoO);
                            mvwprintw(win_erro, 2, 0,
                            "                         ");
                        } catch(...) {
                            mvwprintw(win_erro, 2, 0,
                            "Erro no formato do estado de origem");
                            deuRuim = true;
                        }

                        try {
                            cidadeDobj.setCidade(cidadeD);
                            mvwprintw(win_erro, 3, 0,
                            "                         ");
                        } catch(...) {
                            mvwprintw(win_erro, 3, 0,
                            "Erro no formato da cidade de destino");
                            deuRuim = true;
                        }

                        try {
                            estadoDobj.setEstado(estadoD);
                            mvwprintw(win_erro, 4, 0,
                            "                         ");
                        } catch(...) {
                            mvwprintw(win_erro, 4, 0,
                            "Erro no formato do estado de destino");
                            deuRuim = true;
                        }

                        wrefresh(win_erro);
                        // Limpando os campos
                        manterBuscaWin = false;
                        if (deuRuim) {  // saindo caso tenha dado erro
                            for (int i = 0; i < 4; i++) {
                                mvwprintw(form[i], 1, 1,
                                "              ");
                                wrefresh(form[i]);
                            }
                            break;
                        }
                        // aquisição do vetor de caronas
                        vetor = servico->pesquisarCarona(cidadeOobj, estadoOobj, cidadeDobj, estadoDobj, dataobj);
                        clear();
                        refresh();

                        // desenhando tela para mostrar caronas e reservas
                        mvwprintw(leftWin, 0,
                        leftWin->_maxx/2 - caronas.size()/2, caronas.c_str());
                        mvwprintw(leftWin, 1, 1,
                         "Pressione 'q' para voltar ao menu inicial");
                        mvwprintw(rightWin, 0, rightWin->_maxx/2 - 7,
                         "Reservas");
                        wrefresh(leftWin);
                        wrefresh(rightWin);

                        highlight = 0;
                        int a;


                        // escolha de evento
                        while (true) {

                            // printando a lista de todos os eventos


                            for (int i = 0; i < vetor.size(); i++) {
                                if (i == highlight) {
                                    wattron(leftWin, A_REVERSE);
                                }

                                // Fazer metodo ja retorna formatado





                                mvwprintw(leftWin, 2 + i, 3, "Cidade de Origem: %s -Estado de Origem: %s - Cidade de Destino %s - Estado de Destino % - Data %s - Duração %s - Vagas %s - Preço %s");

                                vetor[i].getCidadeOrigem().getCidade();
                                vetor[i].getEstadoOrigem().getEstado();
                                vetor[i].getCidadeDestino().getCidade();
                                vetor[i].getEstadoDestino().getEstado();
                                vetor[i].getData().getData();
                                vetor[i].getDuracao().getDuracao();
                                vetor[i].getVaga().getVaga();
                                vetor[i].getPreco().getPreco();

                                wattroff(leftWin, A_REVERSE);
                            }
                            wrefresh(leftWin);
                            // adiquirindo vetor de apresentação

                            vetor[highlight];  // vetorA=buscaApre(vetor[highlight]) //fazer funcao ou metodo que retona todas as apresentações de um evento passado como parametro

                            // printando as apresentaçoes na janela direita
                            std::string reservaInfo;  // info das apresentações
                            if(vetor.size()!=0) {
                                for (int i = 0; i < vetor[highlight].vecRes.size(); i++) {
                                    // fazer metodo que retorna
                                    //  o q ira aparecer em cada apresentação
                                    //apreInfo = MSE::infoApresentacao(vetor[highlight].vecApres[i]);
                                    //mvwprintw(rightWin, 7*i + 3, 3, apreInfo.c_str());


                                    mvwprintw(rightWin, 2+i + 7*i, 3, "Código de Reserva: %s", vetor[highlight].vecRes[i].getCodigoDeReserva().getCodigoDeReserva().c_str());
                                    mvwprintw(rightWin, 2+i + 7*i, 3, "Assento: %s", vetor[highlight].vecRes[i].getAssento().getAssento().c_str());
                                    mvwprintw(rightWin, 2+i + 7*i, 3, "Bagagem: %s", vetor[highlight].vecRes[i].getBagagem().getBagagem());

                                    /*
                                    mvwprintw(rightWin, 2+i + 7*i, 3, "Código da Apresentação: %s", vetor[highlight].vecApres[i].GetCodigoDeApresentacao().getConteudo().c_str());
                                    mvwprintw(rightWin, 3+i + 7*i, 3, "Data: %s", vetor[highlight].vecApres[i].GetData().getConteudo().c_str());
                                    mvwprintw(rightWin, 4+i + 7*i, 3, "Disponibilidade: %s", vetor[highlight].vecApres[i].GetDisponibilidade().getConteudo().c_str());
                                    mvwprintw(rightWin, 5+i + 7*i, 3, "Horário: %s", vetor[highlight].vecApres[i].GetHorario().getConteudo().c_str());
                                    mvwprintw(rightWin, 6+i + 7*i, 3, "Sala: %s", vetor[highlight].vecApres[i].GetNumeroDeSala().getConteudo().c_str());
                                    mvwprintw(rightWin, 7+i + 7*i, 3, "Preço: %s", vetor[highlight].vecApres[i].GetPreco().getConteudo().c_str());
                                    */
                                }
                            }
                            wrefresh(rightWin);

                            a = wgetch(leftWin);
                            wclear(rightWin);
                            box(rightWin, 0, 0);
                            wrefresh(rightWin);
                            // selecionando evento ou saindo
                            switch (a) {
                                case KEY_UP:
                                    highlight--;
                                    if (highlight == -1) {
                                        highlight = 0;
                                    }
                                    break;
                                case KEY_DOWN:
                                    highlight++;
                                    if (highlight == vetor.size()) {
                                        highlight = vetor.size() - 1;
                                    }
                                    break;

                                case 'q':
                                    wclear(win_erro);
                                    wrefresh(win_erro);
                                    delwin(win_erro);

                                    wclear(leftWin);
                                    wrefresh(leftWin);
                                    delwin(leftWin);

                                    wclear(rightWin);
                                    wrefresh(rightWin);
                                    delwin(rightWin);

                                    wclear(searchWin);
                                    wrefresh(searchWin);
                                    delwin(searchWin);
                                    return;

                                default:
                                    break;
                            }
                        }
                        break;
                    default:
                        break;
                }
            }
        }


    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

    wclear(leftWin);
    wrefresh(leftWin);
    delwin(leftWin);

    wclear(rightWin);
    wrefresh(rightWin);
    delwin(rightWin);

    wclear(searchWin);
    wrefresh(searchWin);
    delwin(searchWin);
    /* */
    }
}


void MAC::criarCarona() {
    echo();
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    wrefresh(stdscr);

    // Janela onde ficara o formulario
    auto janelaCarona = newwin(34, 40, y_max/2 - 17, x_max/2 - 20);
    box(janelaCarona, 0, 0);
    mvwprintw(janelaCarona, 0, janelaCarona->_maxx/2 - 8,"Cadastrar Carona");
    // printando as labels
    std::string labels[9] = {"Código de Carona", "Cidade de Origem", "Estado de Origem", "Cidade de Destino",
                             "Estado de Destino", "Data", "Duração", "Vagas", "Preço"};
    for(int i = 0;i < 9;i++) {
        mvwprintw(janelaCarona, 5 + 3 * i, 20 - labels[i].size()- 1, labels[i].c_str());
    }
    //desenhando na tela
    wrefresh(janelaCarona);
    // janela de erro
    WINDOW* win_erro = newwin(15, 45, 0, x_max/2-20);


    //array de windows para as caixas de texto
    WINDOW* forms[9] = {nullptr};
    for(int i = 0; i < 9; i++) {
        forms[i] = newwin(3, 19, janelaCarona->_begy + 4 + 3 * i, janelaCarona->_begx + 20);
        box(forms[i], 0, 0);
        wrefresh(forms[i]);
    }
    //variaveis para a verificação
    CodigoDeCarona codigoDeCaronaobj;
    Cidade cidadeOobj, cidadeDobj;
    Estado estadoOobj, estadoDobj;
    Data dataobj;
    Duracao duracaoobj;
    Vaga vagaobj;
    Preco precoobj;
    int nmrDeVagas = 0;


    //loop de inserção
    bool manterTelaCadastrarCarona = true;
    char respForm[9][18] = {{' '}};
    curs_set(1);
    while(manterTelaCadastrarCarona){
        //limpando form
        for(int i = 0;i < 9;i++) {
            mvwprintw(forms[i],1,1,"                 ");
            wrefresh(forms[i]);
            wmove(forms[i],1,1);
        }
        //pegando info
        for(int i = 0;i < 9;i++) {
            wgetstr(forms[i],respForm[i]);
        }
        //verificando infos
        {
            manterTelaCadastrarCarona = false;

            try{
                codigoDeCaronaobj.setCodigoDeCarona(respForm[0]);
                mvwprintw(win_erro, 0, 0, "                    ");
            }catch(...) {
                manterTelaCadastrarCarona = true;
                mvwprintw(win_erro, 0, 0, "Erro no código de carona");

            }

            try{
                cidadeOobj.setCidade(respForm[1]);
                mvwprintw(win_erro, 1, 0, "                    ");
            }catch(...) {
                manterTelaCadastrarCarona = true;
                mvwprintw(win_erro, 1, 0, "Erro na cidade de origem");
            }

            try{
                estadoOobj.setEstado(respForm[2]);
                mvwprintw(win_erro, 2, 0, "                    ");
            }catch(...) {
                manterTelaCadastrarCarona = true;
                mvwprintw(win_erro, 2, 0, "Erro no estado de origem");

            }

            try{
                cidadeDobj.setCidade(respForm[3]);
                mvwprintw(win_erro, 3, 0, "                    ");
            }catch(...) {
                manterTelaCadastrarCarona = true;
                mvwprintw(win_erro, 3, 0, "Erro na cidade de destino");

            }

            try{
                estadoDobj.setEstado(respForm[4]);
                mvwprintw(win_erro, 4, 0, "                    ");
            }catch(...) {
                manterTelaCadastrarCarona = true;
                mvwprintw(win_erro, 4, 0, "Erro no estado de destino");

            }

            try{
                dataobj.setData(respForm[5]);
                mvwprintw(win_erro, 5, 0, "                    ");
            }catch(...) {
                manterTelaCadastrarCarona = true;
                mvwprintw(win_erro, 5, 0, "Erro na data");

            }

            try{
                //int duracaoInt = duracaoobj.getDuracao();

                duracaoobj.setDuracao(atoi(respForm[6]));
                mvwprintw(win_erro, 6, 0, "                    ");
            }catch(...) {
                manterTelaCadastrarCarona = true;
                mvwprintw(win_erro, 6, 0, "Erro na duração");

            }

            try{
                vagaobj.setVaga(atoi(respForm[7]));
                //nmrDeVagas = stoi(vagaobj);
                if(atoi(respForm[7]) > 4) {
                    manterTelaCadastrarCarona = true;
                    mvwprintw(win_erro, 7, 0, "Erro no numero de vagas");
                }
                else {
                    mvwprintw(win_erro, 7, 0, "                    ");
                }
            }catch(...) {
                manterTelaCadastrarCarona = true;
                mvwprintw(win_erro, 7, 0, "Erro no número de vagas");

            }


            try{
                precoobj.setPreco(atof(respForm[8]));
                mvwprintw(win_erro, 8, 0, "                    ");
            }catch(...) {
                manterTelaCadastrarCarona = true;
                mvwprintw(win_erro, 8, 0, "Erro no preço");

            }


            wrefresh(win_erro);
        }

    }

    wclear(janelaCarona);
    wrefresh(janelaCarona);
    delwin(janelaCarona);

    for(int i = 0;i < 7;i++) {
        wclear(forms[i]);
        wrefresh(forms[i]);
        delwin(forms[i]);
    }


    //Construindo o objeto evento

    Carona carona;
    carona.setCidadeOrigem(cidadeOobj);
    carona.setEstadoOrigem(estadoOobj);
    carona.setCidadeDestino(cidadeDobj);
    carona.setEstadoDestino(estadoDobj);
    carona.setData(dataobj);
    carona.setDuracao(duracaoobj);
    carona.setVaga(vagaobj);
    carona.dono.setEmail(controller->getEmail());

    //vetor de apresentações
    std::vector<Reserva> vecReserva(nmrDeVagas);

    // janela onde sera criado as apresentações
    auto janelaCriarReserva = newwin(23, 40, y_max/2 - 10, x_max/2 - 20);
    box(janelaCriarReserva, 0, 0);
    mvwprintw(janelaCriarReserva, 0, janelaCriarReserva->_maxx/2 - 10,"Criar Reserva ");
    //printando as labels
    std::string labels2[2] = {"Assento", "Bagagem"};
    for(int i = 0;i < 2;i++) {
        mvwprintw(janelaCriarReserva, 5 + 3 * i, 20 - labels2[i].size() - 1, labels2[i].c_str());
    }

    //desenhando a tela
    wclear(win_erro);
    wrefresh(win_erro);
    wrefresh(janelaCriarReserva);


    for(int i = 0; i < 2; i++) {
        forms[i] = newwin(3, 19, janelaCriarReserva->_begy + 4 + 3 * i, janelaCriarReserva->_begx + 20);
        box(forms[i], 0, 0);
        wrefresh(forms[i]);
    }

    //Variaveis para verificação
    Assento assentoobj;
    Bagagem bagagemobj;

    //loop para cração de reservas
    bool manterCriaReserva = true;
    Reserva reserva;
    for(int i = 0;i < nmrDeVagas;i++) {
        //printando o numero da apresentação no top da tela
        mvwprintw(janelaCriarReserva, 0, janelaCriarReserva->_maxx/2 + 9,"%d", i + 1);
        wrefresh(janelaCriarReserva);
        //loop de uma janela
        while(janelaCriarReserva) {
            //limpando forms
            for(int i = 0;i < 2;i++) {
                mvwprintw(forms[i],1,1,"                 ");
                wrefresh(forms[i]);
                wmove(forms[i],1,1);
            }

            //pegando info
            for(int i = 0;i < 2;i++) {
                wgetstr(forms[i],respForm[i]);
            }

            //verificando as infos
            {
                manterCriaReserva = false;
                try{
                    assentoobj.setAssento(respForm[0]);
                    mvwprintw(win_erro, 0, 0, "                       ");
                }catch(...){
                    manterCriaReserva = true;
                    mvwprintw(win_erro, 0, 0, "Erro no assento");
                }

                try{
                    bagagemobj.setBagagem(atoi(respForm[1]));
                    mvwprintw(win_erro, 1, 0, "                       ");
                }catch(...){
                    manterCriaReserva = true;
                    mvwprintw(win_erro, 1, 0, "Erro na bagagem");
                }


                wrefresh(win_erro);

            }
        }
        wclear(win_erro);
        wrefresh(win_erro);

        reserva.setAssento(assentoobj);
        reserva.setBagagem(bagagemobj);

        manterCriaReserva = true;
        vecReserva[i] = reserva;
    }
    Email email;
    email.setEmail(controller->getEmail());
    servico->cadastrarCarona(email, carona, vecReserva);


    wclear(janelaCriarReserva);
    wrefresh(janelaCriarReserva);
    delwin(janelaCriarReserva);


    for(int i = 0; i < 2; i++) {
        wclear(forms[i]);
        wrefresh(forms[i]);
        delwin(forms[i]);
    }

    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

    wrefresh(stdscr);
}



//////////////////////////////////
void MAR::executar() {

    char CodRes[4];
    char qtd[4];

    std::string opcoes[2] = {"Menu", "Reservar"};
    std::string compra = "Reserva";

    //clear();
    erase();
    refresh();

    int y_max, x_max, wy_max, wx_max;
    getmaxyx(stdscr, y_max, x_max);

    auto reservaWin = newwin(14, 50, y_max/2 - 7, x_max/2 - 25);
    auto win_erro = newwin(5, 50, 0, x_max/2 - 20);
    box(reservaWin, 0, 0);
    keypad(reservaWin, true);
    getmaxyx(reservaWin, wy_max, wx_max);
    mvwprintw(reservaWin, 0, reservaWin->_maxx / 2 - compra.size() / 2,
     compra.c_str());

    WINDOW* form[3];
    std::string labels[3] = {"Codigo da Carona", "Numero de Bagagem", "Vagas"};

    for (int i = 0; i < 3; i++) {
        form[i] = newwin(3, 17, reservaWin->_begy + 3 + i * 3,
         reservaWin->_begx + reservaWin->_maxx - 19);
        box(form[i], 0, 0);
    }

    for (int i = 0; i < 3; i++) {
        mvwprintw(reservaWin, form[i]->_begy - reservaWin->_begy + 1,
         form[i]->_begx - reservaWin->_begx - labels[i].size() - 1,
         labels[i].c_str());
    }

    for (int i = 0; i < 3; i++) {
        mvwprintw(reservaWin,
         reservaWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
         opcoes[i].c_str());
    }
    wrefresh(reservaWin);

    for (int i = 0; i < 3; i++) {
        wrefresh(form[i]);
    }

    int highlight = 0;
    int choice = 0;
    bool deuRuim = false;
    bool manterreservaWin = true;
    CodigoDeReserva codRes;
    CodigoDeCarona codCar;
    Conta conta;
    Reserva reserva;
    Email dono;

    while (true) {
        echo();
        curs_set(1);
        wmove(form[0], 1, 1);
        wgetstr(form[0], CodRes);
        wmove(form[1], 1, 1);
        wgetstr(form[1], qtd);
        noecho();
        curs_set(0);

        if (deuRuim) {
            manterreservaWin = true;
        }

        while (manterreservaWin) {
            for (int i = 0; i < 2; i++) {
                if (i == highlight) {
                    wattron(reservaWin, A_REVERSE);
                }
                mvwprintw(reservaWin,
                 reservaWin->_maxy - 1, 5 + i * (30 - opcoes[i].size()),
                 opcoes[i].c_str());
                wattroff(reservaWin, A_REVERSE);
            }
            choice = wgetch(reservaWin);

            switch (choice) {
                case KEY_LEFT:
                    highlight--;
                    if (highlight == -1) {
                        highlight = 0;
                    }
                    break;
                case KEY_RIGHT:
                    highlight++;
                    if (highlight == 2) {
                        highlight = 1;
                    }
                    break;
                default:
                    break;
            }

            if (choice == 10) {
                switch (highlight) {
                    case 0: // Menu
                        for (int i = 0; i < 2; i++) {
                        wclear(form[i]);
                        wrefresh(form[i]);
                        delwin(form[i]);
                        }
                        wclear(reservaWin);
                        wrefresh(reservaWin);
                        delwin(reservaWin);

                        wclear(win_erro);
                        wrefresh(win_erro);
                        delwin(win_erro);

                        return;
                        break;
                    case 1: // Confirmar
                        reserva = servico->listarReservas(codRes);
                        if (reserva.getCodigoDeReserva().getCodigoDeReserva().empty()) {
                            mvwprintw(win_erro, 0, 0, "Reserva não Encontrada");
                            deuRuim = true;
                            //break;
                        } else if (std::stoi(reserva.getAssento().getAssento()) == 0) {
                           mvwprintw(win_erro, 1, 0, "Sem assentos disponíveis");
                            deuRuim = true;
                            //break;
                        }

                        wrefresh(win_erro);
                        manterreservaWin = false;
                        if (deuRuim) {
                            for (int i = 0; i < 2; i++) {
                                mvwprintw(form[i], 1, 1, "          ");
                                wrefresh(form[i]);
                            }
                            break;
                        }

                        dono.setEmail(controller->getEmail());
                        codRes.setCodigoDeReserva(CodRes);
                        servico->reservar(reserva);



                        break;
                    default:
                        break;
                }
            }
        }
        if (!deuRuim) {
            break;
        }
    }

    for (int i = 0; i < 2; i++) {
        wclear(form[i]);
        wrefresh(form[i]);
        delwin(form[i]);
    }
    wclear(reservaWin);
    wrefresh(reservaWin);
    delwin(reservaWin);

    wclear(win_erro);
    wrefresh(win_erro);
    delwin(win_erro);

    return;

}



////////////////////////////////
