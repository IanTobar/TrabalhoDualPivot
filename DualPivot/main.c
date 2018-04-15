#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "ES.h"
#include "Funcoes.h"

/*
 * 
 */
int main(int argc, char** argv) {

    FILE *a; //Ponteiro que vai apontar para o arquivo
    FILE *b;
    int op, tamanho_vetor; //op = variavel para armazenar opções/tamanho_vetor = guarda o tamanho do vetor
    double ti = 0, tf = 0, tempo = 0; //Tempo Inicial, Tempo Final e Tempo gasto
    struct timeval tempo_inicial, tempo_final;
    char entrada[100], saida[100];

    printf("Digite o nome do arquivo\n");
    scanf(" %[^\n]s", entrada);

    //Pega o tamanho do vetor
    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &tamanho_vetor);

    //Aloca o vetor dinamicamente por malloc
    int *v = (int*) malloc(tamanho_vetor * sizeof (int));
    cria_arquivo(a, entrada);
    escreveArquivo(a, entrada, tamanho_vetor);
    lerArquivo(entrada, v);

    //MENU
    do {
        printf("[1]Ordenar por DualPivot QuickSort (ordem crescente)\n");
        printf("[2]Ordenar por DualPivot QuickSort (ordem decrescente)\n");
        printf("[3]Sair\n");
        scanf("%d", &op);

        switch (op) {

            case 1:
                printf("Digite o nome de arquivo de saida\n");
                scanf(" %[^\n]s", saida);
                gettimeofday(&tempo_inicial, NULL);
                qSDualPivotCrescente(v, 0, tamanho_vetor);
                gettimeofday(&tempo_final, NULL);
                ti = (double) tempo_inicial.tv_usec + ((double) tempo_inicial.tv_sec * (1000000.0));
                tf = (double) tempo_final.tv_usec + ((double ) tempo_final.tv_sec * (1000000.0));
                tempo = (tf - ti) / 1000;
                
                salvaArquivo(b, saida, tamanho_vetor, v);

                break;
            case 2:
                printf("Digite o nome de arquivo de saida\n");
                scanf(" %[^\n]s", saida);
                qSDualPivotDecrescente(v, 0, tamanho_vetor);
                salvaArquivo(b, saida, tamanho_vetor, v);
                break;
            case 3:
                exit(1);
                break;
            default:
                break;
        }
    } while (op != 3);
    return (EXIT_SUCCESS);
}

