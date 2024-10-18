#include <stdio.h>
#include <string.h>  // Necessário para usar strcmp e strcpy
#include "professor.h"

int menuProfessor() {
    int opcao;
    printf("0 - Voltar\n");
    printf("1 - Cadastrar professor\n");
    printf("2 - Listar professor\n");
    printf("3 - Atualizar professor\n");
    printf("4 - Excluir professor\n");

    scanf("%d", &opcao);
    return opcao;
}

int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == TAM_PROFESSOR) {
        return LISTA_CHEIA;
    } else {
        printf("Digite a matrícula do professor:\n");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            return MATRICULA_INVALIDA;
        }
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].matricula == matricula)
                return MATRICULA_EXISTENTE;
        }

        int sexo;
        do {
            printf("Digite o sexo do professor (M/F):\n");

            // Limpar o buffer
            getchar();

            scanf(" %c", &sexo);
            sexo = toupper(sexo); // Converte para maiúscula

            if (sexo != 'M' && sexo != 'F') {
                printf("Sexo inválido. Digite M ou F!\n");
                // Limpa o buffer de entrada, para nova leitura de scanf
                getchar();
            }
        } while (sexo != 'M' && sexo != 'F');




        // Limpar o buffer antes de usar fgets
        getchar();

        printf("Digite o CPF do professor:\n");
        char cpf[MAX_CPF];
        fgets(cpf, MAX_CPF, stdin);
        cpf[strcspn(cpf, "\n")] = 0;  // Remove o '\n' no final da string

        for (int i = 0; i < qtdProfessor; i++) {
            if (strcmp(listaProfessor[i].cpf, cpf) == 0)
                return CPF_EXISTENTE;
        }

        printf("Digite o nome do professor:\n");
        char nome[MAX_NOME];
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = 0;  // Remove o '\n' no final da string

        // Transferir os dados para a lista de alunos
        listaProfessor[qtdProfessor].matricula = matricula;
        strcpy(listaProfessor[qtdProfessor].cpf, cpf);
        strcpy(listaProfessor[qtdProfessor].nome, nome);
        listaProfessor[qtdProfessor].sexo = sexo;
        listaProfessor[qtdProfessor].ativo = TRUE;

        printf("Cadastro realizado com sucesso\n");
        return CAD_PROFESSOR_SUCESSO;
    }
}

void listarProfessor(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == 0) {
        printf("-- Lista de professores vazia --\n");
    } else {
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].ativo == TRUE) {
                printf("Matrícula: %d\n", listaProfessor[i].matricula);
                printf("Nome: %s\n", listaProfessor[i].nome);
                printf("CPF: %s\n", listaProfessor[i].cpf);
                printf("Sexo: %c\n", listaProfessor[i].sexo);
            }
        }
    }
}

int atualizarProfessor(Professor listaProfessor[], int qtdProfessor) {
    printf("Digite a matrícula do professor:\n");
    int matricula;
    scanf("%d", &matricula);
    if (matricula < 0) {
        return MATRICULA_INVALIDA;
    }
    for (int i = 0; i < qtdProfessor; i++) {
        if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo == TRUE) {
            printf("Digite a nova matrícula:\n");
            int novaMatricula;
            scanf("%d", &novaMatricula);
            if (novaMatricula < 0) {
                return MATRICULA_INVALIDA;
            }
            listaProfessor[i].matricula = novaMatricula;
            return ATUALIZACAO_PROFESSOR_SUCESSO;
        }
    }
    return MATRICULA_INEXISTENTE;
}

int excluirProfessor(Professor listaProfessor[], int qtdProfessor) {
    printf("Digite a matrícula do professor:\n");
    int matricula;
    scanf("%d", &matricula);
    if (matricula < 0) {
        return MATRICULA_INVALIDA;
    }
    for (int i = 0; i < qtdProfessor; i++) {
        if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo == TRUE) {
            listaProfessor[i].ativo = FALSE;
            return EXCLUSAO_PROFESSOR_SUCESSO;
        }
    }
    return MATRICULA_INEXISTENTE;
}
