
#ifndef FUNCOES_H
#define FUNCOES_H

//Quick Dual Pivot
void troca (int* a, int* b);
void qSDualPivotCrescente (int* vet, int menorPos, int maiorPos);
int divide(int* vet, int menorPos, int maiorPos, int*pivoEsq);

//Quick Tradicional
void quickSort(int *v, int inicio, int fim);
int particiona(int *v, int inicio, int fim);


#endif 
