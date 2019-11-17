#include "Modalidade.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade) {
    this->nome = nome;
    quantidadeDeEquipes = quantidade;
    temResultado = 0;

    if(quantidade < 2) {
        throw new invalid_argument("Nao ha equipes suficientes.");
    }
    equipes = new Equipe* [quantidadeDeEquipes];

    for(int i = 0; i < quantidadeDeEquipes; i++){
        equipes[i] = participantes[i];
    }
}

Modalidade::~Modalidade() {

}

string Modalidade::getNome() {
    return nome;
}

Equipe** Modalidade::getEquipes() {
    return equipes;
}

int Modalidade::getQuantidadeDeEquipes() {
    return quantidadeDeEquipes;
}

void Modalidade::setResultado(Equipe** ordem) {
    resultado = new Equipe* [quantidadeDeEquipes];

    for(int i = 0; i < quantidadeDeEquipes; i++){
        //RESULTADO[0] EH A CAMPEA, RESULTADO[1] EH A SEGUNDA COLOCADA...
        resultado[i] = ordem[i];
    }
    //CONTABILIZANDO QUE SETRESULTADO JA FOI CHAMADO UMA OU MAIS VEZES
    temResultado = 1;
}

bool Modalidade::temResultado() {
    if(temResultado = 1) {
        return true;
    } else return false;
}

TabelaComOrdem* Modalidade::getTabela() {

}

void Modalidade::imprimir() {
    cout << "Modalidade" << getNome() << endl;
    //CHAMADA DO METODO IMPRIMIR DA TABELACOMORDEM
}
