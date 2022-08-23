//
// Created by bruno on 17/08/22.
//
#include "stdafx.h"
#include "Universidade.h"
#define MAX 50
Universidade::Universidade(char const * n) {
    setNome(n);
    countDpto = 0;
    for(int i=0 ; i<50 ; i++)
        pDptos[i]= NULL;
}

Universidade::~Universidade() {

}

void Universidade::setNome(char const *n) {
    strcpy(Nome, n);
}

char* Universidade::getNome() {
    return Nome;
}

void Universidade::setDepartamento(Departamento* departamento)
{
    countDpto;
    if(countDpto<MAX) {
        pDptos[countDpto] = departamento;
        countDpto++;
    }
}

void Universidade::imprimeDepartamentos() {
    cout<<"Departamentos da(o) "<<getNome()<<":"<<endl;
    for(int i=0; i<countDpto ; i++)
        cout<<pDptos[i]->getNome()<<endl;
}
