//
// Created by bruno on 16/08/22.
//
#include "stdafx.h"
#include "Principal.h"

#include <fstream>
using namespace std;
Principal::Principal():
        idContUnivs(0),
        idContDptos(0),
        idContDisciplinas(0),
        idContProfessores(0),
        idContAlunos(0),
        //Professores
        Newton(idContProfessores++), Einstein(idContProfessores++), Simao(idContProfessores++),
        //Universidades
        Cambridge(idContUnivs++), Princeton(idContUnivs++), UTFPR(idContUnivs++),
        //Departamentos
        DAINF(idContDptos++), DAELN(idContDptos++), DAFIS(idContDptos++), DAQUI(idContDptos++)
        , FisicaCambridge(idContDptos++), FisicaPrinceton(idContDptos++),
        //Disciplinas
        fundProg(idContDisciplinas++), tecProg(idContDisciplinas++), estDados(idContDisciplinas++),
        //Pessoas
        Bruno(idContAlunos++), Joao(idContAlunos++), Pedro(idContAlunos++),
        Renato(idContAlunos++), Renato2(idContAlunos++)
{
    inicializarUniversidade();
    inicializarDepartamento();
    inicializarProfessor();
    inicializarAluno();
    inicializarDisciplina();

    struct tm *local;
    time_t segundos;
    time(&segundos);
    local = localtime(&segundos);

    diaAt = local->tm_mday;
    mesAt = local->tm_mon+1;
    anoAt = local->tm_year+1900;
}
Principal::~Principal() {

}
void Principal::Executar(){


    execUniversidade();
    execDepartamento();
    execProfessor();
    execAluno();
    execDisciplina();

    Menu();

    Universidade * aux1 = LUniversidades.localizarID(3);
    Universidade* aux2 = LUniversidades.localizarID(4);

    aux1->imprimeDepartamentos();
    aux2->imprimeDepartamentos();

}

void Principal::inicializarUniversidade() {

    Cambridge.setNome("Universidade de Cambridge");
    Princeton.setNome("Universidade de Princeton");
    UTFPR.setNome("UTFPR");

    //Associando(embora seja uma agregação) as universidades com seus respectivos departamentos.
    Cambridge.setDepartamento(&FisicaCambridge);
    Princeton.setDepartamento(&FisicaPrinceton);
    UTFPR.setDepartamento(&DAINF);
    UTFPR.setDepartamento(&DAELN);
    UTFPR.setDepartamento(&DAFIS);
    UTFPR.setDepartamento(&DAQUI);

}

void Principal::inicializarDepartamento() {
    DAINF.setNome("DAINF");
    DAELN.setNome("DAELN");
    DAFIS.setNome("DAFIS");
    DAQUI.setNome("DAQUI");
    FisicaCambridge.setNome("Dep. Fis. Cambridge");
    FisicaPrinceton.setNome("Dep Fis. Princeton");

    DAINF.setDisciplina(&fundProg);
    DAINF.setDisciplina(&tecProg);
    DAINF.setDisciplina(&estDados);


    DAINF.setUniv(&UTFPR);
    DAELN.setUniv(&UTFPR);
    DAFIS.setUniv(&UTFPR);
    DAQUI.setUniv(&UTFPR);
    FisicaCambridge.setUniv(&Cambridge);
    FisicaPrinceton.setUniv(&Princeton);
}

void Principal::inicializarDisciplina() {
    fundProg.setNome("Fundamentos de Programação");
    tecProg.setNome("Técnicas de programação");
    estDados.setNome("Estrutura de dados");

    fundProg.setDpto(&DAINF);
    tecProg.setDpto(&DAINF);
    estDados.setDpto(&DAINF);

    tecProg.setAluno(&Renato2);
    tecProg.setAluno(&Joao);
    tecProg.setAluno(&Pedro);
    tecProg.setAluno(&Renato);
    tecProg.setAluno(&Bruno);

    estDados.setAluno(&Pedro);
    estDados.setAluno(&Joao);

}

void Principal::inicializarProfessor() {
    Newton.Inicializa(4, 1, 1643, "Newton");
    Einstein.Inicializa(14, 3, 1879, "Einstein");
    Simao.Inicializa(3, 10, 1976, "Simão");

    Newton.setUnivAfiliada(&Cambridge);
    Einstein.setUnivAfiliada(&Princeton);
    Simao.setUnivAfiliada(&UTFPR);

    Newton.setDptoAfiliado(&FisicaCambridge);
    Einstein.setDptoAfiliado(&FisicaPrinceton);
    Simao.setDptoAfiliado(&DAINF);

}

void Principal::inicializarAluno() {
    Bruno.Inicializa(6, 2, 2002, "Bruno");
    Joao.Inicializa(5,12,2001,"Joao");
    Pedro.Inicializa(7,11,2003,"Pedro");
    Renato.Inicializa(24,6,2000,"Renato");
    Renato2.Inicializa(25,7,2001,"Renato");

    Bruno.setRA(2319136);
    Joao.setRA(34234);
    Pedro.setRA(4234324);
    Renato.setRA(65654);
    Renato2.setRA(546547);

    Bruno.setUniv(&UTFPR);
    Joao.setUniv(&UTFPR);
    Pedro.setUniv(&UTFPR);
    Renato.setUniv(&UTFPR);
    Renato2.setUniv(&UTFPR);
}

void Principal::execUniversidade() {
    UTFPR.imprimeDepartamentos();
}

void Principal::execDepartamento() {
    DAINF.imprimeDisciplinas();
}

void Principal::execDisciplina() {
    tecProg.removeAluno(&Renato);
    tecProg.imprimeAlunos();
    estDados.imprimeAlunos();
    tecProg.setNota1(&Bruno, 9.5);
    tecProg.setNota1(&Pedro, 8);
    tecProg.setNota2(&Bruno, 9.8);
    tecProg.setNota2(&Pedro, 7);
    tecProg.imprimeMedias();

}

void Principal::execProfessor() {
    Newton.calcIdade(diaAt, mesAt, anoAt);
    Einstein.calcIdade(diaAt, mesAt, anoAt);
    Simao.calcIdade(diaAt, mesAt, anoAt);

    Newton.ondeTrabalho();
    Newton.ondeDepartamentoTrabalho();
    Einstein.ondeTrabalho();
    Einstein.ondeDepartamentoTrabalho();
    Simao.ondeTrabalho();
    Simao.ondeDepartamentoTrabalho();

}

void Principal::execAluno() {
    Bruno.calcIdade(diaAt, mesAt, anoAt);
    Bruno.OndeEstudo();

}

void Principal::Menu() {
    int op=-1;
    while(op!=5)
    {
        system("clear");
        cout<<"Cadastrar 1"<<endl;
        cout<<"Executar 2"<<endl;
        cout<<"Gravar 3"<<endl;
        cout<<"Recuperar 4"<<endl;
        cout<<"Sair do menu 5"<<endl;
        cin>>op;
        switch(op){
            case 1:MenuCad();break;
            case 2:MenuExec();break;
            case 3:MenuGravar();break;
            case 4:MenuRecuperar();break;
            case 5:cout<<"FIM"<<endl;break;
            default: {cout<<"Opção inválida."<<endl;fflush(stdin);system("pause()");}break;
        }
    }
}

void Principal::MenuCad() {
    int op = -1;

    while (op != 5) {
        system("clear");
        cout << "Cadastrar universidade 1" << endl;
        cout << "Cadastrar departamento 2" << endl;
        cout << "Cadastrar disciplina 3" << endl;
        cout << "Cadastrar aluno 4" <<endl;
        cout << "Sair do menu cadastro 5" << endl;
        cin >> op;
        switch (op) {
            case 1:CadUniversidade();break;
            case 2:CadDepartamento();break;
            case 3:CadDisciplina();break;
            case 4:CadAluno();break;
            case 5:cout << "FIM" << endl;break;
            default:{cout << "Opção inválida." << endl;fflush(stdin);system("pause()");}break;
        }
    }
}

void Principal::CadUniversidade() {
    char nome[150];
    Universidade * aux1;

    cout<<"Insira o nome da universidade: ";
    cin>>nome;
    aux1 = new Universidade(idContUnivs++);
    aux1->setNome(nome);
    LUniversidades.incluaUniv(aux1);
}

void Principal::CadDepartamento() {
    char nome[150];
    Universidade* univ = NULL;
    cout<<"Insira o nome da universidade que você deseja cadastrar o departamento: ";
    cin>>nome;
    univ = LUniversidades.localizar(nome);
    if(univ!=NULL){
        Departamento* dpto;
        dpto = new Departamento(idContDptos++);
        cout<<"Insira o nome do departamento: ";
        cin>>nome;
        dpto->setNome(nome);
        dpto->setUniv(univ);
        LDepartamentos.setDpto(dpto);
        univ->setDepartamento(dpto);
    }
    else {
        cout << "Universidade inexistente" << endl;
        fflush(stdin);
        getchar();
    }
}

void Principal::CadDisciplina() {
    char nome[150];
    Departamento* dpto = NULL;
    cout<<"Insira o departamento que você deseja cadastrar a disciplina";
    cin>>nome;
    dpto = LDepartamentos.localizar(nome);
    if(dpto!=NULL)
    {
        Disciplina* disc;
        disc = new Disciplina(idContDisciplinas++);
        cout<<"Insira o nome da disciplina: ";
        cin>>nome;
        disc->setNome(nome);
        disc->setDpto(dpto);
        LDisciplinas.setDisciplina(disc);
        dpto->setDisciplina(disc);
    }
    else {
        cout << "Departamento inexistente" << endl;
        fflush(stdin);
        getchar();
    }
}

void Principal::CadAluno() {
    char nome[50];
    Aluno* aux;
    int RA;
    cout<<"Insira o nome do aluno: ";
    cin>>nome;
    cout<<"Insira o RA do aluno: ";
    cin>>RA;
    aux = new Aluno(idContAlunos++);
    aux->setNome(nome);
    aux->setRA(RA);
    LAlunos.setAluno(aux);
}

void Principal::MenuExec() {
    int op = -1;

    while(op !=5)
    {
        system("clear");
        cout<<"Imprimir lista universidades 1"<<endl;
        cout<<"Imprimir lista departamentos 2"<<endl;
        cout<<"Imprimir lista disciplinas 3"<<endl;
        cout<<"Imprimir lista alunos 4"<<endl;
        cout<<"Sair 5"<<endl;
        cin>>op;
        switch(op){
            case 1:{LUniversidades.listeUnivs();fflush(stdin);getchar();}break;
            case 2:{LDepartamentos.imprimeDptos();fflush(stdin);getchar();}break;
            case 3:{LDisciplinas.imprimeDisciplinas();fflush(stdin);getchar();}break;
            case 4:{LAlunos.imprimeAlunos();fflush(stdin);getchar();}break;
            case 5:cout<<"Saindo do menu cadastro"<<endl;break;
            default:{cout<<"Valor inserido inválido"<<endl;fflush(stdin);getchar();}break;
        }
    }
}



void Principal::MenuGravar() {
    int op = -1;

    while(op !=6)
    {
        system("clear");
        cout<<"Gravar tudo 1"<<endl;
        cout<<"Gravar universidades 2"<<endl;
        cout<<"Gravar departamentos 3"<<endl;
        cout<<"Gravar disciplinas 4"<<endl;
        cout<<"Gravar alunos 5"<<endl;
        cout<<"Sair 6"<<endl;
        cin>>op;
        switch(op){
            case 1:gravarTudo();break;
            case 2:gravarUnivs();break;
            case 3:gravarDptos();break;
            case 4:gravarDisciplinas();break;
            case 5:gravarAlunos();break;
            case 6:cout<<"Saindo do menu gravar"<<endl;break;
            default:{cout<<"Valor inserido inválido"<<endl;fflush(stdin);getchar();}break;
        }
    }

}
void Principal::gravarTudo() {
    gravarUnivs();
    gravarDptos();
    gravarDisciplinas();
    gravarAlunos();
}

void Principal::gravarUnivs() {
    ofstream GravadorUnivs( "Universidades.txt", ios::out );
    if(!GravadorUnivs){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    elUniversidade* pElUniversidade=LUniversidades.pPrimeiraUniv;
    Universidade* pUniversidade;
    while(pElUniversidade!=NULL){
        pUniversidade = pElUniversidade->getUniv();
        GravadorUnivs<<pUniversidade->getId()<<" "<<pUniversidade->getNome()<<endl;
        pElUniversidade = pElUniversidade->pProxUniv;
    }
    GravadorUnivs.close();
    gravarRUnivs();
}



void Principal::gravarDptos() {
    ofstream GravadorDptos( "Departamentos.txt", ios::out );
    if(!GravadorDptos){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    elDepartamento* pElDpto=LDepartamentos.pPrimeiroDpto;
    Departamento* pDpto;
    while(pElDpto!=NULL)
    {
        pDpto = pElDpto->getDpto();
        GravadorDptos<<pDpto->getId()<<" "<<pDpto->getNome()<<endl;
        pElDpto = pElDpto->pProxDpto;
    }
    GravadorDptos.close();
    gravarRDptos();

}


void Principal::gravarDisciplinas() {
    ofstream GravadorDisciplinas( "Disciplinas.txt", ios::out );
    if(!GravadorDisciplinas){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    elDisciplina* pElDisciplina=LDisciplinas.pPrimeiraDisciplina;
    Disciplina* pDisciplina=NULL;
    while(pElDisciplina!=NULL)
    {
        pDisciplina = pElDisciplina->getDisciplina();
        GravadorDisciplinas<<pDisciplina->getId()<<" "<<pDisciplina->getNome()<<endl;
        pElDisciplina = pElDisciplina->pProxDisciplina;
    }
    GravadorDisciplinas.close();
    gravarRDisciplinas();

}



void Principal::gravarAlunos() {
    ofstream GravadorAlunos( "Alunos.txt", ios::out );
    if(!GravadorAlunos){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    elAluno* pElAluno=LAlunos.pPrimeiroAluno;
    Aluno* pAluno;
    while(pElAluno!=NULL)
    {
        pAluno = pElAluno->getAluno();
        GravadorAlunos<<pAluno->getId()<<" "<<pAluno->getRA()<<" "<<pAluno->getNome()<<endl;
        pElAluno = pElAluno->pProxAluno;
    }
    GravadorAlunos.close();
}

void Principal::MenuRecuperar() {
    int op = -1;

    while(op !=6)
    {
        system("clear");
        cout<<"Recuperar tudo 1"<<endl;
        cout<<"Recuperar universidades 2"<<endl;
        cout<<"Recuperar departamentos 3"<<endl;
        cout<<"Recuperar disciplinas 4"<<endl;
        cout<<"Recuperar alunos 5"<<endl;
        cout<<"Recuperar 6"<<endl;
        cin>>op;
        switch(op){
            case 1:
                RecuperarTudo();break;
            case 2:RecuperarUnivs();break;
            case 3:RecuperarDptos();break;
            case 4:RecuperarDisciplinas();break;
            case 5:RecuperarAlunos();break;
            case 6:cout<<"Saindo do menu gravar"<<endl;break;
            default:{cout<<"Valor inserido inválido"<<endl;fflush(stdin);getchar();}break;
        }
    }

}

void Principal::RecuperarTudo() {
    RecuperarUnivs();
    RecuperarDptos();
    RecuperarDisciplinas();
    RecuperarAlunos();
    recuperarRUnivs();
    recuperarRDptos();
    recuperarRDisciplinas();
    recuperarRAlunos();
}

void Principal::RecuperarUnivs() {
    ifstream RecuperadorUnivs("Universidades.txt", ios::in);
    if(!RecuperadorUnivs){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    int id;
    char nome[50];
    Universidade* univ;
    while(RecuperadorUnivs>>id>>nome){

            univ =new Universidade(id);
            univ->setNome(nome);
            LUniversidades.incluaUniv(univ);
    }
    RecuperadorUnivs.close();

}





void Principal::RecuperarDptos() {
    ifstream RecuperadorDptos("Departamentos.txt", ios::in);
    if(!RecuperadorDptos){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    int id;
    char nome[50];
    Departamento* dpto;
    while(RecuperadorDptos>>id>>nome){

        dpto =new Departamento(id);
        dpto->setNome(nome);
        LDepartamentos.setDpto(dpto);
    }
    RecuperadorDptos.close();

}

void Principal::RecuperarDisciplinas() {
    ifstream RecuperadorDiscs("Disciplinas.txt", ios::in);
    if(!RecuperadorDiscs){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    int id;
    char nome[50];
    Disciplina* disc;
    while(RecuperadorDiscs>>id>>nome){

        disc =new Disciplina(id);
        disc->setNome(nome);
        LDisciplinas.setDisciplina(disc);
    }

    RecuperadorDiscs.close();

}

void Principal::RecuperarAlunos() {
    ifstream RecuperadorAlunos("Alunos.txt", ios::in);
    if(!RecuperadorAlunos){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    int id, RA;
    char nome[50];
    while(RecuperadorAlunos>>id>>RA>>nome){
        if(strcmp(nome, "")){
            Aluno* aux =new Aluno(id);
            aux->setRA(RA);
            aux->setNome(nome);
            LAlunos.setAluno(aux);
        }
    }
    RecuperadorAlunos.close();
}


void Principal::gravarRUnivs() {
    ofstream arquivo("RUniversidades.txt", ios::out);

    if(!arquivo){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    elUniversidade* pElUniversidade = LUniversidades.pPrimeiraUniv;
    Universidade* pUniversidade;
    elDepartamento* pElDpto;
    Departamento* pDpto;

    while(pElUniversidade!=NULL){
        pUniversidade = pElUniversidade->getUniv();
        arquivo<<pUniversidade->getId()<<" ";
        pElDpto = pUniversidade->lista.pPrimeiroDpto;
        while(pElDpto!=NULL){
            pDpto = pElDpto->getDpto();
            arquivo<<pDpto->getId()<<" ";
            pElDpto = pElDpto->pProxDpto;
        }
        arquivo<<-1<<endl;
        pElUniversidade = pElUniversidade->pProxUniv;
    }

    arquivo.close();
}

void Principal::gravarRDptos() {

    ofstream arquivo("RDepartamentos.txt", ios::out);

    if(!arquivo){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    elDepartamento* pElDpto = LDepartamentos.pPrimeiroDpto;
    Departamento* pDpto;
    elDisciplina* pElDisc;
    Disciplina* pDisc;

    while(pElDpto!=NULL){
        pDpto = pElDpto->getDpto();
        arquivo<<pDpto->getId()<<" ";
        arquivo<<pDpto->getUnivAssociada()<<" ";
        pElDisc = pDpto->lista.pPrimeiraDisciplina;
        while(pElDisc!=NULL){
            pDisc = pElDisc->getDisciplina();
            arquivo<<pDisc->getId()<<" ";
            pElDisc = pElDisc->pProxDisciplina;
        }
        arquivo<<-1<<endl;
        pElDpto = pElDpto->pProxDpto;
    }

    arquivo.close();

}

void Principal::gravarRDisciplinas() {
    ofstream arquivo("RDisciplinas.txt", ios::out);

    if(!arquivo){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }
    elDisciplina* pElDisc = LDisciplinas.pPrimeiraDisciplina;
    Disciplina* pDisc;
    elAluno* pElAluno;
    Aluno* pAluno;

    while(pElDisc!=NULL){
        pDisc = pElDisc->getDisciplina();
        arquivo<<pDisc->getId()<<" ";
        arquivo<<pDisc->getDpto()<<" ";
        pElAluno = pDisc->lista.pPrimeiroAluno;
        while(pElAluno!=NULL){
            pAluno = pElAluno->getAluno();
            arquivo<<pAluno->getId()<<" ";
            pElAluno = pElAluno->pProxAluno;
        }
        arquivo<<-1<<endl;
        pElDisc = pElDisc->pProxDisciplina;
    }
    arquivo.close();


}

void Principal::gravarRAlunos() {

}

void Principal::recuperarRUnivs() {
    Universidade *pUniv;
    Departamento *pDpto;
    int idUniv, idDpto;
    ifstream arquivo("RUniversidades.txt", ios::in);

    if(!arquivo){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    while(arquivo>>idUniv)
    {
        pUniv = LUniversidades.localizarID(idUniv);
        while((arquivo>>idDpto)&& idDpto!=-1)
        {
            pDpto = LDepartamentos.localizarID(idDpto);
            if(pDpto!=NULL)
                pUniv->setDepartamento(pDpto);
        }
    }
}

void Principal::recuperarRDptos() {

    Departamento *pDpto;
    Universidade * pUniv;
    Disciplina *pDisc;
    int  idDpto,idUniv, idDisc;
    ifstream arquivo("RDepartamentos.txt", ios::in);

    if(!arquivo){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    while(arquivo>>idDpto)
    {
        pDpto = LDepartamentos.localizarID(idDpto);
        arquivo>>idUniv;
        pUniv = LUniversidades.localizarID(idUniv);
        pDpto->setUniv(pUniv);
        while((arquivo>>idDisc) && idDisc!=-1)
        {
            pDisc = LDisciplinas.localizarID(idDisc);
            if(pDisc!=NULL)
                pDpto->setDisciplina(pDisc);
        }
    }
    arquivo.close();

}

void Principal::recuperarRDisciplinas() {
    Disciplina *pDisc;
    Departamento * pDpto;
    Aluno *pAluno;
    int  idDisc,idDpto, idAluno;
    ifstream arquivo("RDisciplinas.txt", ios::in);

    if(!arquivo){
        cerr<<"Arquivo não pode ser aberto"<<endl;
        fflush(stdin);
        getchar();
        return;
    }

    while(arquivo>>idDisc)
    {
        pDisc = LDisciplinas.localizarID(idDisc);
        arquivo>>idDpto;
        pDpto = LDepartamentos.localizarID(idDpto);
        pDisc->setDpto(pDpto);
        while((arquivo>>idAluno) && idAluno!=-1)
        {
            pAluno = LAlunos.localizarID(idAluno);
            if(pAluno!=NULL)
                pDisc->setAluno(pAluno);
        }
    }
    arquivo.close();
}

void Principal::recuperarRAlunos() {

}












