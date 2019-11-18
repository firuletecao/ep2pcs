#include "PersistenciaDeCompeticao.h"
#include "Equipe.h"
#include "Competicao.h"
#include "Modalidade.h"


using namespace std;


PersistenciaDeCompeticao::PersistenciaDeCompeticao()
{}

PersistenciaDeCompeticao::~PersistenciaDeCompeticao()
{}

Competicao* PersistenciaDeCompeticao::carregar(string arquivo){
    ifstream input;
    input.open(arquivo);
    if (input.fail()){
        throw new invalid_argument("erro");
    }

    int quantidadeEquipesCompeticao, x, numeroDeModalidades, existeResultado, quantidadeEquipesModalidade, quantidadeDeParticipantes;
    string nomeDaEquipe, nomeDaCompeticao, nomeDaModalidade, nome1;
    Equipe **equipesDaCompeticao;
    Equipe **equipesDaModalidade;
    Equipe **ordem;
    Modalidade *m;
    CompeticaoSimples *c1;

    input >> quantidadeEquipesCompeticao;

    equipesDaCompeticao = new Equipe*[quantidadeEquipesCompeticao];

    for (int i = 0; i < quantidadeEquipesCompeticao; i++) {
        input >> nomeDaEquipe;
        equipesDaCompeticao[i] = new Equipe(nomeDaEquipe);
    }

    input >> nomeDaCompeticao;
    input >> x;

    if(x == 0){
        input >> nomeDaModalidade; //nome da modalidade
        input >> existeResultado; // 0 se modalidade nao tem resultado
        if(existeResultado != 0){
            input >> quantidadeDeParticipantes; //quantidade de participantes
            ordem = new Equipe*[quantidadeDeParticipantes];
            for(int i=0;i<quantidadeDeParticipantes;i++){
                    input >> nomeDaEquipe;
                    for(int j=0; j<quantidadeEquipesCompeticao;j++ ){
                            if(equipesDaCompeticao[j]->getNome()==nomeDaEquipe)ordem[i]=equipesDaCompeticao[j];
                    }
            }
            m = new Modalidade(nomeDaModalidade, ordem,quantidadeDeParticipantes );
            m->setResultado(ordem);
            c1 = new CompeticaoSimples(nomeDaCompeticao, equipesDaCompeticao, quantidadeEquipesCompeticao, m);

            return c1;
        }else{
            input >> quantidadeDeParticipantes;
            ordem = new Equipe*[quantidadeDeParticipantes];
            for(int i=0;i<quantidadeDeParticipantes;i++){
                input >> nomeDaEquipe;
                for(int j=0;i<quantidadeEquipesCompeticao;j++){
                    if(equipesDaCompeticao[j]->getNome()==nomeDaEquipe)ordem[i]=equipesDaCompeticao[j];
                }
            }
            m= new Modalidade(nomeDaModalidade, ordem, quantidadeDeParticipantes);
            c1 = new CompeticaoSimples(nomeDaCompeticao, equipesDaCompeticao, quantidadeEquipesCompeticao, m);

            return c1;
        }
    }else{

        CompeticaoMultimodalidades *c = new CompeticaoMultimodalidades(nomeDaCompeticao, equipesDaCompeticao, quantidadeEquipesCompeticao);
        input >> numeroDeModalidades;

        for (int i = 0; i < numeroDeModalidades; i++){
            input >> nomeDaModalidade;
            input >> existeResultado;
            input >> quantidadeEquipesModalidade;

            equipesDaModalidade = new Equipe*[quantidadeEquipesModalidade];

            for (int j = 0; j < quantidadeEquipesModalidade; j++) {
                input >> nome1;

                for (int k = 0; k < quantidadeEquipesModalidade; k++){
                    if (nome1 == equipesDaCompeticao[k]->getNome()){
                        equipesDaModalidade[j] = equipesDaCompeticao[k];
                    }
                }

            }

            Modalidade *m = new Modalidade(nomeDaModalidade, equipesDaModalidade, quantidadeEquipesModalidade);

            if (existeResultado!=0) {
                m->setResultado(equipesDaModalidade);
            }
            c->adicionar(m);
    }
    return c;
}
}

void PersistenciaDeCompeticao::salvar(string arquivo, Competicao *c){
    CompeticaoMultimodalidades* competicaoMultiModalidades= dynamic_cast<CompeticaoMultimodalidades*>(c);

    if (competicaoMultiModalidades!=nullptr) {
        ofstream output;
        output.open(arquivo);

        if (output.fail()){
            throw new invalid_argument("erro");
        }

        int quantidadeDeEquipes = competicaoMultiModalidades->getQuantidadeDeEquipes();

        output << quantidadeDeEquipes;
        output << "\n";

        Equipe **participantes = competicaoMultiModalidades->getEquipes();

        for (int i = 0; i < quantidadeDeEquipes; i++){
            output << participantes[i]->getNome();
            output << "\n";
        }
        output << competicaoMultiModalidades->getNome();
        output << "\n";
        output << 1;
        output << "\n";

        list<Modalidade*>* m = competicaoMultiModalidades->getModalidades();
        int quantidadeDeModalidades, existeResultado;

        quantidadeDeModalidades = m->size();
        output << quantidadeDeModalidades << "\n";

        list<Modalidade*>::iterator i = m->begin();

        while(i != m->end()){
            Modalidade *m1 = (*i);
            existeResultado = m1->temResultado();
            output << m1->getNome() << "\n";

            if (existeResultado) {
                output << 1 << " ";
                output << m1->getQuantidadeDeEquipes() << " ";

                participantes = m1->getTabela()->getEquipesEmOrdem();
                for (int i = 0; i < m1->getQuantidadeDeEquipes(); i++) {
                    output << participantes[i]->getNome() << " ";
                }

                output << "\n";
            }else{
                output << 0 << " ";
                output << m1->getQuantidadeDeEquipes() << " ";

                participantes = m1->getEquipes();
                for (int i = 0; i < m1->getQuantidadeDeEquipes(); i++) {
                    output << participantes[i]->getNome() << " ";
                }

                output << "\n";
            }

            i++;
        }

        output.close();
    }else {
        CompeticaoSimples* competicaoSimples = dynamic_cast<CompeticaoSimples*>(c);

        ofstream output;
        output.open(arquivo);

        if (output.fail()){
            throw new invalid_argument ("erro");
        }

        output << competicaoSimples->getQuantidadeDeEquipes() << "\n";

        Equipe **equipes = competicaoSimples->getEquipes();

        for (int i = 0; i < competicaoSimples->getQuantidadeDeEquipes(); i++){
            output << equipes[i]->getNome() << "\n";
        }

        output << "\n";

        output << competicaoSimples->getNome() << "\n";
        output << 0 << "\n";

        Modalidade *m2 = competicaoSimples->getModalidade();
        output << m2->getNome() << "\n";

        int quantidadeDeEquipes;
        quantidadeDeEquipes = m2->getQuantidadeDeEquipes();
        if (m2->temResultado()){
                output << 1 << " ";
                output << quantidadeDeEquipes << " ";

                equipes = m2->getTabela()->getEquipesEmOrdem();
                for (int i = 0; i < quantidadeDeEquipes; i++){
                    output << equipes[i]->getNome() << " ";
                }
        }else{
                output << 0 << " ";
                output << quantidadeDeEquipes << " ";

                equipes = m2->getEquipes();

                for (int i = 0; i < quantidadeDeEquipes; i++){
                    output << equipes[i]->getNome() << " ";
                }
        }

        output.close();
    }

}
