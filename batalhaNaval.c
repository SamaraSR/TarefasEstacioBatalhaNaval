#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


#define TAM 10
#define TAM_HAB 5

int main() {
    setlocale(LC_ALL, "Portuguese");

    // nº 0 representará água e 3 os navios
    int tabuleiro[TAM][TAM] = {0}; 

    // Navios horizontais, verticais e diagonais
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    // Posições iniciais dos navios
    int linhaH = 2, colunaH = 2; // horizontal
    int linhaV = 6, colunaV = 7; // vertical
    int linhaD1 = 0, colunaD1 = 6; // diagonal principal
    int linhaD2 = 5, colunaD2 = 3; // diagonal secundária

    int i, j;

    // Validação para posicionar navios
    int podeColocar = 1;

    // Horizontal
    for (i = 0; i < 3; i++) {
        if (colunaH + i >= TAM || tabuleiro[linhaH][colunaH + i] != 0) {
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
        if (linhaV + i >= TAM || tabuleiro[linhaV + i][colunaV] != 0) {
            podeColocar = 0;
        }
    }
    if (podeColocar) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }

    // Diagonal principal
    podeColocar = 1;
    for (i = 0; i < 3; i++) {
        if (linhaD1 + i >= TAM || colunaD1 + i >= TAM || tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
            podeColocar = 0;
        }
    }
    if (podeColocar) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
        }
    }

    // Diagonal secundária
    podeColocar = 1;
    for (i = 0; i < 3; i++) {
        if (linhaD2 + i >= TAM || colunaD2 - i < 0 || tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
            podeColocar = 0;
        }
    }
    if (podeColocar) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = navioDiagonal2[i];
        }
    }

    // Matrizes de habilidade: Cone, Cruz e Octaedro
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    // Preenchendo a matriz Cone (em forma de pirâmide para baixo)
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB/2 - i && j <= TAM_HAB/2 + i && i <= TAM_HAB/2) {
                cone[i][j] = 1;
            }
        }
    }

    // Preenchendo a matriz Cruz (linha e coluna central marcadas)
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // Preenchendo a matriz Octaedro (losango com centro no meio)
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB/2) + abs(j - TAM_HAB/2) <= TAM_HAB/2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Função para sobrepor matriz de habilidade no tabuleiro
    void aplicarHabilidade(int tab[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
        int i, j;  
        for (i = 0; i < TAM_HAB; i++) {
            for (j = 0; j < TAM_HAB; j++) {
                int lin = origemLinha - TAM_HAB/2 + i;
                int col = origemColuna - TAM_HAB/2 + j;
                if (lin >= 0 && lin < TAM && col >= 0 && col < TAM) {
                    if (habilidade[i][j] == 1 && tab[lin][col] == 0) {
                        tab[lin][col] = 5; // Marca como área de efeito da habilidade
                    }
                }
            }
        }
    }

    // Aplicando habilidades no tabuleiro em pontos específicos
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 7, 2);
    aplicarHabilidade(tabuleiro, octaedro, 2, 8);

    // Exibir o tabuleiro final
    printf("\n*** BATALHA NAVAL COM HABILIDADES ***\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
