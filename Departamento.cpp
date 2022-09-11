//
// Created by bruno on 17/08/22.
//
#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"



Departamento::Departamento(int identificador) {
    id = identificador;
    pUniv = NULL;
}

Departamento::~Departamento() {
}

void Departamento::setNome(const char *n) {
    strcpy(nome, n);
    lista.setNome(n);
}

char *Departamento::getNome() {
    return nome;
}

void Departamento::setUniv(Universidade *universidade) {
    pUniv = universidade;
}

void Departamento::setDisciplina(Disciplina *disc) {
    lista.setDisciplina(disc);
}

void Departamento::imprimeDisciplinas() {
    lista.imprimeDisciplinas();
}

int Departamento::getId() {
    return id;
}

int Departamento::getUnivAssociada() {
   if(pUniv==NULL)
       return -1;
    return pUniv->getId();
}
