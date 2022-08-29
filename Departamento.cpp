//
// Created by bruno on 17/08/22.
//
#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"
#include "Disciplina.h"

Departamento::Departamento(char const *n) {
    setNome(n);
    pPrimeiraDisciplina=NULL;
    pDisciplinaAtual=NULL;
}

Departamento::~Departamento() {

}

void Departamento::setNome(const char *n) {
    strcpy(nome, n);
}

char *Departamento::getNome() {
    return nome;
}

void Departamento::setUniv(Universidade *universidade) {
    pUniv = universidade;
}

void Departamento::setDisciplina(Disciplina *disc) {
    if(pPrimeiraDisciplina == NULL) {
        pPrimeiraDisciplina = disc;
        pDisciplinaAtual = disc;
    }
    else
    {
        pDisciplinaAtual->proxDisciplina = disc;
        disc->antDisciplina = pDisciplinaAtual;
        pDisciplinaAtual = disc;
    }
}

void Departamento::imprimeDisciplinas() {
    Disciplina* aux;
    cout<<"Disciplinas do "<<getNome()<<':'<<endl;
    for(aux = pPrimeiraDisciplina ; aux!=NULL; aux = aux->proxDisciplina)
        cout<<aux->getNome()<<endl;

}
