#include <stdio.h>
#include <string.h>

#define TAM 15

// Busca Linear
int buscaLinear(char palavras[][20], int tamanho, char procurada[]);

// Busca Binária
int buscaBinaria(char palavras[][20], int tamanho, char procurada[]);


int main() {
    char palavras[TAM][20] = {
        "abacaxi",
        "banana",
        "cachorro",
        "dado",
        "elefante",
        "foca",
        "gato",
        "hotel",
        "igreja",
        "janela",
        "kiwi",
        "laranja",
        "macaco",
        "navio",
        "ovelha"
    };

    char palavra[20];
    printf("Informe a palavra: ");
    scanf("%19s", palavra);

    printf("Busca Linear: ");
    int posicao = buscaLinear(palavras, TAM, palavra);
    printf("%d\n", posicao);

    printf("Busca Binária: ");
    posicao = buscaBinaria(palavras, TAM, palavra);
    printf("%d\n", posicao);
}

int buscaLinear(char palavras[][20], int tamanho, char procurada[]) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(palavras[i], procurada) == 0) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(char palavras[][20], int tamanho, char procurada[]) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio, comparacao;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        comparacao = strcmp(palavras[meio], procurada);
        if (comparacao == 0) {
            return meio;
        }
        else if (comparacao < 0) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return -1;
}
