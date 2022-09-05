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
    char nome[30];
    Universidade* pUniv;
    listaDisciplinas* lista;

public:
    Departamento(char const *n="");
    ~Departamento();
    void setNome(char const *n);
    char* getNome();
    void setUniv(Universidade* universidade);
    void setDisciplina(Disciplina * disc);
    void imprimeDisciplinas();

};


#endif //SISTEMA_ACADEMICO_DEPARTAMENTO_H
