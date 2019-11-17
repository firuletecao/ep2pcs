#ifndef COMPETICAO_H
#define COMPETICAO_H
#include <iostream>
#include <stdexcept>
#include <string>
#include "Equipe.h"

using namespace std;


class Competicao {
    public:
        Competicao(string nome, Equipe** equipes, int quantidade);
        virtual ~Competicao();

        string getNome();
        Equipe** getEquipes();
        int getQuantidadeDeEquipes();

        Tabela* getTabela();
        void imprimir();

    protected:
        int quantidadeDeEquipes;
        string nome;
        Equipe** equipesParticipantes;
};

#endif // COMPETICAO_H
