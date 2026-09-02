#include <stdio.h>
#define TAMANHO (8)

int contaPares(int v[], int tamanho);

int main() {
    int  vetor[TAMANHO];
    for (int i = 0; i < TAMANHO; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    int pares = contaPares(vetor, TAMANHO);
    printf("Quantidade de pares: %d\n", pares);
}

int contaPares(int v[], int tamanho) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (v[i] % 2 == 0) {
            contador++;
        }
    }
    return contador;
}

