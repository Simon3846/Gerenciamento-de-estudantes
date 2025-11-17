
#ifndef ALUNO_H
#define ALUNO_H

/**
 * Estrutura que representa as notas de um aluno em uma disciplina.
 * P: Vetor de notas das provas (P1 e P2)
 * E: Vetor de notas dos exercícios (E1 e E2)
 * T: Nota do trabalho final
 */
typedef struct {
    float P[2];  // Provas: P1 (até 30), P2 (até 50)
    float E[2];  // Exercícios: E1 e E2 (cada até 5)
    float T;     // Trabalho final (até 10)
} nota;

/**
 * Vetor para armazenar nomes (aluno ou disciplina)
 */
typedef char vet_nome[50];

/**
 * Estrutura principal do aluno.
 * nome: Nome do aluno
 * enrollment_number: Número de matrícula (único)
 * numero_disciplinas: Quantidade de disciplinas em que está matriculado
 * disciplinas: Nomes das disciplinas
 * notas: Notas em cada disciplina
 * avarage_grade: Média em cada disciplina
 * attedance: Frequência do aluno (percentual)
 * situation_attendace: Situação da frequência (1=aprovado, 0=reprovado)
 * situation_grade: Situação da nota em cada disciplina (1=aprovado, 0=reprovado)
 */
typedef struct {
    vet_nome nome;                    // Nome do aluno
    double enrollment_number;         // Número de matrícula
    int numero_disciplinas;           // Quantidade de disciplinas
    vet_nome disciplinas[5];          // Disciplinas em que está matriculado
    nota notas[5];                    // Notas em cada disciplina
    float avarage_grade[5];           // Média em cada disciplina
    float attedance;                  // Frequência do aluno
    int situation_attendace;          // Situação da frequência
    int situation_grade[5];           // Situação da nota em cada disciplina
} aluno;

#endif