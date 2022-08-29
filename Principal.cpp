//
// Created by bruno on 16/08/22.
//
#include "stdafx.h"
#include "Principal.h"


Principal::Principal():
Newton(4, 1, 1643, "Newton"),
Einstein(14, 3, 1879, "Einstein"),
Simao(3, 10, 1976, "Simão"),
Bruno(6, 2, 2002, "Bruno", 2319136),
Joao(5,12,2001,"Joao",321321),
Pedro(7,11,2003,"Pedro",4324324),
Renato(24,6,2000,"Renato",4324321),
Renato2(25,7,2001,"Renato", 432432),
Cambridge("Universidade de Cambridge"), Princeton("Universidade de Princeton"), UTFPR("UTFPR"),
FisicaCambridge("Dep. Fis. Cambridge"),
FisicaPrinceton("Dep Fis. Princeton"),
DAINF("DAINF"), DAELN("DAELN"), DAFIS("DAFIS"), DAQUI("DAQUI"),
fundProg("Fundamentos de Programação"), tecProg("Técnicas de programação"), estDados("Estrutura de dados")
{
    //Associando(embora seja uma agregação) as universidades com seus respectivos departamentos.
    Cambridge.setDepartamento(&FisicaCambridge);
    Princeton.setDepartamento(&FisicaPrinceton);
    UTFPR.setDepartamento(&DAINF);
    UTFPR.setDepartamento(&DAELN);
    UTFPR.setDepartamento(&DAFIS);
    UTFPR.setDepartamento(&DAQUI);

    //Associando os professores com suas respectivas universidades.
    Newton.setUnivAfiliada(&Cambridge);
    Einstein.setUnivAfiliada(&Princeton);
    Simao.setUnivAfiliada(&UTFPR);

    DAINF.setDisciplina(&fundProg);
    DAINF.setDisciplina(&tecProg);
    DAINF.setDisciplina(&estDados);
    fundProg.setDpto(&DAINF);
    tecProg.setDpto(&DAINF);
    estDados.setDpto(&DAINF);
    //Associando os alunos com suas respectivas universidades.
    Bruno.setUniv(&UTFPR);
    Joao.setUniv(&UTFPR);
    Pedro.setUniv(&UTFPR);
    Renato.setUniv(&UTFPR);
    Renato2.setUniv(&UTFPR);

    tecProg.setAluno(&Renato);
    tecProg.setAluno(&Joao);
    tecProg.setAluno(&Pedro);
    tecProg.setAluno(&Renato2);
    tecProg.setAluno(&Bruno);

    //Associando os professores com suas respectivas universidades.
    Newton.setDptoAfiliado(&FisicaCambridge);
    Einstein.setDptoAfiliado(&FisicaPrinceton);
    Simao.setDptoAfiliado(&DAINF);

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

    UTFPR.imprimeDepartamentos();

    //Calcula a idade das pessoas.
    Newton.calcIdade(diaAt, mesAt, anoAt);
    Einstein.calcIdade(diaAt, mesAt, anoAt);
    Simao.calcIdade(diaAt, mesAt, anoAt);
    Bruno.calcIdade(diaAt, mesAt, anoAt);

    //Imprime a universidade a qual o profesor trabalha e, também, o departamento.
    Newton.ondeTrabalho();
    Newton.ondeDepartamentoTrabalho();
    Einstein.ondeTrabalho();
    Einstein.ondeDepartamentoTrabalho();
    Simao.ondeTrabalho();
    Simao.ondeDepartamentoTrabalho();

    //Imprime a universidade a qual o aluno estuda.
    Bruno.OndeEstudo();

    //Imprime as disciplinas dos departamentos.
    DAINF.imprimeDisciplinas();

    //Remove os alunos de uma determina disciplina.

    //Imprime os alunos de uma determinada disciplina.
    tecProg.imprimeAlunos();



}
