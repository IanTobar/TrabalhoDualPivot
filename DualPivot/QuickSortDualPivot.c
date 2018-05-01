#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"

void qSDualPivotCrescente(int*vet, int menorPos, int maiorPos, relatorio *r) {
    if (menorPos < maiorPos) {
        int pivoEsq, pivoDir;
        pivoDir = divide(vet, menorPos, maiorPos, &pivoEsq, r);
        qSDualPivotCrescente(vet, menorPos, pivoEsq - 1, r);
        qSDualPivotCrescente(vet, pivoEsq + 1, pivoDir - 1, r);
        qSDualPivotCrescente(vet, pivoDir + 1, maiorPos, r);
    }
}

int particiona(int* vet, int inicio, int fim, int*pivoEsq, relatorio *r) {

    //pivo a esquerda = posicao inicial do vetor
    //pivo a direita = posicao final do vetor

    //O pivo a esquerda sempre deve ser menor que o pivo a direita
    if (vet[inicio] > vet[fim])
        troca(&vet[inicio], &vet[fim]);

    //Valores marcadores
    //i = garante separacao de valores < pivo dir e > pivo esq
    //k = garante separacao de valores < pivo esq
    //j = garante separacao de valores > pivo a esq
    int i = inicio + 1,j = fim - 1,k = inicio + 1;
    //Valores pivo
    int l = vet[inicio], m = vet[fim];//Pivo a esquerda, Pivo a direita

    //Compara os marcadores com os valores pivos
    while (k <= j) {
        if (vet[k] < l) {
            troca(&vet[k], &vet[i]);
            i++;
        } else {
            if (vet[k] >= m) {
                while (vet[j] > m && k < j)
                    j--;
                troca(&vet[k], &vet[j]);
                j--;
                if (vet[k] < l) {
                    troca(&vet[k], &vet[i]);
                    i++;
                }
            }
        }
        k++;
    }
    i--;
    j++;

    //Troca os valores pivo com seus marcadores
    troca(&vet[inicio], &vet[i]);
    troca(&vet[fim], &vet[j]);
    *pivoEsq = i;
    return j;
}

