#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"


float * fillColumn(int n) {
    float *p = (float*) malloc(n * sizeof(float) + 1);
    int i;
    for(i = 0; i < n; i++) {
        printf("insert value %d: ", i+1);
        scanf("%f", p+i);
    }
    printf("insert b value: ");
    scanf("%f", p+n);
    return p;
}

float **fillLine(int n) {
    float **m = (float**) malloc(n * sizeof(float *));
    int i;
    for(i = 0; i < n; i++) {
        printf("---Line %d---\n", i+1);
        m[i] = fillColumn(n);
    }
    return m;
}

int pivoting(float** m, int n, int index) {
    float max = m[index][index];
    int indexOfMax = index;
    int i;
    for(i = indexOfMax + 1; i < n; i++) {
        if(m[i][index] > max) {
            max = m[i][index];
            indexOfMax = i;
        }
    }
    return indexOfMax;
}

void switchMatrix(float **m, int n, int index, int newIndex) {
    int j;
    for(j = index; j <= n; j++) {
        float tmp = m[index][j];
        m[index][j] = m[newIndex][j];
        m[newIndex][j] = tmp;
    }
}

float sum(float **m, int n, float *b, int index) {
    float sum = 0;
    int j, k;
    for(j = n - 1, k = 0; j > index; j--, k++) {
        sum += m[index][j] * b[k];
    }
    return sum;
}

float *calculate(float **m, int n) {
    int i, j, k;
    for(k = 0; k < n - 1; k++) {
        int indexOfMax = pivoting(m, n, k);
        if(m[indexOfMax][k] == 0) {
            printf("an unknown cannot all have coefficients equal to 0");
            return NULL;
        }
        
        if(k != indexOfMax) switchMatrix(m, n, k, indexOfMax);
        
        for(i = k + 1; i < n; i++) {
            float t = m[i][k] / m[k][k];
            m[i][k] -= t * m[k][k];
            for(j = k + 1; j <= n; j++) {
                m[i][j] -= t * m[k][j];
            }
        }
    }
    float *b = (float*) malloc(n * sizeof(float));
    for(k = n - 1, i = 0; k >= 0; k--, i++) {
        b[i] = (m[k][n] - sum(m, n, b, k)) / m[k][n-i-1];
    }
    return b;
}