#ifndef PERSISTENCIADECOMPETICAO_H
#define PERSISTENCIADECOMPETICAO_H
#include "Competicao.h"
#include"Equipe.h"
#include <fstream>
#include"Modalidade.h"
#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"

class PersistenciaDeCompeticao
{
    public:
        PersistenciaDeCompeticao();
        virtual ~PersistenciaDeCompeticao();
        Competicao* carregar(string arquivo);
        void salvar(string arquivo, Competicao *c);
    private:


};

#endif // PERSISTENCIADECOMPETICAO_H
