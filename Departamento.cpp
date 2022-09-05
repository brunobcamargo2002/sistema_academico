//
// Created by bruno on 17/08/22.
//
#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"



Departamento::Departamento(char const *n) {
    pUniv = NULL;
    lista = new listaDisciplinas(n, -1);
    setNome(n);
}

Departamento::~Departamento() {
        delete(lista);
}

void Departamento::setNome(const char *n) {
    strcpy(nome, n);
    lista->setNome(n);
}

char *Departamento::getNome() {
    return nome;
}

void Departamento::setUniv(Universidade *universidade) {
    pUniv = universidade;
}

void Departamento::setDisciplina(Disciplina *disc) {
    lista->setDisciplina(disc);
}

void Departamento::imprimeDisciplinas() {
    lista->imprimeDisciplinas();
}
