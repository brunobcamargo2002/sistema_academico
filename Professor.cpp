//
// Created by bruno on 22/08/22.
//
#include "stdafx.h"
#include "Professor.h"


Professor::Professor(int identificador) : Pessoa(identificador) {
    pUnivAfiliada = NULL;
    pDptoAfiliado = NULL;
}

Professor::~Professor() {
    pUnivAfiliada = NULL;
    pDptoAfiliado = NULL;
}

void Professor::setUnivAfiliada(Universidade *Univ) {
    pUnivAfiliada = Univ;
}

void Professor::setDptoAfiliado(Departamento *dep) {
    pDptoAfiliado = dep;
}

void Professor::ondeTrabalho() {
    if(pUnivAfiliada!=NULL)
        cout<<"O "<<nomeP<<" trabalha na "<<pUnivAfiliada->getNome()<<"."<<endl;

}

void Professor::ondeDepartamentoTrabalho() {
    if(pDptoAfiliado!=NULL)
        cout<<"O "<<getNome()<<" trabalha no "<<pDptoAfiliado->getNome()<<"."<<endl;
}




