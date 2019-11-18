#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H

#include "Equipe.h"
#include "Modalidade.h"
#include "Competicao.h"
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"
#include <list>
#include <vector>

using namespace std;

class CompeticaoMultimodalidades: public Competicao {
    public:
        CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
        virtual ~CompeticaoMultimodalidades();

        void adicionar(Modalidade* m);
        list<Modalidade*>* getModalidades();
        Tabela* getTabela();

        static void setPontuacao(vector<int>* pontos);
        static int getPontoPorPosicao(int posicao);
        void imprimir();

    private:
        int quantidadeDeModalidades;
        string nome;
        Equipe** equipesParticipantes;
        list<Modalidade*>* listaDeModalidades;
        static vector<int>* pontuacao;
};

#endif // COMPETICAOMULTIMODALIDADES_H
