//
// Created by bruno on 22/08/22.
//

#ifndef SISTEMA_ACADEMICO_PROFESSOR_H
#define SISTEMA_ACADEMICO_PROFESSOR_H

#include "Pessoa.h"
class Professor : public Pessoa{
private:
    Universidade *pUnivAfiliada;
    Departamento *pDptoAfiliado;
public:
    Professor(int diaNa, int mesNa, int anoNa, char const * nome);
    Professor();
    ~Professor();
    void setUnivAfiliada(Universidade* Univ);
    void setDptoAfiliado(Departamento* dep);
    void ondeTrabalho();
    void ondeDepartamentoTrabalho();

};


#endif //SISTEMA_ACADEMICO_PROFESSOR_H
