#include "TabelaComOrdem.h"

TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade):Tabela(participantes, quantidade)
{}

TabelaComOrdem::~TabelaComOrdem(){}

void TabelaComOrdem::setResultado(Equipe** ordem){
    for(int i=0; i<quantidadeDeEquipes; i++){
        participantes[i]=ordem[i];
    }
    TemResultado=1;
}

int TabelaComOrdem::getPosicao(Equipe* participante){
    if(TemResultado==1){
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
    if(TemResultado==1){
        return participantes;
    }
    throw new logic_error("Um resultado ainda nao foi definido");
}

void TabelaComOrdem::imprimir(){
    if(TemResultado==0){
        for(int i=0;i<quantidadeDeEquipes;i++){
            cout<<"\t"<<participantes[i]->getNome()<<endl;
        }
    }else{
        for(int j=0;j<quantidadeDeEquipes;j++){
            cout<<"\t"<<j+1<<"o "<<participantes[j]->getNome()<<endl;
        }
    }

}

