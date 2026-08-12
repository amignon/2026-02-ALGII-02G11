#include <stdio.h>

int main() {
    float n1;
    float n2;

    printf("N1: ");
    scanf("%f", &n1);
    printf("N2: ");
    scanf("%f", &n2);

    float media = (n1 + n2) / 2;

    printf("Media: %.2f\n", media);

    return 0;
}