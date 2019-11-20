#include "TabelaComPontos.h"

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade):Tabela(participantes, quantidade)
{
        pontuacao= new int[quantidade];
        pontuacaofinal = new int[quantidade];
        for(int i=0; i<quantidade; i++){
            pontuacao[i]=0;
        }
        ordenado= new Equipe*[quantidade];
        existeResultado=0;
}

TabelaComPontos::~TabelaComPontos(){}

int TabelaComPontos::getPontos(Equipe* participante){ //RETORNA A PONTUACAO DE UMA EQUIPE DE ACORDO COM SUA POSICAO NO EQUIPE** PARTICIPANTES DA CLASSE TABELACOMPONTOS
    for(int i=0; i<quantidadeDeEquipes; i++){
        if(participantes[i]==participante){
            return pontuacao[i];
        }
    }
    throw new invalid_argument("a equipe que voce esta tentando conseguir os pontos nao faz parte da tabela");
}
void TabelaComPontos::pontuar(Equipe* participante, int pontos){ //ADICIONA OS PONTOS CORRESPONDENTES A CADA EQUIPE CONFORME SUA POSICAO
        int pontuou=0;
        for(int i=0; i<quantidadeDeEquipes; i++){
            if(participantes[i]==participante){
                    pontuou=1;
                pontuacao[i]=pontuacao[i]+pontos;
            }
        }
        if(pontuou==0){
            throw new invalid_argument("A equipe que voce esta tetando pontuar nao faz parte");
        }
}
int TabelaComPontos::getPosicao(Equipe* participante){ //RETORNA A POSICAO DE UMA DADA EQUIPE
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
            }
        }
    }
    return j;

}
Equipe** TabelaComPontos::getEquipesEmOrdem(){ //RETORNA AS EQUIPES EM ORDEM DE PONTUACAO
    int k;
    int *pontuacaobackup;
    pontuacaobackup = new int[quantidadeDeEquipes];
        for(int i=0;i<quantidadeDeEquipes;i++){
        pontuacaobackup[i]=pontuacao[i];
    }
    for(int j=0; j<quantidadeDeEquipes; j++){
            k=0;
        for(int i=1; i<quantidadeDeEquipes;i++){
            if(pontuacao[k]<pontuacao[i]){
                    k=i;
            }
        }

        ordenado[j] = participantes[k];
        pontuacaofinal[j] = pontuacao[k];
        pontuacao[k] = -1;
    }

    existeResultado = 1;
    for(int i=0;i<quantidadeDeEquipes;i++){
    pontuacao[i] = pontuacaobackup[i];
    }

    return ordenado;
}
void TabelaComPontos::imprimir(){
      if(!existeResultado){//CASO NAO TENHA RESULTADO
        for(int i=0;i<quantidadeDeEquipes;i++){
            cout<<"\t"<<participantes[i]->getNome()<<endl;
        }
        }else{//CASO TENHA RESULTADO
            for(int i=0;i<quantidadeDeEquipes;i++){
        cout<<"\t"<<i<<"o "<<participantes[i]->getNome()<<" "<<pontuacaofinal[i]<<endl;
            }
        }
}
