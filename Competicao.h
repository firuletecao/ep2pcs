#ifndef COMPETICAO_H
#define COMPETICAO_H
#include <stdexcept>
#include "Tabela.h"
#include "Equipe.h"

using namespace std;


class Competicao {
    public:
        Competicao(string nome, Equipe** equipes, int quantidade);
        virtual ~Competicao();

        string getNome();
        Equipe** getEquipes();
        int getQuantidadeDeEquipes();

        virtual Tabela* getTabela() = 0;
        virtual void imprimir() = 0;

    protected:
        int quantidadeDeEquipes;
        string nome;
        Equipe** equipesParticipantes;
};

#endif // COMPETICAO_H
