#include <stdio.h>
#include "aluno.h"
#include "professor.h"

int menuGeral();

int main() {
    Aluno listaAluno[TAM_ALUNO];
    Professor listaProfessor[TAM_PROFESSOR];
    int opcao;
    int qtdAluno = 0;
    int qtdProfessor = 0;
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
                    printf("Atualizar aluno\n");
                    int sairAtualizarAluno = FALSE;
                    int opcaoAtualizarAluno;

                    while (sairAtualizarAluno == FALSE) {
                        opcaoAtualizarAluno = menuAtualizarAluno(); 

                        switch (opcaoAtualizarAluno) {
                            case 0: {
                                sairAtualizarAluno = TRUE;
                                break;
                            }
                            case 1: {
                                int retorno = atualizarMatriculaAluno(listaAluno, qtdAluno);
                                if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                    printf("Matrícula de aluno atualizada com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                            case 2: {
                                int retorno = atualizarNomeAluno(listaAluno, qtdAluno);
                                if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                    printf("Nome de aluno atualizado com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                            case 3: {
                                int retorno = atualizarSexoAluno(listaAluno, qtdAluno);
                                if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                    printf("Sexo de aluno atualizado com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                            case 4: {
                                int retorno = atualizarCpfAluno(listaAluno, qtdAluno);
                                if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                    printf("CPF do aluno atualizado com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                            case 5: {
                                int retorno = atualizarDataNascAluno(listaAluno, qtdAluno);
                                if (retorno == ATUALIZACAO_ALUNO_SUCESSO)
                                    printf("Data de nascimento do aluno atualizada com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                        }
                    }
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
            int sairProfessor = FALSE;
            int opcaoProfessor;

            while (sairProfessor == FALSE) {
                opcaoProfessor = menuProfessor();

                switch (opcaoProfessor) {
                case 0: {
                    sairProfessor = TRUE;
                    break;
                }
                case 1: {
                    int retorno = cadastrarProfessor(listaProfessor, qtdProfessor);
                    if (retorno == LISTA_CHEIA)
                        printf("Lista de professores cheia\n");
                    else if (retorno == MATRICULA_INVALIDA)
                        printf("Matrícula inválida\n");
                    else if (retorno == MATRICULA_EXISTENTE)
                        printf("Matrícula já existente\n");
                    else if (retorno == CPF_EXISTENTE)
                        printf("CPF já existente\n");
                    else if (retorno == SEXO_INVALIDO)
                        printf("Sexo inválido\n");
                    else {
                        printf("Professor cadastrado com sucesso\n");
                        qtdProfessor++;
                    }
                    break;
                }
                case 2: {
                    listarProfessor(listaProfessor, qtdProfessor);
                    break;
                }
                case 3: {
                    printf("Atualizar professor\n");
                    int sairAtualizarProfessor = FALSE;
                    int opcaoAtualizarProfessor;
                    
                    while (sairAtualizarProfessor == FALSE){
                        opcaoAtualizarProfessor = menuAtualizarProfessor();
                        
                        switch (opcaoAtualizarProfessor){
                            case 0:{
                                sairAtualizarProfessor = TRUE;
                                break;
                            }
                            case 1:{
                                int retorno = atualizarMatriculaProfessor(listaProfessor, qtdProfessor);
                                if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                    printf("Matrícula de professor atualizada com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                            case 2:{
                                int retorno = atualizarNomeProfessor(listaProfessor, qtdProfessor);
                                if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                    printf("Nome de professor atualizado com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                            case 3:{
                                int retorno = atualizarSexoProfessor(listaProfessor, qtdProfessor);
                                if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                    printf("Sexo de professor atualizado com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                            case 4:{
                                int retorno = atualizarCpfProfessor(listaProfessor, qtdProfessor);
                                if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                    printf("CPF do professor atualizado com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                            case 5:{
                                int retorno = atualizarDataNascProfessor(listaProfessor, qtdProfessor);
                                if (retorno == ATUALIZACAO_PROFESSOR_SUCESSO)
                                    printf("CPF do professor atualizado com sucesso\n");
                                else if (retorno == MATRICULA_INEXISTENTE)
                                    printf("Matrícula inexistente\n");
                                else if (retorno == MATRICULA_INVALIDA)
                                    printf("Matrícula inválida\n");
                                break;
                            }
                        }
                    }
                    break;
                }
                case 4: {
                    int retorno = excluirProfessor(listaProfessor, qtdProfessor);
                    if (retorno == EXCLUSAO_PROFESSOR_SUCESSO) {
                        printf("Professor excluído com sucesso\n");
                        qtdProfessor--;
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
