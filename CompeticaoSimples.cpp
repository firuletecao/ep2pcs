#include "CompeticaoSimples.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m) : Competicao(nome, equipes, quantidade) {
    modalidade = m;
}

CompeticaoSimples::~CompeticaoSimples() {

}

Modalidade* CompeticaoSimples::getModalidade() {
    return modalidade;
}
