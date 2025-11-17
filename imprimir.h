
#include <stdio.h>
#include "aluno.h"

/**
 * Imprime a lista de todos os estudantes cadastrados.
 * Mostra o nome e o número de matrícula de cada aluno.
 */
void imprimir_dados(int count, aluno estudante[]){
    puts("----- Lista de Estudantes Cadastrados -----");
    for(int i = 0; i < count; i++){
        printf("Nome: %s ", estudante[i].nome);
        printf("Número de Matrícula: %.0lf\n", estudante[i].enrollment_number);
        printf("------------------------------\n");
    }
}

/**
 * Imprime as disciplinas em que cada estudante está matriculado.
 * Mostra o nome, matrícula e todas as disciplinas cadastradas para cada aluno.
 */
void imprimir_disciplinas_aluno(int count, aluno estudante[]){
    puts("----- Disciplinas dos Estudantes Cadastrados -----");
    for(int i = 0; i < count; i++){
        printf("Nome: %s ", estudante[i].nome);
        printf("Número de Matrícula: %.0lf\n", estudante[i].enrollment_number);
        printf("Disciplinas Cadastradas: \n");
        for(int j = 0; j < estudante[i].numero_disciplinas; j++){
            printf("- %s\n", estudante[i].disciplinas[j]);
        }
        printf("------------------------------\n");
    }
}