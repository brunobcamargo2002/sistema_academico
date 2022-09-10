//
// Created by bruno on 15/08/22.
//
#include "stdafx.h"
#include "Pessoa.h"

Pessoa::Pessoa(int identificador) {
    id = identificador;
}

Pessoa::~Pessoa(){

}
void Pessoa::Inicializa(int diaNa, int mesNa, int anoNa, char const * nome){
    diaP = diaNa;
    mesP = mesNa;
    anoP = anoNa;
    strcpy(nomeP, nome);
    idadeP = 0;
}
void Pessoa::calcIdade(int diaAt, int mesAt, int anoAt) {
    idadeP = anoAt-anoP;
    if(mesP>mesAt)
        idadeP = idadeP-1;
    else if(mesAt == mesP)
    {
        if(diaP>diaAt)
            idadeP = idadeP-1;
    }
    printIdade();
}
int Pessoa::getIdade() {
    return idadeP;
}
char* Pessoa::getNome(){
    return nomeP;
}
void Pessoa::printIdade(){
    cout<<"O "<<getNome()<<" tem "<<getIdade()<<" anos."<<endl;
}

void Pessoa::setNome(const char *name) {
    strcpy(nomeP, name);
}

int Pessoa::getId() {
    return id;
}



