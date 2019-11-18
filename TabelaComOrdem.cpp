#include "TabelaComOrdem.h"

TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade):Tabela(participantes, quantidade)
{}

TabelaComOrdem::~TabelaComOrdem(){}

void TabelaComOrdem::setResultado(Equipe** ordem){
    for(int i=0; i<quantidadeDeEquipes; i++){
        participantes[i]=ordem[i];
    }
    TemResultado=true;
}

int TabelaComOrdem::getPosicao(Equipe* participante){
    if(TemResultado){
      for(int i=0; i<quantidadeDeEquipes; i++){
            if(participantes[i]=participante){
                return i;
            }
      }
      throw new invalid_argument("Essa equipe nao faz parte");
    }
    throw new logic_error("nao ha resultado ainda");
}
Equipe** TabelaComOrdem::getEquipesEmOrdem(){
    if(TemResultado){
        return participantes;
    }
    throw new logic_error("Um resultado ainda nao foi definido");
}

void TabelaComOrdem::imprimir(){
    if(!TemResultado){
        for(int i=0;i<quantidadeDeEquipes;i++){
            cout<<"\t"<<participantes[i]->getNome()<<endl;
        }
    }else{
        for(int j=0;j<quantidadeDeEquipes;j++){
            cout<<"\t"<<j<<"o "<<ordem[j]->getNome()<<endl;
        }
    }

}

