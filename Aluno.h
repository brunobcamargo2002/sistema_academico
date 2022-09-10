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
    Aluno(int identificador);
    Aluno();
    ~Aluno();
    void setRA(int RegAc);
    int getRA();
    void setUniv(Universidade* Universidade);
    void OndeEstudo();



};


#endif //SISTEMA_ACADEMICO_ALUNO_H
