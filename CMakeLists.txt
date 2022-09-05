cmake_minimum_required(VERSION 3.23)
project(sistema_academico)

set(CMAKE_CXX_STANDARD 14)

add_executable(sistema_academico main.cpp Pessoa.cpp Pessoa.h Principal.cpp Principal.h stdafx.cpp stdafx.h Universidade.cpp Universidade.h Departamento.cpp Departamento.h Professor.cpp Professor.h Aluno.cpp Aluno.h Disciplina.cpp Disciplina.h elAluno.cpp elAluno.h elDisciplina.cpp elDisciplina.h listaAlunos.cpp listaAlunos.h listaDisciplinas.cpp listaDisciplinas.h listaDepartamentos.cpp listaDepartamentos.h elDepartamento.cpp elDepartamento.h)
