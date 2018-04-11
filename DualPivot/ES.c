#include <stdio.h>
#include <stdlib.h>
#include "ES.h"

void lerArquivo(char nomeArquivo, int *vet) {
    FILE *entrada;
    int i = 0;
    entrada = fopen(nomeArquivo, "r");
    if (entrada == NULL) {
        printf("Arquivo Vazio /n");
    }
    while (!feof(entrada)) {
        fscanf(entrada, '%i', vet[i]);
        i++;
    }
}