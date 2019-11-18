#include <iostream>
#include "Equipe.h"
#include "Modalidade.h"
#include "Competicao.h"
#include "Tabela.h"
#include "PersistenciaDeCompeticao.h"

using namespace std;

int main()
{
    string nomeDaEquipe, //GUARDA O NOME DAS EQUIPES PARA SALVAR NO VETOR
        nomeDaModalidade, //GUARDA O NOME DAS MODALIDADES
        nomeDaCompeticao, //GUARDA O NOME DA COMPETICAO
        nomeDoArquivo; //GUARDA O NOME DO ARQUIVO
    char resposta; //gGUARDA A RESPOSTA PARA PERGUNTAS (S/N) OU (S/M)
    int n, //QUANTIDADE DE EQUIPES
        m, //QUANTIDADE DE MODALIDADES
        posicaoDaEquipe;//GUARDA A POSICAO DA EQUIPE CONFORME A ORDEM DE ENTRADA PELO USUARIO

    Modalidade* modalidade;
    Modalidade** modalidades;
    Competicao* competicao;
    PersistenciaDeCompeticao* arquivo = new PersistenciaDeCompeticao();

    cout << "Deseja carregar uma competicao (s/n)?" << endl;
    cin >> resposta;

    if(resposta == 's') {
        cout << "Digite o nome do arquivo: " << endl;
        cin >> nomeDoArquivo;

        competicao = arquivo->carregar(nomeDoArquivo);

        CompeticaoSimples *carregadaSimples = dynamic_cast<CompeticaoSimples*>(competicao);

        if(carregadaSimples == nullptr) {
            CompeticaoMultimodalidades *carregadaMultimodalidades = dynamic_cast<CompeticaoMultimodalidades*>(competicao);
            carregadaMultimodalidades->imprimir();
        }

        carregadaSimples->imprimir();
    }
    if(resposta == 'n') {

        cout << "Informe a quantidade de equipes: " << endl;
        cin >> n;

        Equipe** equipes = new Equipe* [n]; //CRIA UM VETOR PARA GUARDAR OS NOMES DE CADA EQUIPE EM ORDEM DE ENTRADA

        for(int i = 0; i < n; i++){
            cout << "Informe o nome da equipe " << i + 1 << endl;
            cin >> nomeDaEquipe;

            equipes[i] = new Equipe (nomeDaEquipe);
        }

        cout << "Informe o nome da competicao: " << endl;
        cin >> nomeDaCompeticao;

        cout << "Competicao Simples(s) ou Multimodalidade(m)? " << endl;
        cin >> resposta;

            if(resposta == 's'){

                cout << "Informe o nome da modalidade: " << endl;
                cin >> nomeDaModalidade;

                modalidade = new Modalidade (nomeDaModalidade, equipes, n);

                CompeticaoSimples* compSimples = new CompeticaoSimples(nomeDaCompeticao, equipes, n, modalidade);

                cout << "Tem resultado (s/n)? " << endl;
                cin >> resposta;

                    if(resposta == 's') { //A MODALIDADE JA TEM RESULTADO

                        Equipe** equipesOrdenadas = new Equipe* [n];

                        for(int i = 0; i < n; i++){
                            cout << "Informe a equipe " << i + 1 << "a colocada: " << endl;
                            cin >> nomeDaEquipe;

                            for(int j = 0; j < n; j++){
                                if(equipes[j]->getNome() == nomeDaEquipe){
                                    equipesOrdenadas[i] = equipes[j];
                                }
                            }

                        }

                        modalidade->setResultado(equipesOrdenadas);

                        cout << "Deseja salvar a competicao (s/n)? " << endl;
                        cin >> resposta;

                        if(resposta == 's'){
                            cout << "Digite o nome do arquivo: " << endl;
                            cin >> nomeDoArquivo;

                            arquivo->salvar(nomeDoArquivo, compSimples);
                            compSimples->imprimir();
                        }
                        if(resposta == 'n'){
                            compSimples->imprimir();
                        }
                        delete equipesOrdenadas;
                    }
                    if(resposta == 'n') { //A MODALIDADE NAO TEM RESULTADO, AINDA

                        cout << "Deseja salvar a competicao (s/n)?" << endl;
                        cin >> resposta;

                        if(resposta == 's') {
                            cout << "Digite o nome do arquivo:" << endl;
                            cin >> nomeDoArquivo;

                            arquivo->salvar(nomeDoArquivo, competicao);
                            competicao->imprimir();
                        }
                        if(resposta == 'n') {
                            competicao->imprimir();
                        }
                    }
            }
            if(resposta == 'm'){ //COMPETICAO MULTIMODALIDADES
                cout << "Informe a quantidade de modalidades: " << endl;
                cin >> m;

                Modalidade** modalidades = new Modalidade* [m];
                CompeticaoMultimodalidades* compMultimodalidades = new CompeticaoMultimodalidades(nomeDaCompeticao, equipes, n);

                for(int i = 0; i < m; i++){
                    cout << "Informe o nome da modalidade " << i + 1 << endl;
                    cin >> nomeDaModalidade;

                    modalidades[i] = new Modalidade (nomeDaModalidade, equipes, n);

                    cout << "Tem resultado (s/n)? " << endl;
                    cin >> resposta;

                    if(resposta == 's') {//MODALIDADE TEM RESULTADO

                        Equipe** equipesOrdenadas = new Equipe* [n];

                        for(int i = 0; i < m; i++){
                            cout << "Informe a equipe " << i + 1 << "a colocada: " << endl;
                            cin >> posicaoDaEquipe;

                            equipesOrdenadas[i] = equipes[posicaoDaEquipe - 1];
                        }

                        modalidades[i]->setResultado(equipesOrdenadas);
                    }

                }

                cout << "Deseja salvar a competicao (s/n)? " << endl;
                cin >> resposta;

                if(resposta == 's') {

                    cout << "Digite o nome do arquivo: " << endl;
                    cin >> nomeDoArquivo;

                    arquivo->salvar(nomeDoArquivo, compMultimodalidades);
                    compMultimodalidades->imprimir();
                }
                if(resposta == 'n') {
                    compMultimodalidades->imprimir();
                }
            }
    }

    return 0;
}

