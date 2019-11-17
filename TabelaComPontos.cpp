#include "TabelaComPontos.h"

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade):Tabela(participantes, quantidade)
{
        pontuacao= new int[quantidade];
        for(int i=0; i<quantidade; i++){
            pontuacao[i]=0;
        }
        ordenado= new Equipe*[quantidade];
}

TabelaComPontos::~TabelaComPontos(){}

int TabelaComPontos::getPontos(Equipe* participante){
    for(int i=0; i<quantidadeDeEquipes; i++){
        if(participantes[i]==participante){
            return pontuacao[i];
        }
    }
    throw new invalid_argument("a equipe que voce esta tentando conseguir os pontos nao faz parte da tabela");
}
void TabelaComPontos::pontuar(Equipe* participante, int pontos){
        for(int i=0; i<quantidadeDeEquipes; i++){
            if(participantes[i]==participante){
                pontuacao[i]=pontuacao[i]+pontos;
            }
        }
        throw new invalid_argument("A equipe que voce esta tetando pontuar nao faz parte");
}
int TabelaComPontos::getPosicao(Equipe* participante){
    int j=1, l=0, posicaoDoParticipante;
    for(int i=0;i<quantidadeDeEquipes;i++){
        if(participantes[i]==participante){
            l=1;
            posicaoDoParticipante=i;
        }
    }
    if(l=0){
        throw new invalid_argument("A equipe nao faz parte da tabela");
    }
    for(int k=0;k<quantidadeDeEquipes;k++){
        if(participante!=participantes[k]){
            if(pontuacao[posicaoDoParticipante]<pontuacao[k]){
                j++;
                /* eu acho que isso pode dar erro no futuro por causa que pra 2 pessoas iguais ele erra pros 2*/
            }
        }
    }
    return j;

}
Equipe** TabelaComPontos::getEquipesEmOrdem(){
    int k;
    for(int j=0; j<quantidadeDeEquipes; j++){
            k=0;
        for(int i=1; i<quantidadeDeEquipes;i++){
            if(pontuacao[k]<pontuacao[i]) k=i;
        }
        ordenado[j]=participantes[k];
        pontuacao[k]=-1;
        /*isso vai dar problema se ele quiser chamar alguma coisa que depende de participantes depois de chamar essa funcao*/
    }
    return ordenado;
}
void TabelaComPontos::imprimir(){
}
