//
// Created by bruno on 05/09/22.
//

#ifndef SISTEMA_ACADEMICO_LISTADISCIPLINAS_H
#define SISTEMA_ACADEMICO_LISTADISCIPLINAS_H
#include "stdafx.h"
#include "elDisciplina.h"
class listaDisciplinas {
private:
    int numDisciplinas, maxDisciplinas;
    char nome[150];

public:
    elDisciplina* pPrimeiraDisciplina;
    elDisciplina* pDisciplinaAtual;
    listaDisciplinas(const char* name = "", int maxDisc= 1000);
    ~listaDisciplinas();
    void setDisciplina(Disciplina * disc);
    void imprimeDisciplinas();
    void setNome(const char* name);


};


#endif //SISTEMA_ACADEMICO_LISTADISCIPLINAS_H
