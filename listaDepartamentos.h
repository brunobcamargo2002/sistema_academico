//
// Created by bruno on 05/09/22.
//

#ifndef SISTEMA_ACADEMICO_LISTADEPARTAMENTOS_H
#define SISTEMA_ACADEMICO_LISTADEPARTAMENTOS_H

#include "elDepartamento.h"

class listaDepartamentos {
private:
    int numDptos, maxDptos;

    char nome[30];
public:
    elDepartamento* pPrimeiroDpto;
    elDepartamento* pDptoAtual;
    listaDepartamentos(const char *name="",int maxDep = 50);
    ~listaDepartamentos();
    void setDpto(Departamento* dpto);
    void imprimeDptos();
    void setNome(const char* n);
    Departamento* localizar(const char * nome);
    Departamento* localizarID(int id);



};


#endif //SISTEMA_ACADEMICO_LISTADEPARTAMENTOS_H
