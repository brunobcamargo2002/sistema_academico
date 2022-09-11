//
// Created by bruno on 05/09/22.
//

#include "listaAlunos.h"

#include <fstream>

listaAlunos::listaAlunos(int na, const char* name) {
    strcpy(nome, name);
    maxAlunos = na;
    numAlunos= 0;
    pPrimeiroAluno= NULL;
    pAlunoAtual= NULL;

}

listaAlunos::~listaAlunos() {
    elAluno *aux1, *aux2;

    aux1 = pPrimeiroAluno;
    while(aux1!=NULL)
    {
        aux2= aux1->pProxAluno;
        delete(aux1);
        aux1 = aux2;
    }
    pPrimeiroAluno = NULL;
    pAlunoAtual = NULL;

}

void listaAlunos::setAluno(Aluno *aluno) {
    elAluno* slave = new elAluno;
    slave->setAluno(aluno);
    if(pPrimeiroAluno==NULL) {
        pPrimeiroAluno = slave;
        pAlunoAtual = slave;
        numAlunos++;
    }
    else if(numAlunos<maxAlunos)
    {

        numAlunos++;
        elAluno *aux=pPrimeiroAluno;
        int flag = 1;
        int i=0;
        char* nome1 = slave->getNome();
        char* nome2;

        while(aux!=NULL && flag){
            nome2 = aux->getNome();
            i=0;
            while(nome1[i]==nome2[i] && nome1[i]!='\0' && nome2[i]!='\0') i++;
            if(nome1[i]<=nome2[i])
            {
                slave->pAntAluno = aux->pAntAluno;
                slave->pProxAluno = aux;
                aux->pAntAluno = slave;
                if(slave->pAntAluno!=NULL)
                    slave->pAntAluno->pProxAluno=slave;
                else
                    pPrimeiroAluno = slave;
                flag = 0;
            }
            else
            {
                aux = aux->pProxAluno;
            }
        }
        if(flag){
            pAlunoAtual->pProxAluno = slave;
            slave->pAntAluno = pAlunoAtual;
            slave->pProxAluno = NULL;
            pAlunoAtual = slave;
        }
    }
    else
        cout<<"A matricula do aluno "<<aluno->getNome()<<" não foi realizada, pois a turma está cheia."<<endl;

}

void listaAlunos::removeAluno(Aluno *aluno) {
    elAluno* aux;

    for(aux=pPrimeiroAluno; aux!=NULL; aux= aux->pProxAluno)
    {
        if(aux->getAluno()==aluno)
        {
            if(aux->pAntAluno==NULL)
                pPrimeiroAluno= aux->pProxAluno;
            if(aux->pProxAluno==NULL)
                pAlunoAtual = aux->pAntAluno;
            if(aux->pProxAluno!=NULL)
                aux->pProxAluno->pAntAluno=aux->pAntAluno;
            if(aux->pAntAluno!=NULL)
                aux->pAntAluno->pProxAluno=aux->pProxAluno;
            aux->pAntAluno= NULL;
            aux->pProxAluno= NULL;
            return;
        }

    }
}

void listaAlunos::imprimeAlunos() {
    elAluno *aux;
    cout<<"Lista de alunos da disciplina "<<nome<<':'<<endl;
    for(aux=pPrimeiroAluno ; aux!=NULL ; aux=aux->pProxAluno)
        cout<<aux->getNome()<<endl;

}

void listaAlunos::setNota1(Aluno *aluno, float nota1) {
    elAluno* aux;
    for(aux= pPrimeiroAluno; aux!=NULL; aux= aux->pProxAluno){
        if(aux->getAluno()==aluno)
            aux->setNota1(nota1);
    }
}

void listaAlunos::setNota2(Aluno *aluno, float nota2) {
    elAluno* aux;
    for(aux= pPrimeiroAluno; aux!=NULL; aux= aux->pProxAluno){
        if(aux->getAluno()==aluno)
            aux->setNota2(nota2);
    }
}

void listaAlunos::addFalta(Aluno *aluno, int f) {
    elAluno* aux;
    for(aux= pPrimeiroAluno; aux!=NULL; aux= aux->pProxAluno){
        if(aux->getAluno()==aluno)
            aux->addFalta(f);
    }
}

void listaAlunos::imprimeMedias() {
    elAluno* aux;
    for(aux= pPrimeiroAluno; aux!=NULL; aux=aux->pProxAluno){
        cout<<"O aluno "<<aux->getNome()<<" está com média: "<<aux->getMedia()<<endl;
    }
}

void listaAlunos::setNome(const char *name) {
    strcpy(nome, name);

}

Aluno *listaAlunos::localizarID(int id) {
    elAluno* pElAluno=pPrimeiroAluno;
    Aluno* pAluno;

    while(pElAluno!=NULL){
        pAluno = pElAluno->getAluno();
        if(id == pAluno->getId())
            return pAluno;
        pElAluno = pElAluno->pProxAluno;
    }
    return NULL;
}



