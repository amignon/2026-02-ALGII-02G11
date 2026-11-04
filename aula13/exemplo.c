/*
Uma papelaria armazena seus produtos em estoque.txt no formato nome;quantidade;preco. 
Escreva um programa que leia os registros e grave em reposicao.txt apenas 
os produtos que têm menos de cinco unidades. Ao final, apresente o valor total do estoque. 
*/
#include <stdio.h>

#define MAX_PRODUTOS 100

typedef struct {
    char nome[101];
    int quantidade;
    float preco;
} Produto;

// Carrega os produtos do arquivo para o vetor e retorna a quantidade de registros
int carregarProdutos(Produto produtos[], int n) {
    FILE *arquivo;
    char linha[200];
    int total = 0;

    arquivo = fopen("estoque.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo estoque.txt\n");
        return -1;
    }
    
    while (total < n && fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%99[^;];%d;%f",
            produtos[total].nome, &produtos[total].quantidade,
            &produtos[total].preco) == 3) {
            total++;
        }
    }
    fclose(arquivo);
    return total;
} 

int imprimirProdutos(Produto produtos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%25s | %3d | %6.2f\n", produtos[i].nome,
        produtos[i].quantidade, produtos[i].preco);
    }
}
int main() {
    Produto produtos[MAX_PRODUTOS];
    int total = carregarProdutos(produtos, MAX_PRODUTOS);
    imprimirProdutos(produtos, total);
    printf("\nTotal de registros lidos: %d\n", total);
    return 0;
}