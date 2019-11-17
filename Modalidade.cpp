#include "Modalidade.h"

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade) {
    this->nome = nome;
    quantidadeDeEquipes = quantidade;
    existeResultado = 0;

    if(quantidade < 2) {
        throw new invalid_argument("Nao ha equipes suficientes.");
    }
    equipes = new Equipe* [quantidadeDeEquipes];

    for(int i = 0; i < quantidadeDeEquipes; i++){
        equipes[i] = participantes[i];
    }
}

Modalidade::~Modalidade() {}
string Modalidade::getNome() {
    return nome;
}

Equipe** Modalidade::getEquipes() {
    return equipes;
}

int Modalidade::getQuantidadeDeEquipes() {
    return quantidadeDeEquipes;
}

void Modalidade::setResultado(Equipe** ordem) {
    resultado = new Equipe* [quantidadeDeEquipes];

    for(int i = 0; i < quantidadeDeEquipes; i++){
        //RESULTADO[0] EH A CAMPEA, RESULTADO[1] EH A SEGUNDA COLOCADA...
        resultado[i] = ordem[i];
    }
    //CONTABILIZANDO QUE SETRESULTADO JA FOI CHAMADO UMA OU MAIS VEZES
    existeResultado = 1;
}

bool Modalidade::temResultado() {
    if(existeResultado = 1) {
        return true;
    } else return false;
}

TabelaComOrdem* Modalidade::getTabela() {
            tabelaModalidade=TabelaComOrdem(resultado, quantidadeDeEquipes);
            return tabelaModalidade;
}

void Modalidade::imprimir() {
    cout << "Modalidade" << getNome() << endl;
    //CHAMADA DO METODO IMPRIMIR DA TABELACOMORDEM
}
