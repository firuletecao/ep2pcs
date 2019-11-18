#include "Tabela.h"

Tabela::Tabela(Equipe** participantes, int quantidade) {
    if(quantidade < 2) {
        throw new invalid_argument("Nao ha equipes suficientes.");
    }

    quantidadeDeEquipes = quantidade;
    participantes = new Equipe* [quantidade];

    for(int i = 0; i < quantidadeDeEquipes; i++){
        this->participantes[i] = participantes[i];
    }

}

Tabela::~Tabela(){}

 int Tabela::getQuantidadeDeEquipes() {
     return quantidadeDeEquipes;
 }

