//
// Created by bruno on 17/08/22.
//
#include "stdafx.h"
#include "Departamento.h"

Departamento::Departamento(char const *n) {
    setNome(n);
}

Departamento::~Departamento() {

}

void Departamento::setNome(const char *n) {
    strcpy(nome, n);
}

char *Departamento::getNome() {
    return nome;
}

void Departamento::setUniv(Universidade *universidade) {
    pUniv = universidade;
}
