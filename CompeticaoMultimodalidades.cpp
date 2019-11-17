#include "CompeticaoMultimodalidades.h"

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade): Competicao(nome, equipes, quantidade) {
    listaDeModalidades = new list<Modalidade*>();

}

CompeticaoMultimodalidades::~CompeticaoMultimodalidades() {

}

void CompeticaoMultimodalidades::adicionar(Modalidade* m) {
    listaDeModalidades->push_back(m);
}

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades() {
    return listaDeModalidades;
}

Tabela* CompeticaoMultimodalidades::getTabela() {

}

vector<int>* CompeticaoMultimodalidades::pontuacao = new vector<int>({13,10,8,7,5,4,3,2,1});

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos) {
    for(int i = 0; i < 9; i++) {
        pontuacao->at(i) = pontos->at(i);
    }
}

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao) {

    switch (posicao)
    {
        case 1:
            return pontuacao->at(0);
            break;
        case 2:
            return pontuacao->at(1);
            break;
        case 3:
            return pontuacao->at(2);
            break;
        case 4:
            return pontuacao->at(3);
            break;
        case 5:
            return pontuacao->at(4);
            break;
        case 6:
            return pontuacao->at(5);
            break;
        case 7:
            return pontuacao->at(6);
            break;
        case 8:
            return pontuacao->at(7);
            break;
        case 9:
            return pontuacao->at(8);
            break;
        default:
            return 0;

    }
}

void CompeticaoMultimodalidades::imprimir() {

}
