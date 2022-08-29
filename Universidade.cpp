//
// Created by bruno on 17/08/22.
//

#include "Universidade.h"
Universidade::Universidade(char const * n) {
    setNome(n);
}

Universidade::~Universidade() {

}

void Universidade::setNome(char const *n) {
    strcpy(Nome, n);
}

char* Universidade::getNome() {
    return Nome;
}

void Universidade::setDepartamento(Departamento* departamento)
{
    pDptos.push_back(departamento);
}

void Universidade::imprimeDepartamentos() {
    list<Departamento*>::iterator iterador;
    cout<<"Departamentos da "<<getNome()<<":"<<endl;
    for(iterador=pDptos.begin(); iterador!=pDptos.end();iterador++)
        cout<<(*iterador)->getNome()<<endl;
}
