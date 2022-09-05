//
// Created by bruno on 05/09/22.
//

#include "elDepartamento.h"

elDepartamento::elDepartamento() {
    departamento = NULL;
    pAntDpto = NULL;
    pProxDpto = NULL;

}

elDepartamento::~elDepartamento() {

}

void elDepartamento::setDpto(Departamento *dpto) {
    departamento = dpto;
}

Departamento *elDepartamento::getDpto() {
    return departamento;
}

char* elDepartamento::getNome() {
    return departamento->getNome();
}
