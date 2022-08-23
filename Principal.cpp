//
// Created by bruno on 16/08/22.
//
#include "stdafx.h"
#include "Principal.h"


Principal::Principal():
Newton(4, 1, 1643, "Newton"),
Einstein(14, 3, 1879, "Einstein"),
Simao(3, 10, 1976, "Simão"),
Cambridge("Universidade de Cambridge"), Princeton("Universidade de Princeton"), UTFPR("UTFPR"),
FisicaCambridge("Dep. Fis. Cambridge"),
FisicaPrinceton("Dep Fis. Princeton"),
DAINF("DAINF"), DAELN("DAELN"), DAFIS("DAFIS"), DAQUI("DAQUI"),
Bruno(6, 2, 2002, "Bruno", 2319136)
{
    Cambridge.setDepartamento(&FisicaCambridge);
    Princeton.setDepartamento(&FisicaPrinceton);
    UTFPR.setDepartamento(&DAINF);
    UTFPR.setDepartamento(&DAELN);
    UTFPR.setDepartamento(&DAFIS);
    UTFPR.setDepartamento(&DAQUI);

    Newton.setUnivAfiliada(&Cambridge);
    Einstein.setUnivAfiliada(&Princeton);
    Simao.setUnivAfiliada(&UTFPR);

    Newton.setDptoAfiliado(&FisicaCambridge);
    Einstein.setDptoAfiliado(&FisicaPrinceton);
    Simao.setDptoAfiliado(&DAINF);

    Bruno.setUniv(&UTFPR);

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

    Newton.calcIdade(diaAt, mesAt, anoAt);
    Einstein.calcIdade(diaAt, mesAt, anoAt);
    Simao.calcIdade(diaAt, mesAt, anoAt);

    Bruno.calcIdade(diaAt, mesAt, anoAt);

    Newton.ondeTrabalho();
    Newton.ondeDepartamentoTrabalho();
    Einstein.ondeTrabalho();
    Einstein.ondeDepartamentoTrabalho();
    Simao.ondeTrabalho();
    Simao.ondeDepartamentoTrabalho();

    Bruno.OndeEstudo();

}
