#include "Competicao.h"

Competicao::Competicao(string nome, Equipe** equipes, int quantidade) {
    this->nome = nome;
    quantidadeDeEquipes = quantidade;

    if(quantidadeDeEquipes < 2) throw new invalid_argument("Nao ha equipes suficientes");

    this->equipesParticipantes = new Equipe* [quantidade];

    for(int i = 0; i < quantidadeDeEquipes; i++) {
        equipesParticipantes[i] = equipes[i];
    }
}

Competicao::~Competicao() {

}

string Competicao::getNome(){
    return nome;
}

Equipe** Competicao::getEquipes() {
    return equipesParticipantes;
}

int Competicao::getQuantidadeDeEquipes() {
    return quantidadeDeEquipes;
}

