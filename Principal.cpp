//
// Created by bruno on 16/08/22.
//
#include "stdafx.h"
#include "Principal.h"


Principal::Principal()
{

    inicializarUniversidade();
    inicializarDepartamento();
    inicializarProfessor();
    inicializarAluno();
    inicializarDisciplina();

    struct tm *local;
    time_t segundos;
    time(&segundos);
    local = localtime(&segundos);

    diaAt = local->tm_mday;
    mesAt = local->tm_mon+1;
    anoAt = local->tm_year+1900;
}
Principal::~Principal() {

}
void Principal::Executar(){

    execUniversidade();
    execDepartamento();
    execProfessor();
    execAluno();
    execDisciplina();

}

void Principal::inicializarUniversidade() {

    Cambridge.setNome("Universidade de Cambridge");
    Princeton.setNome("Universidade de Princeton");
    UTFPR.setNome("UTFPR");

    //Associando(embora seja uma agregação) as universidades com seus respectivos departamentos.
    Cambridge.setDepartamento(&FisicaCambridge);
    Princeton.setDepartamento(&FisicaPrinceton);
    UTFPR.setDepartamento(&DAINF);
    UTFPR.setDepartamento(&DAELN);
    UTFPR.setDepartamento(&DAFIS);
    UTFPR.setDepartamento(&DAQUI);

}

void Principal::inicializarDepartamento() {
    DAINF.setNome("DAINF");
    DAELN.setNome("DAELN");
    DAFIS.setNome("DAFIS");
    DAQUI.setNome("DAQUI");
    FisicaCambridge.setNome("Dep. Fis. Cambridge");
    FisicaPrinceton.setNome("Dep Fis. Princeton");

    DAINF.setDisciplina(&fundProg);
    DAINF.setDisciplina(&tecProg);
    DAINF.setDisciplina(&estDados);


    DAINF.setUniv(&UTFPR);
    DAELN.setUniv(&UTFPR);
    DAFIS.setUniv(&UTFPR);
    DAQUI.setUniv(&UTFPR);
    FisicaCambridge.setUniv(&Cambridge);
    FisicaPrinceton.setUniv(&Princeton);
}

void Principal::inicializarDisciplina() {
    fundProg.setNome("Fundamentos de Programação");
    tecProg.setNome("Técnicas de programação");
    estDados.setNome("Estrutura de dados");

    fundProg.setDpto(&DAINF);
    tecProg.setDpto(&DAINF);
    estDados.setDpto(&DAINF);

    tecProg.setAluno(&Renato2);
    tecProg.setAluno(&Joao);
    tecProg.setAluno(&Pedro);
    tecProg.setAluno(&Renato);
    tecProg.setAluno(&Bruno);

    estDados.setAluno(&Pedro);
    estDados.setAluno(&Joao);

}

void Principal::inicializarProfessor() {
    Newton.Inicializa(4, 1, 1643, "Newton");
    Einstein.Inicializa(14, 3, 1879, "Einstein");
    Simao.Inicializa(3, 10, 1976, "Simão");

    Newton.setUnivAfiliada(&Cambridge);
    Einstein.setUnivAfiliada(&Princeton);
    Simao.setUnivAfiliada(&UTFPR);

    Newton.setDptoAfiliado(&FisicaCambridge);
    Einstein.setDptoAfiliado(&FisicaPrinceton);
    Simao.setDptoAfiliado(&DAINF);

}

void Principal::inicializarAluno() {
    Bruno.Inicializa(6, 2, 2002, "Bruno");
    Joao.Inicializa(5,12,2001,"Joao");
    Pedro.Inicializa(7,11,2003,"Pedro");
    Renato.Inicializa(24,6,2000,"Renato");
    Renato2.Inicializa(25,7,2001,"Renato");

    Bruno.setRA(2319136);
    Joao.setRA(34234);
    Pedro.setRA(4234324);
    Renato.setRA(65654);
    Renato2.setRA(546547);

    Bruno.setUniv(&UTFPR);
    Joao.setUniv(&UTFPR);
    Pedro.setUniv(&UTFPR);
    Renato.setUniv(&UTFPR);
    Renato2.setUniv(&UTFPR);
}

void Principal::execUniversidade() {
    UTFPR.imprimeDepartamentos();
}

void Principal::execDepartamento() {
    DAINF.imprimeDisciplinas();
}

void Principal::execDisciplina() {
    tecProg.removeAluno(&Renato);
    tecProg.imprimeAlunos();
    estDados.imprimeAlunos();
    tecProg.setNota1(&Bruno, 9.5);
    tecProg.setNota1(&Pedro, 8);
    tecProg.setNota2(&Bruno, 9.8);
    tecProg.setNota2(&Pedro, 7);
    tecProg.imprimeMedias();

}


void Principal::execProfessor() {
    Newton.calcIdade(diaAt, mesAt, anoAt);
    Einstein.calcIdade(diaAt, mesAt, anoAt);
    Simao.calcIdade(diaAt, mesAt, anoAt);

    Newton.ondeTrabalho();
    Newton.ondeDepartamentoTrabalho();
    Einstein.ondeTrabalho();
    Einstein.ondeDepartamentoTrabalho();
    Simao.ondeTrabalho();
    Simao.ondeDepartamentoTrabalho();

}

void Principal::execAluno() {
    Bruno.calcIdade(diaAt, mesAt, anoAt);
    Bruno.OndeEstudo();

}
