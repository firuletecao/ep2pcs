#ifndef MODALIDADE_H
#define MODALIDADE_H
#include <iostream>
#include <stdexcept>
#include <string>
#include "Equipe.h"

using namespace std;

class Modalidade {
    public:
        Modalidade(string nome, Equipe** participantes, int quantidade);
        virtual ~Modalidade();

        virtual string getNome();
        virtual Equipe** getEquipes();
        virtual int getQuantidadeDeEquipes();

        virtual void setResultado(Equipe** ordem);
        virtual bool temResultado();
        virtual TabelaComOrdem* getTabela();

        virtual void imprimir();

    private:
        Equipe** equipes;
        Equipe** resultado;
        string nome;
        int quantidadeDeEquipes;
        int temResultado;
};

#endif // MODALIDADE_H
