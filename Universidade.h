//
// Created by bruno on 17/08/22.
//

#ifndef SISTEMA_ACADEMICO_UNIVERSIDADE_H
#define SISTEMA_ACADEMICO_UNIVERSIDADE_H

using namespace std;
#include "stdafx.h"
#include "listaDepartamentos.h"


class Universidade {
private:
    int id;
    char Nome[150];


public:
    listaDepartamentos lista;
    void setNome(char const * n);
    void setDepartamento(Departamento* departamento);
    void imprimeDepartamentos();
    Universidade(int id=-1);
    ~Universidade();
    char* getNome();
    int getId();


};




#endif //SISTEMA_ACADEMICO_UNIVERSIDADE_H
