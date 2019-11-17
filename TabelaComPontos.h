#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H
#include <string>
#include <stdexcept>
#include<stdio.h>
#include "Equipe.h"
#include "Tabela.h"

using namespace std;


class TabelaComPontos: public Tabela
{
    public:
        TabelaComPontos(Equipe** participantes, int quantidade);
        virtual ~TabelaComPontos();
        int getPontos(Equipe* participante);
        void pontuar(Equipe* participante, int pontos);
        int getPosicao(Equipe* participante);
        Equipe** getEquipesEmOrdem();
        void imprimir();

    private:
        int* pontuacao;
        Equipe** ordenado;
};

#endif // TABELACOMPONTOS_H
