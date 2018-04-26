/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Funcoes.h"

void resetaStructRelatorio(relatorio* r) {
    r->numComp = 0;
    r->numTrocas = 0;
}

void printaStructRelatorio(relatorio* r) {
    printf("Numero de Comparacoes: %d\nNumero de Trocas: %d\n", r->numComp, r->numTrocas);
}

void troca(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void printaVetor(int* v, int tamanhoVetor) {
    for (int i = 0; i < tamanhoVetor; i++)
        printf("%d ", v[i]);

    printf("\n");
}