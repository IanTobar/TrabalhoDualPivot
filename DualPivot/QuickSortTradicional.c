/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Funcoes.h"
#include <stdio.h>

void quickSort(int *v, int inicio, int fim) {
    int pivo;
    if (inicio < fim) {
        pivo = particiona(v, inicio, fim);
        printa_vetor(v,fim+1);
        quickSort(v, inicio, pivo - 1);
        quickSort(v, pivo + 1, fim);
    }
}

int particiona(int *v, int inicio, int fim) {
    int pivo = v[inicio];
    int pos = inicio;

    for (int i = inicio + 1; i <= fim; i++) {
        if (v[i] < pivo) {
            pos++;
            if (i != pos) {
                printf("i = %d\npos = %d\n", i, pos);
                troca(i, pos, v);
            }
        }
    }

    troca(inicio, pos, v);

    return pos;
}