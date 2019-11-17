#ifndef MODALIDADE_H
#define MODALIDADE_H

#include <stdexcept>
#include "TabelaComOrdem.h"
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
        int existeResultado;
        TabelaComOrdem* tabelaModalidade;
};

#endif // MODALIDADE_H
