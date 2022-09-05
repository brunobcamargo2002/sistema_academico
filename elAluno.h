//
// Created by bruno on 30/08/22.
//

#ifndef SISTEMA_ACADEMICO_ELALUNO_H
#define SISTEMA_ACADEMICO_ELALUNO_H

#include "Aluno.h"
class elAluno {
private:
    Aluno* aluno;
    float nota1, nota2,media;
    int faltas;



public:
    elAluno *pAntAluno, *pProxAluno;
    elAluno();
    ~elAluno();
    void setAluno(Aluno* pa);
    Aluno* getAluno();
    char* getNome();
    void setNota1(float n1);
    void setNota2(float n2);
    void calcMedia();
    void addFalta(int f);
    float getMedia();

};


#endif //SISTEMA_ACADEMICO_ELALUNO_H
