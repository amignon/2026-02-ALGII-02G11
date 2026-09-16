#include <stdio.h>

#define LINHA 3
#define COLUNA 2

void le_matriz(int linha, int coluna, int m[linha][coluna]);
void imprime_matriz(int linha, int coluna, int m[linha][coluna]);
void transposta(int lin, int col, int A[lin][col], int At[col][lin]);

int main() {
    int A[LINHA][COLUNA];
    int At[COLUNA][LINHA];
    le_matriz(LINHA, COLUNA, A);
    transposta(LINHA, COLUNA, A, At);
    imprime_matriz(COLUNA, LINHA, At);
    return 0;
}

void le_matriz(int linha, int coluna, int m[linha][coluna]) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprime_matriz(int linha, int coluna, int m[linha][coluna]) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }   
}

void transposta(int lin, int col, int A[lin][col], int At[col][lin]) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            At[j][i] = A[i][j];
        }
    }
}