//
// Created by bruno on 17/08/22.
//

#ifndef SISTEMA_ACADEMICO_UNIVERSIDADE_H
#define SISTEMA_ACADEMICO_UNIVERSIDADE_H

#include "Departamento.h"


class Universidade {
private:
    char Nome[30];
    Departamento *pDptos[50];
    int countDpto;

    void setNome(char const * n);
public:
    void setDepartamento(Departamento* departamento);
    void imprimeDepartamentos();
    Universidade(char const * n ="");
    ~Universidade();
    char* getNome();


};




#endif //SISTEMA_ACADEMICO_UNIVERSIDADE_H
