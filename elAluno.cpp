//
// Created by bruno on 30/08/22.
//
#include "elAluno.h"

elAluno::elAluno() {
    aluno = NULL;
    pAntAluno = NULL;
    pProxAluno= NULL;
    nota1 = 0;
    nota2 = 0;
    media = 0;
    faltas = 0;
}

elAluno::~elAluno(){

}

void elAluno::setAluno(Aluno *pa) {
    aluno = pa;
}

Aluno *elAluno::getAluno() {
    return aluno;
}

char *elAluno::getNome() {
    aluno->getNome();
}

void elAluno::setNota1(float n1) {
    nota1 = n1;
    calcMedia();

}

void elAluno::setNota2(float n2) {
    nota2= n2;
    calcMedia();
}

void elAluno::calcMedia() {
    media = (float)(nota1+nota2)/2;
}

void elAluno::addFalta(int f) {
    faltas+=f;
}

float elAluno::getMedia() {
    return media;
}
