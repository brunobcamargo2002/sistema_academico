//
// Created by bruno on 16/08/22.
//
#include "Pessoa.h"
#include "Professor.h"
#include "Aluno.h"
#include "Departamento.h"
#include "Disciplina.h"
#ifndef SISTEMA_ACADEMICO_PRINCIPAL_H
#define SISTEMA_ACADEMICO_PRINCIPAL_H


class Principal {
private:
    Professor Newton, Einstein, Simao;
    Universidade Cambridge, Princeton, UTFPR;
    Departamento DAINF, DAELN, DAFIS, DAQUI, FisicaCambridge, FisicaPrinceton;
    Disciplina fundProg, tecProg, estDados;
    Aluno Bruno, Joao, Pedro, Renato, Renato2;


    int diaAt;
    int mesAt;
    int anoAt;
public:
    Principal();
    ~Principal();
    void Executar();

    void inicializarUniversidade();
    void inicializarDepartamento();
    void inicializarDisciplina();
    void inicializarProfessor();
    void inicializarAluno();

    void execUniversidade();
    void execDepartamento();
    void execDisciplina();
    void execProfessor();
    void execAluno();

};


#endif //SISTEMA_ACADEMICO_PRINCIPAL_H
