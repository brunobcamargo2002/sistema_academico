//
// Created by bruno on 27/08/22.
//
#include "stdafx.h"
#include "Disciplina.h"

Disciplina::Disciplina(const char *codigo) {
    setNome(codigo);
    antDisciplina = NULL;
    proxDisciplina= NULL;
    dptoFiliado= NULL;
    maxAlunos= 45;
    numAlunos= 0;
    pPrimeiroAluno= NULL;
    pAlunoAtual= NULL;


}

Disciplina::~Disciplina() {

}

void Disciplina::setNome(const char *codigo) {
    strcpy(nome, codigo);
}

char* Disciplina::getNome() {
    return nome;
}

void Disciplina::setDpto(Departamento *dpto) {
    dptoFiliado = dpto;
}

void Disciplina::setAluno(Aluno *aluno) {
    if(pPrimeiroAluno==NULL) {
        pPrimeiroAluno = aluno;
        pAlunoAtual = aluno;
        numAlunos++;
    }
    else if(numAlunos<maxAlunos)
    {
        numAlunos++;
        Aluno *aux=pPrimeiroAluno;
        int flag = 1;
        int i=0;
        char* nome1 = aluno->getNome();
        char* nome2;

        while(aux!=NULL && flag){
            nome2 = aux->getNome();
            i=0;
            while(nome1[i]==nome2[i] && nome1[i]!='\0' && nome2[i]!='\0') i++;
            if(nome1[i]<=nome2[i])
            {
                aluno->pAntAluno = aux->pAntAluno;
                aluno->pProxAluno = aux;
                aux->pAntAluno = aluno;
                if(aluno->pAntAluno!=NULL)
                    aluno->pAntAluno->pProxAluno=aluno;
                else
                    pPrimeiroAluno = aluno;
                flag = 0;
            }
            else
            {
                aux = aux->pProxAluno;
            }
        }
        if(flag){
            pAlunoAtual->pProxAluno = aluno;
            aluno->pAntAluno = pAlunoAtual;
            aluno->pProxAluno = NULL;
            pAlunoAtual = aluno;
        }
    }
    else
        cout<<"A matricula do aluno "<<aluno->getNome()<<" não foi realizada, pois a turma está cheia."<<endl;
}

void Disciplina::removeAluno(Aluno *aluno) {
    Aluno* aux;

    for(aux=pPrimeiroAluno; aux!=NULL; aux= aux->pProxAluno)
    {
        if(aux==aluno)
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

void Disciplina::imprimeAlunos() {
    Aluno *aux;
    cout<<"Lista de alunos da disciplina "<<getNome()<<':'<<endl;
    for(aux=pPrimeiroAluno ; aux!=NULL ; aux=aux->pProxAluno)
        cout<<aux->getNome()<<endl;
}
