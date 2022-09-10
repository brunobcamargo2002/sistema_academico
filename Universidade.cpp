//
// Created by bruno on 17/08/22.
//

#include "Universidade.h"
Universidade::Universidade(int identificador) {
    id = identificador;
}

Universidade::~Universidade() {
}

void Universidade::setNome(char const *n) {
    strcpy(Nome, n);
    lista.setNome(n);
}

char* Universidade::getNome() {
    return Nome;
}

void Universidade::setDepartamento(Departamento* departamento)
{
    lista.setDpto(departamento);
}

void Universidade::imprimeDepartamentos() {
    lista.imprimeDptos();
}

int Universidade::getId() {
    return id;
}
