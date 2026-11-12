#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "../source/gauss.h"

void getNumber(int *value) {
    char max[1000];
    char *end;
    long n;

    if (!fgets(max, sizeof(max), stdin)) {
        fprintf(stderr, "Error fgets\n");
        exit(EXIT_FAILURE);
    }
    
    errno = 0;
    n = strtol(max, &end, 10);

    if(end == max) {
        fprintf(stderr, "Error value is null\n");
        exit(EXIT_FAILURE);
    }

    if(*end != '\0' && *end != '\n') {
        fprintf(stderr, "Error value is not valid\n");
        exit(EXIT_FAILURE);
    }

    if (errno == ERANGE) {
        fprintf(stderr, "value insert too long for long type\n");
        exit(EXIT_FAILURE);
    }

     if (n < INT_MIN || n > INT_MAX) {
        fprintf(stderr, "value insert too long\n");
        exit(EXIT_FAILURE);
    }

    *value = (int) n;
}

int main() {
    int n, i;
    printf("insert n: ");
    getNumber(&n);
    float *b = calculate(fillRow(n), n);

    printf("values: ");
    for(i = n - 1; i >= 0; i--) {
        printf("[%.4f], ", b[i]);
    }
    printf("\n");
    free(b);
    b = NULL;
}
