#include "Competicao.h"

Competicao::Competicao(string nome, Equipe** equipes, int quantidade) {
    this->nome = nome;
    quantidadeDeEquipes = quantidade;

    if(quantidadeDeEquipes < 2) throw new invalid_argument("Nao ha equipes suficientes"); //NAO GERA COMPETICAO PARA APENAS UMA EQUIPE

    this->equipesParticipantes = new Equipe* [quantidade];

    for(int i = 0; i < quantidadeDeEquipes; i++) { // SALVA O PARAMETRO EQUIPES RECEBIDO EM UM EQUIPESPARTICIPANTES PROPRIO DA CLASSE COMPETICAO
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

