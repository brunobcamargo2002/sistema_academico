//
// Created by bruno on 22/08/22.
//
#include "stdafx.h"
#include "Aluno.h"

Aluno::Aluno(int diaNa, int mesNa, int anoNa, const char *nome, int RegAc):Pessoa(diaNa, mesNa, anoNa, nome) {
    RA = RegAc;
    pUniv = NULL;
}
Aluno::Aluno(){
    RA = -1;
    pUniv = NULL;
}
Aluno::~Aluno(){

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



