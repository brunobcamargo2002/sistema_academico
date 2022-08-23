//
// Created by bruno on 17/08/22.
//

#ifndef SISTEMA_ACADEMICO_DEPARTAMENTO_H
#define SISTEMA_ACADEMICO_DEPARTAMENTO_H

class Universidade;
class Departamento {
private:
    char nome[30];
    Universidade* pUniv;


public:
    void setNome(char const *n);
    Departamento(char const *n="");
    ~Departamento();
    char* getNome();
    void setUniv(Universidade* universidade);

};


#endif //SISTEMA_ACADEMICO_DEPARTAMENTO_H
