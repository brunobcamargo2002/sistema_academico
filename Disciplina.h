//
// Created by bruno on 27/08/22.
//

#ifndef SISTEMA_ACADEMICO_DISCIPLINA_H
#define SISTEMA_ACADEMICO_DISCIPLINA_H
#include "stdafx.h"
#include "Aluno.h"
#include "listaAlunos.h"
#include "Departamento.h"
class Disciplina {
private:
    char nome[150];
    Departamento* dptoFiliado;
    listaAlunos lista;


public:

    Disciplina(const char * codigo="");
    ~Disciplina();
    void setNome(const char * codigo);
    char* getNome();
    void setDpto(Departamento* dpto);
    void setAluno(Aluno *aluno);
    void removeAluno(Aluno *aluno);
    void imprimeAlunos();
    void setNota1(Aluno* aluno, float nota1);
    void setNota2(Aluno* aluno, float nota2);
    void addFalta(Aluno* aluno, int f);
    void imprimeMedias();


};


#endif //SISTEMA_ACADEMICO_DISCIPLINA_H
