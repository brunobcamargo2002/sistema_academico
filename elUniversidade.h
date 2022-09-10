//
// Created by bruno on 07/09/22.
//

#ifndef SISTEMA_ACADEMICO_ELUNIVERSIDADE_H
#define SISTEMA_ACADEMICO_ELUNIVERSIDADE_H

#include "Universidade.h"
class elUniversidade {
private:
    Universidade* universidade;
public:
    elUniversidade* pAntUniv, *pProxUniv;
    elUniversidade();
    ~elUniversidade();
    void setUniv(Universidade* univ);
    Universidade* getUniv();
    char* getNome();


};


#endif //SISTEMA_ACADEMICO_ELUNIVERSIDADE_H
