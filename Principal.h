//
// Created by bruno on 16/08/22.
//
#include "Pessoa.h"
#include "Professor.h"
#include "Aluno.h"
#include "Departamento.h"
#include "Disciplina.h"

#include "listaUniversidades.h"
#include "listaDepartamentos.h"
#include "listaDisciplinas.h"
#include"listaAlunos.h"
#ifndef SISTEMA_ACADEMICO_PRINCIPAL_H
#define SISTEMA_ACADEMICO_PRINCIPAL_H


class Principal {
private:
    int idContUnivs;
    int idContDptos;
    int idContDisciplinas;
    int idContProfessores;
    int idContAlunos;


    Professor Newton, Einstein, Simao;
    Universidade Cambridge, Princeton, UTFPR;
    Departamento DAINF, DAELN, DAFIS, DAQUI, FisicaCambridge, FisicaPrinceton;
    Disciplina fundProg, tecProg, estDados;
    Aluno Bruno, Joao, Pedro, Renato, Renato2;

    listaUniversidades LUniversidades;
    listaDepartamentos LDepartamentos;
    listaDisciplinas LDisciplinas;
    listaAlunos LAlunos;


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

    void Menu();

    void MenuCad();
    void CadUniversidade();
    void CadDepartamento();
    void CadDisciplina();
    void CadAluno();

    void MenuExec();

    void MenuGravar();
    void gravarTudo();
    void gravarUnivs();
    void gravarDptos();
    void gravarDisciplinas();
    void gravarAlunos();

    void MenuRecuperar();
    void RecuperarTudo();
    void RecuperarUnivs();
    void RecuperarDptos();
    void RecuperarDisciplinas();
    void RecuperarAlunos();



};


#endif //SISTEMA_ACADEMICO_PRINCIPAL_H
