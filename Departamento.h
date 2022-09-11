//
// Created by bruno on 17/08/22.
//

#ifndef SISTEMA_ACADEMICO_DEPARTAMENTO_H
#define SISTEMA_ACADEMICO_DEPARTAMENTO_H
#include "stdafx.h"
#include "listaDisciplinas.h"
class Universidade;
class Departamento {
private:
    int id;
    char nome[30];
    Universidade* pUniv;


public:
    Departamento(int identificador=-1);
    ~Departamento();
    void setNome(char const *n);
    char* getNome();
    void setUniv(Universidade* universidade);
    int getUnivAssociada();
    void setDisciplina(Disciplina * disc);
    void imprimeDisciplinas();
    int getId();

    listaDisciplinas lista;
};


#endif //SISTEMA_ACADEMICO_DEPARTAMENTO_H
