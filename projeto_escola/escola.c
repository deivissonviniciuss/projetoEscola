#include <stdio.h>
#include "aluno.h"

int menuGeral();

int main() {
    Aluno listaAluno[TAM_ALUNO];
    int opcao;
    int qtdAluno = 0;
    int sair = FALSE;

    // Tela inicial com as opções e leitura
    while (sair == FALSE) {
        opcao = menuGeral();

        // Switch para cada opção
        switch (opcao) {
        case 0: {
            sair = TRUE;
            break;
        }
        case 1: {
            printf("Módulo Aluno\n");
            int sairAluno = FALSE;
            int opcaoAluno;

            while (sairAluno == FALSE) {
                opcaoAluno = menuAluno();

                switch (opcaoAluno) {
                case 0: {
                    sairAluno = TRUE;
                    break;
                }
                case 1: {
                    int retorno = cadastrarAluno(listaAluno, qtdAluno);
                    if (retorno == LISTA_CHEIA)
                        printf("Lista de alunos cheia\n");
                    else if (retorno == MATRICULA_INVALIDA)
                        printf("Matrícula inválida\n");
                    else if (retorno == MATRICULA_EXISTENTE)
                        printf("Matrícula já existente\n");
                    else if (retorno == CPF_EXISTENTE)
                        printf("CPF já existente\n");
                    else if (retorno == SEXO_INVALIDO)
                        printf("Sexo inválido\n");
                    else {
                        printf("Aluno cadastrado com sucesso\n");
                        qtdAluno++;
                    }
                    break;
                }
                case 2: {
                    listarAluno(listaAluno, qtdAluno);
                    break;
                }
                case 3: {
                    int retorno = atualizarAluno(listaAluno, qtdAluno);
                    if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                        printf("Aluno atualizado com sucesso\n");
                    else if (retorno == MATRICULA_INEXISTENTE)
                        printf("Matrícula inexistente\n");
                    else if (retorno == MATRICULA_INVALIDA)
                        printf("Matrícula inválida\n");
                    break;
                }
                case 4: {
                    int retorno = excluirAluno(listaAluno, qtdAluno);
                    if (retorno == EXCLUSAO_ALUNO_SUCESSO) {
                        printf("Aluno excluído com sucesso\n");
                        qtdAluno--;
                    } else if (retorno == MATRICULA_INEXISTENTE)
                        printf("Matrícula inexistente\n");
                    else if (retorno == MATRICULA_INVALIDA)
                        printf("Matrícula inválida\n");
                    break;
                }
                }
            }
            break;
        }
        case 2: {
            printf("Módulo Professor\n");
            break;
        }
        default: {
            printf("Opção inválida!\n");
        }
        }
    }

    return 0;
}

int menuGeral() {
    int opcao;
    printf("Projeto Escola\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");

    scanf("%d", &opcao);
    return opcao;
}
