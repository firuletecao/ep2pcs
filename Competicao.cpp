#include "Competicao.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

Competicao::Competicao(string nome, Equipe** equipes, int quantidade) {
    this->nome = nome;
    quantidadeDeEquipes = quantidade;

    if(quantidadeDeEquipes < 2) throw new invalid_argument("Nao ha equipes suficientes");

    equipesParticipantes = new Equipe* [quantidadeDeEquipes];

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

Tabela* Competicao::getTabela() {
    //COMP SIMPLES: TABELA EH A MESMA DE MODALIDADES
    //COMP MULTI: TABELA DEVE CONSIDERAR AS PONTUACOES ATUAIS DAS EQUIPES EM CADA MODALIDADE ADICIONADAS E SOMA-LAS, CASO NAO HAJA RESULTADO, IGNORAR A MODALIDADE
}

void Competicao::imprimir() {
    cout << getNome << endl;
    //CHAMADA DO METODO IMPRIMIR DA TABELA OU VAZIO CASO AINDA NOA HAJA TABELA
}
