#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ES.h"
#include "Funcoes.h"
#include <sys/time.h>

int main(int argc, char** argv) {

    //Adicionando entrada por linha de comando
    //Padrao instituido: argv[0] = Nome do programa
    //argv[1] = Nome Arquivo de Entrada
    //argv[2] = Tamanho do Arquivo de entrada (vetor de entrada) 
    //argv[3] = Nome do Arquivo de Saida
    //argv[4] = Tipo do quickSort (1 = tradicional),(2 = dualPivot)


    FILE *entrada; //Ponteiro que vai apontar para o arquivo de entrada
    FILE *saida; //Ponteiro que vai apontar para o arquivo de saida
    struct timeval tempo_inicial, tempo_final; //estrutura da biblioteca sys/time.h que armazena varios dados sobre o tempo
    int tamanho_vetor, op;
    double ti = 0, tf = 0, tempo = 0; //Tempo Inicial, Tempo Final e Tempo gasto (depois de calculados)
    char saida[100];
    relatorio *r = (relatorio*) malloc(sizeof (relatorio));

    //int op, tamanho_vetor; //op = variavel para armazenar opções/tamanho_vetor = guarda o tamanho do vetor
    //char entrada[100], saida[100];


    //FILE
    //srand(time(NULL));

    //printf("Digite o nome do arquivo\n");
    //scanf(" %[^\n]s", entrada);



    /*Pega o tamanho do vetor
    printf("Qual o tamanho do vetor?\n");
    scanf("%d", &tamanho_vetor);*/

    tamanho_vetor = atoi(argv[2]);
    int *v = (int*) malloc(tamanho_vetor * sizeof (int)); //Aloca o vetor dinamicamente por malloc

    //for (int i = 0; i < tamanho_vetor; i++)
    //  v[i] = tamanho_vetor - i;

    /*cria_arquivo(a, &entrada);
    escreveArquivo(a, &entrada, tamanho_vetor);
    lerArquivo(&entrada, v);
     */
    //MENU
    /*do {
        resetaStructRelatorio(r);
        printf("[1]Ordenar por DualPivot QuickSort (ordem crescente)\n");
        printf("[2]Ordenar por QuickSort Tradicional\n");
        printf("[3]Sair\n");
        scanf("%d", &op);
     */

    //printaVetor(v, tamanho_vetor);


    // printf("Digite o nome de arquivo de saida\n");
    //scanf(" %[^\n]s", saida);
    saida = argv[3];


    op = atoi(argv[4]);
    if (op == 2) {
        gettimeofday(&tempo_inicial, NULL); //Funcao preenche a estrutura com os dados do tempo corrente (usa tempo do sistema operacional)
        qSDualPivotCrescente(v, 0, tamanho_vetor, r); //chamada da funcao de ordenação DualPivot Quick Sort
        gettimeofday(&tempo_final, NULL); //Funcao preenche a estrutura com os dados do tempo corrente (usa tempo do sistema operacional)
        ti = (double) tempo_inicial.tv_usec + ((double) tempo_inicial.tv_sec * (1000000.0)); //utiliza o horario corrente da estrutura e converte para um double
        tf = (double) tempo_final.tv_usec + ((double) tempo_final.tv_sec * (1000000.0)); //utiliza o horario corrente da estrutura e converte para um double
        tempo = (tf - ti) / 1000; //Faz a diferença entre tempo inicial e final para saber o tempo corrente, ja convertendo em milésimos de segundo
        //printaVetor(v, tamanho_vetor);
        //printaStructRelatorio(r);
        //salvaArquivo(b, saida, tamanho_vetor, v);
    } else {
        gettimeofday(&tempo_inicial, NULL); //Funcao preenche a estrutura com os dados do tempo corrente (usa tempo do sistema operacional)
        quickSort(v, 0, tamanho_vetor, r); //chamada da funcao de ordenação QuickSort
        gettimeofday(&tempo_final, NULL); //Funcao preenche a estrutura com os dados do tempo corrente (usa tempo do sistema operacional)
        ti = (double) tempo_inicial.tv_usec + ((double) tempo_inicial.tv_sec * (1000000.0)); //utiliza o horario corrente da estrutura e converte para um double
        tf = (double) tempo_final.tv_usec + ((double) tempo_final.tv_sec * (1000000.0)); //utiliza o horario corrente da estrutura e converte para um double
        tempo = (tf - ti) / 1000; //Faz a diferença entre tempo inicial e final para saber o tempo corrente, ja convertendo em milésimos de segundo
        //printf("Digite o nome de arquivo de saida\n");
        //scanf(" %[^\n]s", saida);
        //printaVetor(v, tamanho_vetor);
        //printaStructRelatorio(r);
    }
    //salvaArquivo(b, saida, tamanho_vetor, v);                           

    return (EXIT_SUCCESS);
}


