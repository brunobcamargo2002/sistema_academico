//
// Created by bruno on 22/08/22.
//
#include "stdafx.h"
#include "Aluno.h"

Aluno::Aluno(int diaNa, int mesNa, int anoNa, const char *nome, int RegAc=-1):Pessoa(diaNa, mesNa, anoNa, nome) {
    setRA(RA);
    pUniv = NULL;
    pAntAluno= NULL;
    pProxAluno= NULL;
}
Aluno::Aluno(){
    RA = -1;
    pUniv = NULL;
}
Aluno::~Aluno(){

}

int Aluno::setRA(int RegAc)
{
    RA = RegAc;
}


int Aluno::getRA() {
    return RA;
}

void Aluno::setUniv(Universidade *Universidade) {
    pUniv = Universidade;
}

void Aluno::OndeEstudo() {
    cout<<"O "<<getNome()<<" estuda na "<<pUniv->getNome()<<"."<<endl;
}



