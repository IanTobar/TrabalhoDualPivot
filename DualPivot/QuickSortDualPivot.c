#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

void troca(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void qSDualPivotCrescente(int*vet, int menorPos, int maiorPos) {
    if (menorPos < maiorPos) {
        int pivoEsq, pivoDir;
        pivoDir = divide(vet, menorPos, maiorPos, &pivoEsq);
        qSDualPivotCrescente(vet, menorPos, pivoEsq - 1);
        qSDualPivotCrescente(vet, pivoEsq + 1, pivoDir - 1);
        qSDualPivotCrescente(vet, pivoDir + 1, maiorPos);
    }
}

int divide(int* vet, int menorPos, int maiorPos, int*pivoEsq) {
    if (vet[menorPos] > vet[maiorPos]) {
        troca(&vet[menorPos], &vet[maiorPos]);
    }

    int i = menorPos + 1;
    int j = maiorPos - 1;
    int k = menorPos + 1;
    int l = vet[menorPos];
    int m = vet[maiorPos];
    while (k <= j) {
        if (vet[k] < l) {
            troca(&vet[k], &vet[i]);
            i++;
        } else if (vet[k] >= m) {
            while (vet[j] > m && k < j) j--;
            troca(&vet[k], &vet[j]);
            j--;
            if (vet[k] < l) {
                troca(&vet[k], &vet[i]);
                i++;
            }
        }
        k++;
    }
    i--;
    j++;

    troca(&vet[menorPos], &vet[i]);
    troca(&vet[maiorPos], &vet[j]);
    *pivoEsq = i;
    return j;
}

