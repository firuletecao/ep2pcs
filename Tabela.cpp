#include "Tabela.h"

Tabela::Tabela(Equipe** participantes, int quantidade)
{
    if(quantidade<2){
        throw new invalid_argument("aaa");
    }
    participantes= new Equipe* [quantidade];
    this->participantes=participantes;
    quantidadeDeEquipes=quantidade;

}

Tabela::~Tabela(){}

 int Tabela::getQuantidadeDeEquipes(){
     return quantidadeDeEquipes;
 }
 void Tabela::imprimir(){
 }
