//
// Created by bruno on 15/08/22.
//

#ifndef SISTEMA_ACADEMICO_PESSOA_H
#define SISTEMA_ACADEMICO_PESSOA_H
#include "Departamento.h"
#include "Universidade.h"
class Pessoa {
protected:
    int diaP;
    int mesP;
    int anoP;
    int idadeP;
    char nomeP[30];


public:
    Pessoa(int diaNa, int mesNa, int anoNa, char const * nome);
    Pessoa();
    ~Pessoa();
    void Inicializa(int diaNa, int mesNa, int anoNa, char const * nome="");
    int getIdade();
    void printIdade();
    char* getNome();
    void calcIdade(int diaAt, int mesAt, int anoAt);

//int getIdade();
//char* getNome();

};


#endif //SISTEMA_ACADEMICO_PESSOA_H
