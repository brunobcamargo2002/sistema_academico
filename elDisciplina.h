//
// Created by bruno on 02/09/22.
//

#ifndef SISTEMA_ACADEMICO_ELDISCIPLINA_H
#define SISTEMA_ACADEMICO_ELDISCIPLINA_H
class Disciplina;
class elDisciplina {
    Disciplina* disciplina;


public:
    elDisciplina* pAntDisciplina;
    elDisciplina* pProxDisciplina;
    elDisciplina();
    ~elDisciplina();
    void setDisciplina(Disciplina* disciplina1);
    char* getNome();
    Disciplina* getDisciplina();



};


#endif //SISTEMA_ACADEMICO_ELDISCIPLINA_H
