
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct Relatorio{
    int numComp;
    int numTrocas;
}relatorio;

void resetaStructRelatorio(relatorio* r);
void printaStructRelatorio(relatorio* r);
void troca(int* a, int* b);
void printaVetor(int* v, int tamanhoVetor);

//Quick Dual Pivot
void qSDualPivotCrescente (int* vet, int menorPos, int maiorPos, relatorio *r);
int divide(int* vet, int menorPos, int maiorPos, int*pivoEsq,relatorio *r);

//Quick Tradicional
void quickSort(int *v, int inicio, int fim,relatorio *r);
int particiona(int *v, int inicio, int fim,relatorio *r);

//HeapSort
void heapSort(int *a, int n, relatorio *r);

#endif 
