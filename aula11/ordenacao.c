#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100000

void bubbleSort(int v[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int v[], int n) {
    int menor, temp;
    for (int i = 0; i < n; i++) {
        menor = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        if (v[i] != v[menor]) {
            temp = v[i];
            v[i] = v[menor];
            v[menor] = temp;
        }
    }
}

void insertionSort(int v[], int n) {
    int chave;
    for (int i = 1; i < n; i++) {
        chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
    
}

void imprime(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    clock_t inicio, fim;
    int bubble[TAMANHO];
    int selection[TAMANHO];
    int insertion[TAMANHO];
    int valor;

    // popula o vetor com valores aleatórios
    for (int i = 0; i < TAMANHO; i++) {
        valor = rand() % 100000;
        bubble[i] = valor;
        insertion[i] = valor;
        selection[i] = valor;
    }

    inicio = clock();
    bubbleSort(bubble, TAMANHO);
    fim = clock();
    double tempoBubble = ((double) (fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

    inicio = clock();
    selectionSort(selection, TAMANHO);
    fim = clock();
    double tempoSelection = ((double) (fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

    inicio = clock();
    insertionSort(insertion, TAMANHO);
    fim = clock();
    double tempoInsertion = ((double) (fim - inicio) / CLOCKS_PER_SEC) * 1000.0;


    printf("Tempo Bubble   : %.1lfms\n", tempoBubble);
    printf("Tempo Selection: %.1lfms\n", tempoSelection);
    printf("Tempo Insertion: %.1lfms\n", tempoInsertion);

    return 0;
}