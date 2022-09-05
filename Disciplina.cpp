//
// Created by bruno on 27/08/22.
//

#include "Disciplina.h"

Disciplina::Disciplina(const char *codigo)
{
    setNome(codigo);
    dptoFiliado= NULL;
}

Disciplina::~Disciplina() {

}

void Disciplina::setNome(const char *codigo) {
    strcpy(nome, codigo);
    lista.setNome(codigo);
}

char* Disciplina::getNome() {
    return nome;
}

void Disciplina::setDpto(Departamento *dpto) {
    dptoFiliado = dpto;
}

void Disciplina::setAluno(Aluno *aluno) {
    lista.setAluno(aluno);

}

void Disciplina::removeAluno(Aluno *aluno) {
    lista.removeAluno(aluno);
}

void Disciplina::imprimeAlunos() {
    lista.imprimeAlunos();
}

void Disciplina::setNota1(Aluno *aluno, float nota1) {
    lista.setNota1(aluno, nota1);
}

void Disciplina::setNota2(Aluno *aluno, float nota2) {
    lista.setNota2(aluno, nota2);
}

void Disciplina::addFalta(Aluno *aluno, int f) {
    lista.addFalta(aluno, f);
}

void Disciplina::imprimeMedias() {
    lista.imprimeMedias();
}




