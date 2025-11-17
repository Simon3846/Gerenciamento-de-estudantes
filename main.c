// Bibliotecas necessárias
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "menu.h"
#include "imprimir.h"
#include "aluno.h"

#define num

// Variáveis globais
int qtd;
int temp;
int count;
int temp_turmas;
int count_turmas = 0;

// Estrutura para turma
typedef struct {
    vet_nome nome_disciplina;
    aluno* estudantes[35]; // ponteiro para aluno
    int quantidade_alunos;
    int quantidade_disciplinas;
} turma;

turma turmas[5];
aluno estudante[200];

// Protótipos das funções
void cadastraturma();
void cadastraaluno();
void cadastra_nota();
void reg_presenca();
void verificar_situacao();
void verificar_aprovados();
void verificar_reprovados();
void imprimir_alunos();
void procurar_aluno();

/**
 * Função principal do programa.
 * Exibe o menu e executa as opções escolhidas pelo usuário.
 */
int main(void)
{
    int op = 0;
    do {
        display_menu();
        time_t tempo_atual;
        time(&tempo_atual); // Obtém o tempo atual

        printf("Hora atual: %s \n", ctime(&tempo_atual));
        printf("Quantidade de alunos cadastrados: %d \n", count);
        printf("Quantidade de disciplinas cadastradas: %d \n", count_turmas);
        printf("Escolha uma opção: \n");

        char buffer[32];
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erro na leitura da opção!\n");
            continue;
        }
        if (sscanf(buffer, "%d", &op) != 1) {
            printf("Valor inválido! Digite um número.\n");
            system("pause");
            continue;
        }

        switch (op) {
            case 1:
                system("cls");
                cadastraaluno();
                system("cls");
                break;
            case 2:
                system("cls");
                cadastraturma();
                system("cls");
                break;
            case 3:
                system("cls");
                verificar_situacao();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                verificar_aprovados();
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                verificar_reprovados();
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                imprimir_alunos();
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                procurar_aluno();
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                imprimir_dados(count, estudante);
                imprimir_disciplinas_aluno(count, estudante);
                cadastra_nota();
                system("pause");
                system("cls");
                break;
            case 9:
                system("cls");
                reg_presenca();
                system("pause");
                system("cls");
                break;
            case 10:
                printf("Obrigado, volte sempre !");
                return 0;
            default:
                printf("Valor inválido!!\n");
                system("pause");
        }
    } while (op != 10);

    return 0;
}




int count=0;
/**
 * Função para cadastrar alunos no sistema.
 * Solicita a quantidade de alunos, verifica limites e chama a função auxiliar para cadastro individual.
 */
void cadastraaluno()
{

   
    SetConsoleOutputCP(CP_UTF8);  // set console to UTF-8
    SetConsoleCP(CP_UTF8);        // set input to UTF-8
    
    
 
   
    printf("Insira a quantidade de alunos que deseja cadastrar: \n");
    
    
    scanf("%d",&qtd); 
    while (getchar() != '\n'); 
    temp = count;
    count += qtd;
    while(count>200){
        printf("A quantidade de alunos está maior que 35! , você pode cadastrar %d \n",35-temp);
        count = temp;
        printf("Insira a quantidade de alunos que deseja cadastrar: \n");
        scanf("%d",&qtd);
        while (getchar() != '\n'); 
        count +=qtd;
    }
  
    
    cadastra_alunos_2(qtd,estudante,temp);
    
}

/**
 * Função auxiliar para cadastrar os dados de cada aluno individualmente.
 * Recebe nome e matrícula, garantindo que não haja repetição de matrícula.
 */
void cadastra_alunos_2(int n, aluno *estudante, int temp) {

    for (int i = temp; i < temp + n; i++) {
        printf("Insira o nome do aluno: \n");
        fgets(estudante[i].nome, sizeof(estudante[i].nome), stdin);
        
        // remove uma linha do fgets
        estudante[i].nome[strcspn(estudante[i].nome, "\n")] = '\0';

        printf("Insira o número de matrícula do aluno: \n");
        scanf("%lf", &estudante[i].enrollment_number);
       jump_here:
        for(int j=0; j < i; j++){
            if(estudante[j].enrollment_number == estudante[i].enrollment_number){
                while(estudante[j].enrollment_number == estudante[i].enrollment_number){
                    printf("Número de matrícula repetido, digite um número de matrícula diferente ! \n" );
                    scanf("%lf", &estudante[i].enrollment_number);
                    goto jump_here;
                }
            }
        }

        while (getchar() != '\n');  // limpa o buffer do teclado
    }
    printf("%d Alunos cadastrados com sucesso! \n",n);
    system("pause");

    
}




/**
 * Função para cadastrar turmas (disciplinas) no sistema.
 * Permite associar alunos já cadastrados a cada disciplina.
 */
void cadastraturma(){
    temp_turmas = count_turmas;
    int disciplina;
    printf("Insira a quantidade de disciplinas que deseja cadastrar (max 5): \n");
    scanf(" %d",&disciplina);
    count_turmas += disciplina;
 
    while(count_turmas>5){
        count_turmas = temp_turmas;
        printf("Numero de disciplinas excedido! Cadastre no maximo 5! \n");

        printf("Insira a quantidade de disciplinas que deseja cadastrar (max 5): \n");
        scanf(" %d",&disciplina);

        
        count_turmas += disciplina;
    
    }
    
    int count_estudantes = 0;
   
    for (int i = temp_turmas; i < count_turmas; i++)
    {
        

        printf("Insira o nome da disciplina %d: \n", i+1);
        
        while (getchar() != '\n'); // Colocar uma linha aqui para limpar o buffer do teclado
        fgets(turmas[i].nome_disciplina, sizeof(turmas[i].nome_disciplina), stdin);
        turmas[i].nome_disciplina[strcspn(turmas[i].nome_disciplina, "\n")] = '\0'; // Remover a nova linha
        printf("Disciplina cadastrada: [%s]\n", turmas[i].nome_disciplina);

        
        printf("Disciplina %d cadastrada com sucesso! \n", i + 1);
        printf("Alunos que podem ser cadastrados nessa disciplina:  \n");
        imprimir_dados(count, estudante);
        do {
            printf("Insira a quantidade de alunos que deseja matricular nessa disciplina (max 35): \n");
            scanf("%d", &count_estudantes);
            if (count_estudantes > 35) {
                printf("Número de alunos excedido! Cadastre no máximo 35 alunos! \n");
            }
        } while (count_estudantes > 35);
        turmas[i].quantidade_alunos = count_estudantes;
        printf("Insira os números de matrícula dos alunos que deseja matricular nessa disciplina: \n");
        for(int k=0; k < count_estudantes; k++){
            double matricula;
            int found = 0;
            printf("Número de matrícula do aluno %d: \n", k + 1);
            scanf("%lf", &matricula);
            for(int j=0; j < count; j++){
                if(estudante[j].enrollment_number == matricula){
                    // adiciona disciplina ao aluno
                    strcpy(estudante[j].disciplinas[estudante[j].numero_disciplinas], turmas[i].nome_disciplina);
                    estudante[j].numero_disciplinas++;
                    // Armazena ponteiro para o aluno na turma
                    turmas[i].estudantes[k] = &estudante[j];
                    found = 1;
                    break;
                }
            }
            if(!found){
                printf("Número de matrícula não encontrado. Tente novamente.\n");
                k--; // decrementa k para repetir a iteração atual 
            }
        }
        // Fim do for de matrícula dos alunos
        
        
        
        system("pause");
    }
}

/**
 * Função para cadastrar notas de um aluno em uma disciplina.
 * Solicita matrícula, disciplina e registra as notas das atividades.
 */
void cadastra_nota(){
    int media;
    double enrollment_number;
    printf("Insira o número de matrícula do aluno que deseja cadastrar a nota: \n");
    scanf("%lf",&enrollment_number);
    for(int i=0; i < count; i++){
        if(estudante[i].enrollment_number == enrollment_number){
            if(estudante[i].numero_disciplinas == 0){
                printf("Aluno não está matriculado em nenhuma disciplina! \n");
                return;
            }
            printf("Aluno encontrado: %s \n", estudante[i].nome);
            printf("Disciplinas do aluno: \n");
            for(int j=0; j < estudante[i].numero_disciplinas; j++){
                printf("%d - %s \n", j+1, estudante[i].disciplinas[j]);
            }
            int disciplina_index;
            printf("Insira o número da disciplina que deseja cadastrar a nota: \n");
            scanf("%d", &disciplina_index);
            if(disciplina_index < 1 || disciplina_index > estudante[i].numero_disciplinas){
                printf("Número de disciplina inválido! \n");
                return;
            }
            disciplina_index--; // Ajusta para índice baseado em zero
             
            for(int l = 0 ; l < 2; l++){
                 printf("Insira a %dª nota da prova: ", l+1);
                scanf("%f", &estudante[i].notas[disciplina_index].P[l]);
                while( (l == 0 && (estudante[i].notas[disciplina_index].P[l] < 0 || estudante[i].notas[disciplina_index].P[l] > 30)) ||
                       (l == 1 && (estudante[i].notas[disciplina_index].P[l] < 0 || estudante[i].notas[disciplina_index].P[l] > 50)) )
                {
                    puts("Insira uma nota válida !!! As notas das provas são: P1 até 30, P2 até 50");
                    scanf("%f", &estudante[i].notas[disciplina_index].P[l]);
                }   

            }
            for(int m = 0 ; m < 2; m++){
                printf("Insira a %dª nota do exercício: ", m+1);
                scanf("%f", &estudante[i].notas[disciplina_index].E[m]);
                while(estudante[i].notas[disciplina_index].E[m] < 0 || estudante[i].notas[disciplina_index].E[m] > 5)
                {
                    puts("Insira uma nota válida !!! As notas dos exercícios são de 0 a 5");
                    scanf("%f", &estudante[i].notas[disciplina_index].E[m]);
                }   
            }

            printf("Insira a nota do trabalho: ");
            scanf("%f", &estudante[i].notas[disciplina_index].T);
            while(estudante[i].notas[disciplina_index].T < 0 || estudante[i].notas[disciplina_index].T > 10) // supondo que trabalho valha 10
            {
                puts("Insira uma nota válida !!! A nota do trabalho é de 0 a 10");
                scanf("%f", &estudante[i].notas[disciplina_index].T);
            }

            printf("Notas cadastradas com sucesso! \n");
            printf("Provas: %.2f, %.2f\n", estudante[i].notas[disciplina_index].P[0], estudante[i].notas[disciplina_index].P[1]);
            printf("Exercícios: %.2f, %.2f\n", estudante[i].notas[disciplina_index].E[0], estudante[i].notas[disciplina_index].E[1]);
            printf("Trabalho: %.2f\n", estudante[i].notas[disciplina_index].T);

            float media = (estudante[i].notas[disciplina_index].P[0] + estudante[i].notas[disciplina_index].P[1] + estudante[i].notas[disciplina_index].E[0] + estudante[i].notas[disciplina_index].E[1] + estudante[i].notas[disciplina_index].T);
            estudante[i].avarage_grade[disciplina_index] = media;   
            if(media >= 60){
                
                estudante[i].situation_grade[disciplina_index] = 1; // nota ok
            } else {
                
                estudante[i].situation_grade[disciplina_index] = 0; // nota reprovada
            }

            return;
        }
    }
}


/**
 * Função para registrar a presença (frequência) de um aluno.
 * Calcula o percentual de presença e atualiza a situação do aluno.
 */
void reg_presenca()
{
    printf("Insira o número de matrícula do aluno que deseja registrar a presença: \n");
    double enrollment_number;
    scanf("%lf", &enrollment_number);
    for(int i = 0; i < count; i++){
        if(estudante[i].enrollment_number == enrollment_number){
            if(estudante[i].numero_disciplinas == 0){
                printf("Aluno não está matriculado em nenhuma disciplina! \n");
                return;
            }
            printf("Aluno encontrado: %s \n", estudante[i].nome);
            printf("Insira a frequência do aluno (0 a 64): \n");
            int frequencia;
            scanf("%d", &frequencia);
            while(frequencia < 0 || frequencia > 64){
                printf("Frequência inválida! Insira um valor entre 0 e 64: \n");
                scanf("%d", &frequencia);
            }
            estudante[i].attedance = (frequencia / 64.0) * 100.0;
            printf("Frequência registrada: %.2f%% \n", estudante[i].attedance);
        }
        for(int j = 0; j < estudante[i].numero_disciplinas; j++){
            if(estudante[i].attedance >= 50.0){
                estudante[i].situation_attendace = 1; // frequência ok
            } else {
                estudante[i].situation_attendace = 0; // reprovado por frequência
            }
        }
    } 
}

/**
 * Função para verificar a situação de um aluno em todas as disciplinas.
 * Mostra frequência, média e se está aprovado ou reprovado.
 */
void verificar_situacao(){
    printf("Insira o número de matrícula do aluno que deseja verificar a situação: \n");
    double enrollment_number;
    scanf("%lf", &enrollment_number);
    int encontrado = 0;
    for(int i = 0; i < count; i++){
        if(estudante[i].enrollment_number == enrollment_number){
            encontrado = 1;
            for(int j=0; j < estudante[i].numero_disciplinas; j++){
                printf("Disciplina: %s \n", estudante[i].disciplinas[j]);
                printf("Frequência: %.2f%% \n", estudante[i].attedance);
                printf("Média: %.2f \n", estudante[i].avarage_grade[j]);
                if(estudante[i].situation_attendace == 1 && estudante[i].situation_grade[j] == 1){
                    printf("Situação: Aprovado \n");
                } else if(estudante[i].situation_attendace == 0){
                    printf("Situação: Reprovado por frequência \n");
                } else if(estudante[i].situation_grade[j] == 0){
                    printf("Situação: Reprovado por nota \n");
                }
            }
            break;
        }
    }
    if(!encontrado){
        printf("Aluno não encontrado! \n");
    }
}

/**
 * Função para listar todos os alunos aprovados em cada disciplina.
 * Mostra nome, disciplina e motivo da aprovação.
 */
void verificar_aprovados()
{
    printf("Alunos aprovados:\n");
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < estudante[i].numero_disciplinas; j++) {
            if(estudante[i].situation_attendace == 1 && estudante[i].situation_grade[j] == 1) {
                printf("Aluno: %s - Disciplina: %s - Motivo: Aprovado\n", estudante[i].nome, estudante[i].disciplinas[j]);
            }
        }
    }
}

                     
/**
 * Função para listar todos os alunos reprovados em cada disciplina.
 * Mostra nome, disciplina e motivo da reprovação (nota ou frequência).
 */
void verificar_reprovados()
{
   printf("Alunos reprovados:\n");
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < estudante[i].numero_disciplinas; j++) {
            if(estudante[i].situation_attendace == 0) {
                printf("Aluno: %s - Disciplina: %s - Motivo: Reprovado por frequência\n", estudante[i].nome, estudante[i].disciplinas[j]);
            } else if(estudante[i].situation_grade[j] == 0) {
                printf("Aluno: %s - Disciplina: %s - Motivo: Reprovado por nota\n", estudante[i].nome, estudante[i].disciplinas[j]);
            }
        }
    }
}

/**
 * Função para imprimir a lista de todos os alunos cadastrados.
 * Mostra nome e matrícula de cada aluno.
 */
void imprimir_alunos()
{
    printf("Lista de alunos cadastrados:\n");
    for(int i = 0; i < count; i++) {
        printf("Aluno: %s - Matrícula: %.0f\n", estudante[i].nome, estudante[i].enrollment_number);
    }
}

/**
 * Função para procurar um aluno pelo número de matrícula.
 * Mostra nome e disciplinas em que está matriculado.
 */
void procurar_aluno()
{
    printf("Insira a matrícula do aluno que deseja procurar: \n");
    double enrollment_number;
    scanf("%lf", &enrollment_number);
    for(int i = 0; i < count; i++) {
        if(estudante[i].enrollment_number == enrollment_number) {
            printf("Aluno encontrado: %s\n", estudante[i].nome);
            printf("Disciplinas:\n");
            for(int j = 0; j < estudante[i].numero_disciplinas; j++) {
                printf("- %s\n", estudante[i].disciplinas[j]);
            }
            return;
        }
    }
    printf("Aluno não encontrado!\n");
}