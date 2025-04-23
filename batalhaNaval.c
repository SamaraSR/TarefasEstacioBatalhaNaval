#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

	// nº 0 representará agua e 3 os navios, um será posicionado na horizontal e outro na vertical
	
    int tabuleiro[10][10] = {0}; 
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

	// Posição inicial dos navios
    int linhaH = 2, colunaH = 2; //horizontal
    int linhaV = 6, colunaV = 7; //vertical
    int i, j; 
   

    // Posiciona navio horizontal
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical
    for (i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // Exibe o tabuleiro
    printf("*** BATALHA NAVAL ***\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
