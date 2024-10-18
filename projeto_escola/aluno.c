#include <stdio.h>
#include <string.h>  // Necessário para usar strcmp e strcpy
#include "aluno.h"

int menuAluno() {
    int opcao;
    printf("0 - Voltar\n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Listar aluno\n");
    printf("3 - Atualizar aluno\n");
    printf("4 - Excluir aluno\n");

    scanf("%d", &opcao);
    return opcao;
}

int cadastrarAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == TAM_ALUNO) {
        return LISTA_CHEIA;
    } else {
        printf("Digite a matrícula do aluno:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].matricula == matricula)
                return MATRICULA_EXISTENTE;
        }

        int sexo;
        do {
            printf("Digite o sexo do aluno (M/F):\n");

            // Limpar o buffer
            getchar();

            scanf(" %c", &sexo);
            sexo = toupper(sexo); // Converte para maiúscula

            if (sexo != 'M' && sexo != 'F') {
                printf("Sexo inválido. Digite M ou F!\n");
                // Limpa o buffer de entrada
                while (getchar() != '\n'); // Para evitar que qualquer caractere residual cause problemas
            }
        } while (sexo != 'M' && sexo != 'F');



        
        // Limpar o buffer antes de usar fgets
        getchar();

        printf("Digite o CPF do aluno:\n");
        char cpf[MAX_CPF];
        fgets(cpf, MAX_CPF, stdin);
        cpf[strcspn(cpf, "\n")] = 0;  // Remove o '\n' no final da string

        for (int i = 0; i < qtdAluno; i++) {
            if (strcmp(listaAluno[i].cpf, cpf) == 0)
                return CPF_EXISTENTE;
        }

        printf("Digite o nome do aluno:\n");
        char nome[MAX_NOME];
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = 0;  // Remove o '\n' no final da string

        // Transferir os dados para a lista de alunos
        listaAluno[qtdAluno].matricula = matricula;
        strcpy(listaAluno[qtdAluno].cpf, cpf);
        strcpy(listaAluno[qtdAluno].nome, nome);
        listaAluno[qtdAluno].sexo = sexo;
        listaAluno[qtdAluno].ativo = TRUE;

        printf("Cadastro realizado com sucesso\n");
        return CAD_ALUNO_SUCESSO;
    }
}

void listarAluno(Aluno listaAluno[], int qtdAluno) {
    if (qtdAluno == 0) {
        printf("-- Lista de alunos vazia --\n");
    } else {
        for (int i = 0; i < qtdAluno; i++) {
            if (listaAluno[i].ativo == TRUE) {
                printf("Matrícula: %d\n", listaAluno[i].matricula);
                printf("Nome: %s\n", listaAluno[i].nome);
                printf("CPF: %s\n", listaAluno[i].cpf);
                printf("Sexo: %c\n", listaAluno[i].sexo);
            }
        }
    }
}

int atualizarAluno(Aluno listaAluno[], int qtdAluno) {
    printf("Digite a matrícula do aluno:\n");
    int matricula;
    scanf("%d", &matricula);
    if (matricula < 0) {
        return MATRICULA_INVALIDA;
    }
    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == TRUE) {
            printf("Digite a nova matrícula:\n");
            int novaMatricula;
            scanf("%d", &novaMatricula);
            if (novaMatricula < 0) {
                return MATRICULA_INVALIDA;
            }
            listaAluno[i].matricula = novaMatricula;
            return ATUALIZACAO_ALUNO_SUCESSO;
        }
    }
    return MATRICULA_INEXISTENTE;
}

int excluirAluno(Aluno listaAluno[], int qtdAluno) {
    printf("Digite a matrícula do aluno:\n");
    int matricula;
    scanf("%d", &matricula);
    if (matricula < 0) {
        return MATRICULA_INVALIDA;
    }
    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].matricula == matricula && listaAluno[i].ativo == TRUE) {
            listaAluno[i].ativo = FALSE;
            return EXCLUSAO_ALUNO_SUCESSO;
        }
    }
    return MATRICULA_INEXISTENTE;
}

