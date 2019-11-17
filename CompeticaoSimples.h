#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H
#include <iostream>
#include <stdexcept>
#include <string>
#include "Equipe.h"
#include "Modalidade.h"
#include "Competicao.h"

using namespace std;

class CompeticaoSimples: public Competicao {
    public:
        CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
        virtual ~CompeticaoSimples();

        Modalidade* getModalidade();
    private:
        Modalidade* modalidade;
};

#endif // COMPETICAOSIMPLES_H
