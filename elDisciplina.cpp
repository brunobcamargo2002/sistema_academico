//
// Created by bruno on 02/09/22.
//

#include "elDisciplina.h"
#include "Disciplina.h"

elDisciplina::elDisciplina() {
    disciplina = NULL;
    pAntDisciplina = NULL;
    pProxDisciplina = NULL;
}

elDisciplina::~elDisciplina() {

}

void elDisciplina::setDisciplina(Disciplina *disciplina1) {
    disciplina = disciplina1;
}

char* elDisciplina::getNome() {
    return disciplina->getNome();
}

Disciplina* elDisciplina::getDisciplina() {
    return disciplina;
}


