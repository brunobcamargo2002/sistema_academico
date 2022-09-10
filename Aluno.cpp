//
// Created by bruno on 22/08/22.
//
#include "stdafx.h"
#include "Aluno.h"

Aluno::Aluno(int identificador):Pessoa(identificador) {
    RA = 0;
    pUniv = NULL;
}
Aluno::Aluno(){
    RA = -1;
    pUniv = NULL;
}
Aluno::~Aluno(){

}

void Aluno::setRA(int RegAc)
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



