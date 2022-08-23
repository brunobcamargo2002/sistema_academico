//
// Created by bruno on 22/08/22.
//

#ifndef SISTEMA_ACADEMICO_ALUNO_H
#define SISTEMA_ACADEMICO_ALUNO_H

#include "Pessoa.h"
#include "Universidade.h"
class Aluno: public Pessoa {
private:
    int RA;
    Universidade* pUniv;
public:
    Aluno(int diaNa, int mesNa, int anoNa, char const * nome, int RegAc);
    Aluno();
    ~Aluno();
    void setUniv(Universidade* Universidade);
    void OndeEstudo();
    int getRA();


};


#endif //SISTEMA_ACADEMICO_ALUNO_H