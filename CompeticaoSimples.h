#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H
#include "Equipe.h"
#include "Modalidade.h"
#include "Competicao.h"
#include "Tabela.h"

using namespace std;

class CompeticaoSimples: public Competicao {
    public:
        CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
        virtual ~CompeticaoSimples();

        Tabela* getTabela();
        Modalidade* getModalidade();
        void imprimir();

    private:
        Modalidade* modalidade;
};

#endif // COMPETICAOSIMPLES_H
