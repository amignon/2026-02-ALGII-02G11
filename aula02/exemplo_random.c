#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int n = rand() % 3 + 1;
    printf("%d\n", n);
    return 0;
}