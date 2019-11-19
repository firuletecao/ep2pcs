#include "CompeticaoSimples.h"


CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m) : Competicao(nome, equipes, quantidade) {
    modalidade = m;
}

CompeticaoSimples::~CompeticaoSimples() {

}

Modalidade* CompeticaoSimples::getModalidade() {
    return modalidade;
}

Tabela* CompeticaoSimples::getTabela() {
     return modalidade->getTabela();
}

void CompeticaoSimples::imprimir() {

    cout << nome << endl;
    modalidade->imprimir();
}

