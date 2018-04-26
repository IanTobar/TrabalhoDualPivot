/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Funcoes.h"
#include <stdio.h>

void heapSort(int *a, int n, relatorio *r) {
    int i = n / 2, pai, filho, t;

    for (;;) {
        if (i > 0) {
            r->numComp++;
            i--;
            t = a[i];
        } else {
            r->numComp++;
            n--;
            if (n == 0) {
                r->numComp++;
                return;
            }
            t = a[n];
            a[n] = a[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n) && (a[filho + 1] > a[filho])) {
                r->numComp++;
                filho++;
            }
            if (a[filho] > t) {
                r->numComp++;
                a[pai] = a[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                r->numComp++;
                break;
            }
        }
        a[pai] = t;
    }
}

void quickSort(int *v, int inicio, int fim, relatorio *r) {
    int pivo;
    if (inicio < fim) {
        r->numComp++;
        pivo = particiona(v, inicio, fim,r);\
        quickSort(v, inicio, pivo - 1,r);
        quickSort(v, pivo + 1, fim,r);
    }
}

int particiona(int *v, int inicio, int fim, relatorio *r) {
    int pivo = v[inicio];
    int pos = inicio;

    for (int i = inicio + 1; i <= fim; i++) {
        if (v[i] < pivo) {
            r->numComp++;
            pos++;
            if (i != pos) {
                r->numComp++;
                printf("i = %d\npos = %d\n", i, pos);
                troca(&v[i], &v[pos]);
            }
        }
    }

    troca(&v[inicio], &v[pos]);
    r->numTrocas++;
    return pos;
}