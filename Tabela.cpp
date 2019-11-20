#include "Tabela.h"
#include <string>
#include <iostream>

Tabela::Tabela(Equipe** participantes, int quantidade) {

    if(quantidade < 2) { //NAO FORNECE TABELA PARA APENAS UMA EQUIPE
        throw new invalid_argument("Nao ha equipes suficientes.");
    }

    quantidadeDeEquipes = quantidade;
    this->participantes = new Equipe* [quantidade];

    for(int i = 0; i < quantidadeDeEquipes; i++){ //SALVA O PARAMETRO EQUIPE** PARTICIPANTES EM UM OUTRO EQUIPE** PARTICIPANTES PROPRIO DA CLASSE TABELA
        this->participantes[i] = participantes[i];
    }

}

Tabela::~Tabela(){}

 int Tabela::getQuantidadeDeEquipes() {
     return quantidadeDeEquipes;
 }

