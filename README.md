# gerenciamento-de-estudantes
Sistema básico em C para gerenciar notas e disciplinas de alunos cadastrados. Não utiliza arquivos, então todas as informações são apagadas após a execução.
# Gerenciamento Escolar

Este programa realiza o gerenciamento de alunos, disciplinas, notas e frequência em um sistema escolar simples via terminal.

## Funcionalidades
- Cadastro de alunos (nome e matrícula única)
- Cadastro de disciplinas (turmas)
- Associação de alunos às disciplinas
- Cadastro de notas (2 provas, 2 exercícios, 1 trabalho)
- Cálculo automático da média
- Registro de frequência (presença)
- Verificação da situação do aluno (aprovado/reprovado por nota ou frequência)
- Listagem de alunos, disciplinas e busca por matrícula
- Interface de menu interativo

## Critérios de Aprovação
- Média das notas maior ou igual a 60 pontos (total de 100 pontos possíveis)
- Frequência mínima de 50% (32 de 64 aulas)

## Estruturas Utilizadas
- Estrutura `aluno`: armazena dados pessoais, disciplinas, notas, médias, frequência e situação
- Estrutura `turma`: armazena nome da disciplina e alunos matriculados
- Estrutura `nota`: armazena notas das provas, exercícios e trabalho

## Como Compilar
Utilize o compilador GCC (MinGW no Windows):
```sh
gcc -Wall -Wextra -g3 main.c -o main.exe
```

## Como Executar
No terminal:
```sh
main.exe
```

## Autores
SimãO Baptista Sunga & Luiz Felipe Santana

## Observações
- O programa utiliza caracteres especiais para bordas do menu, por isso recomenda-se rodar em terminal que suporte UTF-8.
- O código está totalmente comentado e organizado para facilitar o entendimento.
- É um dos nossos primeiros projectos e na altura não sabiamos muito sobre modularização do codigo (explicando o motivo de ter criado um imprimir.h sem o imprimir.c).
