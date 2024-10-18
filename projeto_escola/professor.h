#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "utils.h"

#define TAM_PROFESSOR 3     
#define MAX_NOME 100         
#define MAX_CPF 13          
#define MAX_SEXO 2   
#define TRUE 1
#define FALSE 0

// Códigos de retorno para as funções
#define CAD_PROFESSOR_SUCESSO 1
#define LISTA_CHEIA -1
#define MATRICULA_INVALIDA -2
#define MATRICULA_EXISTENTE -3
#define ATUALIZACAO_PROFESSOR_SUCESSO -4
#define MATRICULA_INEXISTENTE -5
#define EXCLUSAO_PROFESSOR_SUCESSO -6
#define CPF_EXISTENTE -8
#define SEXO_INVALIDO -9

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    char sexo;              
    DataNascimento data;    
    int ativo;             
} Professor;

// Protótipos das funções
int menuProfessor();
int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor);
void listarProfessor(Professor listaProfessor[], int qtdProfessor);
int atualizarProfessor(Professor listaProfessor[], int qtdProfessor);
int excluirProfessor(Professor listaProfessor[], int qtdProfessor);

#endif
