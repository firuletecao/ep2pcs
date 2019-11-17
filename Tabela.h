#ifndef TABELA_H
#define TABELA_H
#include <string>
#include <stdexcept>
#include<stdio.h>
#include "Equipe.h"

using namespace std;


class Tabela
{
    public:
        Tabela(Equipe** participantes, int quantidade);
        virtual ~Tabela();

        virtual int getPosicao(Equipe* participante)=0;
        virtual Equipe** getEquipesEmOrdem()=0;
        virtual int getQuantidadeDeEquipes();
        virtual void imprimir();
    protected:
        Equipe** participantes;
        int quantidadeDeEquipes;

};

#endif // TABELA_H
