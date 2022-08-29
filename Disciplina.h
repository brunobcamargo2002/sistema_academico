//
// Created by bruno on 27/08/22.
//

#ifndef SISTEMA_ACADEMICO_DISCIPLINA_H
#define SISTEMA_ACADEMICO_DISCIPLINA_H
#include "Aluno.h"
#include "Departamento.h"
class Disciplina {
private:
    char nome[150];
    Departamento* dptoFiliado;
    int maxAlunos;
    int numAlunos;
    Aluno* pPrimeiroAluno;
    Aluno* pAlunoAtual;



public:
    Disciplina *antDisciplina, *proxDisciplina;
    Disciplina(const char * codigo="");
    ~Disciplina();
    void setNome(const char * codigo);
    char* getNome();
    void setDpto(Departamento* dpto);
    void setAluno(Aluno *aluno);
    void removeAluno(Aluno *aluno);
    void imprimeAlunos();





};


#endif //SISTEMA_ACADEMICO_DISCIPLINA_H
