//
// Created by bruno on 07/09/22.
//

#include "elUniversidade.h"

elUniversidade::elUniversidade() {
    universidade = NULL;
    pAntUniv = NULL;
    pProxUniv = NULL;
}

elUniversidade::~elUniversidade() {

}

void elUniversidade::setUniv(Universidade *univ) {
    universidade = univ;

}

Universidade *elUniversidade::getUniv() {
    return universidade;
}

char *elUniversidade::getNome() {
    return universidade->getNome();
}
