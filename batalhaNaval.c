#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

	// nº 0 representará agua e 3 os navios, um será posicionado na horizontal e outro na vertical
	
    int tabuleiro[10][10] = {0}; 
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};
    

	// Posição inicial dos navios
    int linhaH = 2, colunaH = 2; //horizontal
    int linhaV = 6, colunaV = 7; //vertical
    int linhaD1 = 0, colunaD1 = 6; // Diagonal1
    int linhaD2 = 5, colunaD2 = 3; // Diagonal2

    int i, j; 
   

   // Validação 
    int podeColocar = 1;

    // Horizontal
    for (i = 0; i < 3; i++) {
        if (colunaH + i >= 10 || tabuleiro[linhaH][colunaH + i] != 0) {
            podeColocar = 0;
        }
    }
    if (podeColocar) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }

    // Vertical
    podeColocar = 1;
    for (i = 0; i < 3; i++) {
        if (linhaV + i >= 10 || tabuleiro[linhaV + i][colunaV] != 0) {
            podeColocar = 0;
        }
    }
    if (podeColocar) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }

    // Diagonal 1
    podeColocar = 1;
    for (i = 0; i < 3; i++) {
        if (linhaD1 + i >= 10 || colunaD1 + i >= 10 || tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
            podeColocar = 0;
        }
    }
    if (podeColocar) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
        }
    }

    // Diagonal 2
    podeColocar = 1;
    for (i = 0; i < 3; i++) {
        if (linhaD2 + i >= 10 || colunaD2 - i < 0 || tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
            podeColocar = 0;
        }
    }
    if (podeColocar) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = navioDiagonal2[i];
        }
    }

    // Exibir tabuleiro
    printf("*** BATALHA NAVAL ***\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}