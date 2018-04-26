#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ES.h"
#include "Funcoes.h"

/*
 * 
 */
int main(int argc, char** argv) {

    FILE *a; //Ponteiro que vai apontar para o arquivo
    FILE *b;
    int op, tamanho_vetor; //op = variavel para armazenar opções/tamanho_vetor = guarda o tamanho do vetor
    char entrada[100], saida[100];
    relatorio *r = (relatorio*) malloc(sizeof (relatorio));

    srand(time(NULL));

    printf("Digite o nome do arquivo\n");
    scanf(" %[^\n]s", entrada);

    //Pega o tamanho do vetor
    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &tamanho_vetor);

    //Aloca o vetor dinamicamente por malloc
    int *v = (int*) malloc(tamanho_vetor * sizeof (int));

    for (int i = 0; i < tamanho_vetor; i++)
        v[i] = tamanho_vetor - i;

    /*cria_arquivo(a, &entrada);
    escreveArquivo(a, &entrada, tamanho_vetor);
    lerArquivo(&entrada, v);
     */
    //MENU
    do {
        resetaStructRelatorio(r);
        printf("[1]Ordenar por DualPivot QuickSort (ordem crescente)\n");
        printf("[2]Ordenar por QuickSort Tradicional\n");
        printf("[3]Sair\n");
        scanf("%d", &op);

        printaVetor(v, tamanho_vetor);

        switch (op) {

            case 1:
                printf("Digite o nome de arquivo de saida\n");
                scanf(" %[^\n]s", saida);
                qSDualPivotCrescente(v, 0, tamanho_vetor, r);
                printaVetor(v, tamanho_vetor);
                printaStructRelatorio(r);
                //salvaArquivo(b, saida, tamanho_vetor, v);
                break;
            case 2:
                printf("Digite o nome de arquivo de saida\n");
                scanf(" %[^\n]s", saida);
                quickSort(v, 0, tamanho_vetor, r);
                printaVetor(v, tamanho_vetor);
                printaStructRelatorio(r);
                //salvaArquivo(b, saida, tamanho_vetor, v);                           
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


