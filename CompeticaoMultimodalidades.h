#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H
#include "Equipe.h"
#include "Modalidade.h"
#include "Competicao.h"

using namespace std;

class CompeticaoMultimodalidades
{
    public:
        CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
        virtual ~CompeticaoMultimodalidades();

        void adicionar(Modalidade* m);
        list<Modalidade*>* getModalidades();

        static void setPontuacao(vector<int>* pontos);
        static int getPontoPorPosicao(int posicao);

    private:
};

#endif // COMPETICAOMULTIMODALIDADES_H
