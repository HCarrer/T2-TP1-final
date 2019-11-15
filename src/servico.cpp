#include <vector>
#include <unordered_map>
#include "modulos.h"

std::unordered_map<std::string, Usuario> usuarioTable;
std::unordered_map<std::string, Carona> caronaTable;
std::unordered_map<std::string, Reserva> reservaTable;
std::unordered_map<std::string, Conta> contaTable;

bool MSA::autenticar(Email& email, Senha& senha) {
    auto aux = usuarioTable.find(email.getEmail());

    if (aux == usuarioTable.end()) {
        return false;
    }
    if (aux->second.getSenha().getSenha() == senha.getSenha()) {
        return true;
    }
    return false;
}


////////////////////////
bool MSU::cadastrar(Usuario& usuario, Conta& conta) {
    auto user = usuario;
    user.conta = &conta;

    auto aux = usuarioTable.find(user.getEmail().getEmail());
    if(aux == usuarioTable.end()) {
        usuarioTable[user.getEmail().getEmail()] = user;
        return true;
    }
    else {
        return false;
    }
}

bool MSU::descadastrar(Email& email) {
    if(usuarioTable[email.getEmail()].vecCarona.size() == 0) {
        usuarioTable.erase(email.getEmail());
        return true;
    }
    else {
        return false;
    }
}

Usuario MSU::infoLoggedUser(std::string email) {
    Usuario tmp;
    auto aux = usuarioTable.find(email);

    return tmp = aux->second;
}



/////////////////////////
int MSC::dateToInt(std::string data) {
    auto diaS = data.substr(0,2);
    auto mesS = data.substr(3,2);
    auto anoS = data.substr(6,2);

    int dia = std::stoi(diaS);
    int mes = std::stoi(mesS);
    int ano = std::stoi(anoS);

    return dia + 100 * mes + 10000 * ano;
}

bool MSC::cadastrarCarona(Email& email, Carona& carona, std::vector<Reserva>& vecReserva) {
/*
    auto caron = carona;
    auto aux_usr = usuarioTable.find(email.getEmail());
    Usuario &tmp = aux_usr->second;
    caron.vecRes = vecReserva;
    static std::string codCarona = "0000";
    CodigoDeCarona codCaron;
    codCaron.setCodigoDeCarona(codCarona);

    caron.setCodigoDeCarona(codCaron);
    // setando aque carona pertence
    for(int i = 0;i < caron.vecRes.size();i++) {
        caron.vecRes[i].carona.setCodigoDeCarona(codCarona);
    }
*/
}

bool MSC::descadastrarCarona(CodigoDeCarona& codigoDeCarona) {
}

std::vector<Carona> MSC::pesquisarCarona(Cidade cidadeDeOrigem, Estado estadoDeOrigem, Cidade cidadeDeDestino, Estado estadoDeDestino, Data data) {
/*
    std::vector<Carona> vetor1, vetor2;

    for(auto carona : caronaTable) {
        vetor1.push_back(carona.second);
    }

    for(auto carona : vetor1) {
        if(carona.getEstadoOrigem().getEstado() == estadoDeOrigem().getEstado()) {
            vetor2.push_back(carona);
        }
    }
*/



    std::vector<Carona> aux1, aux2;
    for(auto carona : caronaTable){
        aux1.push_back(carona.second);
    }

    for(auto carona : aux1) {
        if(carona.getEstadoOrigem().getEstado() == estadoDeOrigem.getEstado()) {
            aux2.push_back(carona);
        }
    }
    aux1.clear();
    for(auto carona : aux2) {
        if(carona.getCidadeOrigem().getCidade() == cidadeDeOrigem.getCidade()) {
           aux1.push_back(carona);
        }
    }
    aux2.clear();

    for(auto carona : aux1) {
        for(auto caron : carona.vecRes) {
            if(dateToInt(caron.getData().getData()) <= dateToInt(data.getData())) {
                aux2.push_back(carona);
                break;
            }
        }
    }
    aux1.clear();

    for(auto carona : aux2) {
        for(auto reserva : carona.vecRes) {
            if(dateToInt(reserva.getData().getData()) >= dateToInt(data.getData())) {
                aux1.push_back(carona);
                break;
            }
        }
    }


    return aux1;

}

/////////////////////////
bool MSR::reservar(Reserva& reserva) {
}

bool MSR::cancelarReserva(Reserva& reserva) {
}

Reserva MSR::listarReservas(CodigoDeReserva& codigoDeReserva) {

    auto aux = reservaTable.find(codigoDeReserva.getCodigoDeReserva());
    Reserva vazio;
    if (aux == reservaTable.end()) {
        return vazio;
    } else {
        return aux->second;
    }

}
