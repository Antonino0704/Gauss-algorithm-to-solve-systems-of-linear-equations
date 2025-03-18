#include <stdio.h>
#include <stdlib.h>
#include "../source/gauss.h"

int main() {
    int n, i;
    printf("insert n: ");
    scanf("%d", &n);
    float *b = calculate(fillRow(n), n);

    printf("values: ");
    for(i = n - 1; i >= 0; i--) {
        printf("[%.4f], ", b[i]);
    }
}
