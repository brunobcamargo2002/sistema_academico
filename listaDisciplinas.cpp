//
// Created by bruno on 05/09/22.
//

#include "listaDisciplinas.h"

listaDisciplinas::listaDisciplinas(const char* name, int maxDisc) {
    numDisciplinas = 0;
    maxDisciplinas = maxDisc;
    pPrimeiraDisciplina = NULL;
    pDisciplinaAtual = NULL;
    setNome(name);
}

listaDisciplinas::~listaDisciplinas() {
    elDisciplina *aux1, *aux2;

    aux1 = pPrimeiraDisciplina;
    while(aux1!=NULL)
    {
        aux2= aux1->pProxDisciplina;
        delete(aux1);
        aux1 = aux2;
    }
    pPrimeiraDisciplina = NULL;
    pDisciplinaAtual = NULL;
}

void listaDisciplinas::setDisciplina(Disciplina *disc) {
    if ((numDisciplinas < maxDisciplinas || maxDisciplinas== -1) && disc != NULL) {
        elDisciplina *aux = new elDisciplina;
        aux->setDisciplina(disc);
        if (pPrimeiraDisciplina == NULL) {
            pPrimeiraDisciplina = aux;
            pDisciplinaAtual = aux;
        } else {
            pDisciplinaAtual->pProxDisciplina = aux;
            aux->pAntDisciplina = pDisciplinaAtual;
            pDisciplinaAtual = aux;
        }
        numDisciplinas++;
    }
}

void listaDisciplinas::imprimeDisciplinas() {
    elDisciplina* aux;
    cout<<"Disciplinas do "<<nome<<':'<<endl;
    for(aux = pPrimeiraDisciplina ; aux!=NULL; aux = aux->pProxDisciplina)
        cout<<aux->getNome()<<endl;

}

void listaDisciplinas::setNome(const char *name) {
    strcpy(nome, name);
}
