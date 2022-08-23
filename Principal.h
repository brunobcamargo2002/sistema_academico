//
// Created by bruno on 16/08/22.
//
#include "Pessoa.h"
#include "Professor.h"
#include "Aluno.h"
#include "Departamento.h"
#ifndef SISTEMA_ACADEMICO_PRINCIPAL_H
#define SISTEMA_ACADEMICO_PRINCIPAL_H


class Principal {
private:
    Professor Newton, Einstein, Simao;
    Universidade Cambridge, Princeton, UTFPR;
    Departamento DAINF, DAELN, DAFIS, DAQUI, FisicaCambridge, FisicaPrinceton;
    Aluno Bruno;

    int diaAt;
    int mesAt;
    int anoAt;
public:
    Principal();
    ~Principal();
    void Executar();
};


#endif //SISTEMA_ACADEMICO_PRINCIPAL_H
