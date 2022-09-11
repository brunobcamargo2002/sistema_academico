//
// Created by bruno on 07/09/22.
//

#ifndef SISTEMA_ACADEMICO_LISTAUNIVERSIDADES_H
#define SISTEMA_ACADEMICO_LISTAUNIVERSIDADES_H

#include "elUniversidade.h"
class listaUniversidades {
private:

    int numUniv, maxUniv;
public:
    elUniversidade* pPrimeiraUniv;
    elUniversidade* pUnivAtual;
    listaUniversidades(int nu = 100);
    ~listaUniversidades();
    void incluaUniv(Universidade* universidade);
    void listeUnivs();
    Universidade* localizar(const char * nome);
    Universidade* localizarID(int id);



};


#endif //SISTEMA_ACADEMICO_LISTAUNIVERSIDADES_H
