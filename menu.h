
// Linhas do Menu
char menu1[] = "            Gerenciamento Escolar        ";
char menu2[] = "  1- Cadastrar Aluno                     ";
char menu3[] = "  2- Cadastrar Disciplina                "; 
char menu4[] = "  3- Verificar situação                  ";
char menu5[] = "  4- Verificar Aprovados                 ";
char menu6[] = "  5- Verificar Reprovados                ";
char menu7[] = "  6- Listagem Geral                      ";
char menu8[] = "  7- Procurar Alunos                     ";
char menu9[] = "  8- Cadastrar Notas                     ";
char menu10[] = "  9- Cadastrar Presença                  ";
char menu11[] = "  10- Sair                               ";
char copyright[] = "  Desenvolvido por: Simon & Luiz         ";

/**
 * Exibe uma linha do menu dentro da janela, com bordas laterais.
 * @param string Linha do menu a ser exibida.
 */
void display(char *string) {
    printf("\xE2\x94\x83"); // borda esquerda ┃
    while (*string) {
        printf("%c", *string);
        string++;
        Sleep(1);
    }
    printf("\xE2\x94\x83\n"); // borda direita ┃
}

/**
 * Imprime a borda superior da janela do menu.
 * @param n Tamanho da borda.
 */
void print_upperwindow(int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0)
            printf("\xE2\x94\x8F"); // ┏
        else if (i == n - 1)
            printf("\xE2\x94\x93"); // ┓
        else
            printf("\xE2\x94\x81"); // ━
        Sleep(1);
    }
    printf("\n");
}

/**
 * Imprime a borda inferior da janela do menu.
 * @param n Tamanho da borda.
 */
void print_lowerwindow(int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0)
            printf("\xE2\x94\x97"); // ┗
        else if (i == n - 1)
            printf("\xE2\x94\x9B"); // ┛
        else
            printf("\xE2\x94\x81"); // ━
        Sleep(1);
    }
    printf("\n");
}

/**
 * Exibe o menu principal do sistema na tela, com bordas e opções formatadas.
 */
void display_menu(void) {
    SetConsoleOutputCP(CP_UTF8);  // ativa caracteres UTF-8
    system("color 17");           // fundo azul, texto branco

    print_upperwindow(43);
    display(menu1);
    display(menu2);
    display(menu3);
    display(menu4);
    display(menu5);
    display(menu6);
    display(menu7);
    display(menu8);
    display(menu9);
    display(menu10);
    display(menu11);
    display(copyright);
    print_lowerwindow(43);
}

