//
// Created by bruno on 15/08/22.
//

#ifndef SISTEMA_ACADEMICO_PESSOA_H
#define SISTEMA_ACADEMICO_PESSOA_H
#include "Departamento.h"
#include "Universidade.h"
class Pessoa {
protected:
    int id;
    int diaP;
    int mesP;
    int anoP;
    int idadeP;
    char nomeP[30];


public:
    Pessoa(int identificador=-1);
    ~Pessoa();
    void Inicializa(int diaNa, int mesNa, int anoNa, char const * nome="");
    int getIdade();
    void printIdade();
    void setNome(const char * name);
    char* getNome();
    void calcIdade(int diaAt, int mesAt, int anoAt);
    int getId();

//int getIdade();
//char* getNome();

};


#endif //SISTEMA_ACADEMICO_PESSOA_H
