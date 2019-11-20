#include "TabelaComOrdem.h"
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
    TabelaComPontos* tabelaAtualizada = new TabelaComPontos(equipesParticipantes, quantidadeDeEquipes);

    //O VETOR EQUIPESPARTICIPANTES TEM A ORDEM DAS EQUIPES CONFORME ENTRADA DO USUARIO
    //O VETOR PONTUACAO GUARDA CORRESPONDENTE A CADA COLOCACAO NA MODALIDADE
    //TABELAATUALIZADA EH UMA TABELA QUE GUARDA OS PONTOS DAS EQUIPES NA ORDEM DE ENTRADA PELO USUARIO

    int j;
    list<Modalidade*>::iterator i;

    for( i = listaDeModalidades->begin(); i != listaDeModalidades->end(); i++) { //VARRE A LISTA DO COMEÇO AO FIM
        if((*i)->temResultado()) {
            for(j = 0; j < quantidadeDeEquipes; j++) {
                for(int c = 0; c < quantidadeDeEquipes; c++) {
                    if((*i)->getTabela()->getEquipesEmOrdem()[c] == equipesParticipantes[j]) {
                            tabelaAtualizada->pontuar(equipesParticipantes[j],pontuacao->at(c));

                    }
                }
            }
        }
    }
    return tabelaAtualizada;
}

vector<int>* CompeticaoMultimodalidades::pontuacao = new vector<int>({13,10,8,7,5,4,3,2,1});

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos) { //ATUALIZA A PONTUACAO DE UMA DADA COMPETICAO
    for(int i = 0; i < 9; i++) {
        pontuacao->at(i) = pontos->at(i);
    }
}

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao) { //AQUI O SWITCH CASE ENGLOBA TODAS AS POSSIBILIDADES DE PONTUAR EM RELACAO A UMA DETERMINADA ORDEM

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
    cout << nome << endl;
    Tabela* tabelaParaImprimi = getTabela();
    TabelaComPontos* tabelaParaImprimir = dynamic_cast<TabelaComPontos*>(tabelaParaImprimi);
    list<Modalidade*>::iterator i;
                for(int c = 0; c < quantidadeDeEquipes; c++) {
                    cout << "\t" << c + 1 << "o " <<tabelaParaImprimir->getEquipesEmOrdem()[c]->getNome()<<"(" << tabelaParaImprimir->getPontos(tabelaParaImprimir->getEquipesEmOrdem()[c]) << ")"<<"pontos" << endl;
                }
}

