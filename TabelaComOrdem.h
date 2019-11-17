#ifndef TABELACOMORDEM_H
#define TABELACOMORDEM_H
#include <string>
#include <stdexcept>
#include<stdio.h>
#include "Equipe.h"
#include "Tabela.h"

using namespace std;


class TabelaComOrdem:public Tabela
{
    public:
        TabelaComOrdem(Equipe** participantes, int quantidade);
        virtual ~TabelaComOrdem();
        void setResultado(Equipe** ordem);
        int getPosicao(Equipe* participante);
        Equipe** getEquipesEmOrdem();
        void imprimir();

    private:
        Equipe** ordem;
        bool TemResultado;
};

#endif // TABELACOMORDEM_H
