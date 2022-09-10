//
// Created by bruno on 05/09/22.
//

#include "listaDepartamentos.h"
#include "stdafx.h"
listaDepartamentos::listaDepartamentos(const char *name, int maxDep) {
    numDptos = 0;
    maxDptos = maxDep;
    setNome(name);
    pPrimeiroDpto = NULL;
    pDptoAtual = NULL;

}

listaDepartamentos::~listaDepartamentos() {
    elDepartamento * aux1, *aux2;

    aux1 = pPrimeiroDpto;
    while(aux1!=NULL)
    {
        aux2 = aux1->pProxDpto;
        delete(aux1);
        aux1 = aux2;
    }
    pPrimeiroDpto = NULL;
    pDptoAtual = NULL;
}

void listaDepartamentos::setDpto(Departamento *dpto) {
    if((numDptos<maxDptos || maxDptos==-1)&& dpto!=NULL)
    {
        elDepartamento *aux = new elDepartamento;
        aux->setDpto(dpto);
        if(pPrimeiroDpto==NULL)
        {
            pPrimeiroDpto = aux;
            pDptoAtual = aux;
        }
        else
        {
            aux->pAntDpto = pDptoAtual;
            pDptoAtual->pProxDpto = aux;
            pDptoAtual = aux;
        }
        numDptos++;
    }

}

void listaDepartamentos::imprimeDptos() {
    elDepartamento* aux;
    cout<<"Departamentos da "<<nome<<":"<<endl;
    for(aux = pPrimeiroDpto; aux!=NULL; aux= aux->pProxDpto)
    {
        cout<<aux->getNome()<<endl;
    }

}

void listaDepartamentos::setNome(const char* n) {
    strcpy(nome, n);
}

Departamento *listaDepartamentos::localizar(const char *nome) {
    elDepartamento* aux=pPrimeiroDpto;

    while(aux!=NULL){
        if(!strcmp(aux->getNome(), nome))
            return aux->getDpto();
        aux = aux->pProxDpto;
    }
    return NULL;
}


