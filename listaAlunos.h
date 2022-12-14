//
// Created by bruno on 05/09/22.
//

#ifndef SISTEMA_ACADEMICO_LISTAALUNOS_H
#define SISTEMA_ACADEMICO_LISTAALUNOS_H
#include "elAluno.h"
#include "stdafx.h"

class listaAlunos {
private:
    int maxAlunos;
    int numAlunos;
    char nome[150];

public:
    elAluno* pPrimeiroAluno;
    elAluno* pAlunoAtual;
    listaAlunos(int na =45, const char* name="");
    ~listaAlunos();
    void setAluno(Aluno *aluno);
    void removeAluno(Aluno *aluno);
    void imprimeAlunos();
    void setNota1(Aluno* aluno, float nota1);
    void setNota2(Aluno* aluno, float nota2);
    void addFalta(Aluno* aluno, int f);
    void imprimeMedias();
    void setNome(const char * name);
    Aluno* localizarID(int id);


};


#endif //SISTEMA_ACADEMICO_LISTAALUNOS_H
