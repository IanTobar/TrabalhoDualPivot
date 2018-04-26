#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

void qSDualPivotCrescente(int*vet, int menorPos, int maiorPos, relatorio *r) {
    if (menorPos < maiorPos) {
        r->numComp++;
        int pivoEsq, pivoDir;
        pivoDir = divide(vet, menorPos, maiorPos, &pivoEsq, r);
        qSDualPivotCrescente(vet, menorPos, pivoEsq - 1, r);
        qSDualPivotCrescente(vet, pivoEsq + 1, pivoDir - 1, r);
        qSDualPivotCrescente(vet, pivoDir + 1, maiorPos, r);
    }
}

int divide(int* vet, int menorPos, int maiorPos, int*pivoEsq, relatorio *r) {
    if (vet[menorPos] > vet[maiorPos]) {
        r->numComp++;
        troca(&vet[menorPos], &vet[maiorPos]);
        r->numTrocas++;
    }

    int i = menorPos + 1;
    int j = maiorPos - 1;
    int k = menorPos + 1;
    int l = vet[menorPos];
    int m = vet[maiorPos];
    while (k <= j) {
        if (vet[k] < l) {
            r->numComp++;
            troca(&vet[k], &vet[i]);
            r->numTrocas++;
            i++;
        } else {
            r->numComp++;
            if (vet[k] >= m) {
                r->numComp++;
                while (vet[j] > m && k < j) j--;
                troca(&vet[k], &vet[j]);
                r->numTrocas++;
                j--;
                if (vet[k] < l) {
                    r->numComp++;
                    troca(&vet[k], &vet[i]);
                    r->numTrocas++;
                    i++;
                }
            }
        }
        k++;
    }
    i--;
    j++;

    troca(&vet[menorPos], &vet[i]);
    troca(&vet[maiorPos], &vet[j]);
    r->numTrocas += 2;
    *pivoEsq = i;
    return j;
}

