//
// Created by bruno on 17/08/22.
//

#ifndef SISTEMA_ACADEMICO_UNIVERSIDADE_H
#define SISTEMA_ACADEMICO_UNIVERSIDADE_H

#include <list>
using namespace std;
#include "stdafx.h"
#include "Departamento.h"


class Universidade {
private:
    char Nome[30];
    list<Departamento*> pDptos;

public:
    void setNome(char const * n);
    void setDepartamento(Departamento* departamento);
    void imprimeDepartamentos();
    Universidade(char const * n ="");
    ~Universidade();
    char* getNome();


};




#endif //SISTEMA_ACADEMICO_UNIVERSIDADE_H
