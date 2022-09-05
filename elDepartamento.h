//
// Created by bruno on 05/09/22.
//

#ifndef SISTEMA_ACADEMICO_ELDEPARTAMENTO_H
#define SISTEMA_ACADEMICO_ELDEPARTAMENTO_H
#include "Departamento.h"
class elDepartamento {
private:
    Departamento* departamento;
public:
    elDepartamento* pAntDpto;
    elDepartamento* pProxDpto;
    elDepartamento();
    ~elDepartamento();
    void setDpto(Departamento* dpto);
    Departamento* getDpto();
    char* getNome();


};


#endif //SISTEMA_ACADEMICO_ELDEPARTAMENTO_H
