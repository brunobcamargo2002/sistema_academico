//
// Created by bruno on 07/09/22.
//

#include "listaUniversidades.h"

listaUniversidades::listaUniversidades(int nu) {
    numUniv = 0;
    maxUniv = nu;
    pPrimeiraUniv = NULL;
    pUnivAtual = NULL;
}

listaUniversidades::~listaUniversidades() {
    elUniversidade* aux1 = pPrimeiraUniv, *aux2;

    while(aux1!=NULL){
        aux2 = aux1->pProxUniv;
        delete(aux1);
        aux1 = aux2;
    }
    pPrimeiraUniv = NULL;
    pUnivAtual = NULL;
}

void listaUniversidades::incluaUniv(Universidade *universidade) {
    if(universidade!=NULL) {
        elUniversidade *aux = new elUniversidade;
        aux->setUniv(universidade);
        if(pPrimeiraUniv==NULL){
            pPrimeiraUniv = aux;
            pUnivAtual = aux;
        }
        else{
            aux->pAntUniv = pUnivAtual;
            pUnivAtual->pProxUniv = aux;
            pUnivAtual = aux;
        }
        numUniv++;
    }

}

void listaUniversidades::listeUnivs() {
    elUniversidade *aux = pPrimeiraUniv;
    cout<<"Lista de universidades: "<<endl;
    while(aux!=NULL){
        cout<<aux->getNome()<<endl;
        aux = aux->pProxUniv;
    }

}

Universidade* listaUniversidades::localizar(const char *nome) {
    elUniversidade* aux=pPrimeiraUniv;

    while(aux!=NULL){
        if(!strcmp(aux->getNome(), nome))
            return aux->getUniv();
        aux = aux->pProxUniv;
    }
    return NULL;
}

