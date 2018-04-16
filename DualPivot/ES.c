#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lerArquivo(char *nomeArquivo, int *vet) {
    FILE *entrada;
    int i = 0;
    entrada = fopen(nomeArquivo, "r");
    if (entrada == NULL) {
        printf("Arquivo Vazio /n");
    }
    while (!feof(entrada)) {
        fscanf(entrada, "%d", &vet[i]);
        i++;
    }
}

//Cria um arquivo
void cria_arquivo(FILE *a, char *entrada) {
        if ((a = fopen(entrada, "a")) != NULL) {
            printf("Arquivo criado!\n");
            fclose(a);
        } else {
            printf("Houve um erro ao tentar criar o arquivo!\n");
            fclose(a);
            exit(1);
        }
}

//Printa o vetor na tela
void printa_vetor(int *v,int tamanho_vetor, FILE*a){
    char op;
    char nome[100];
    
    for(int i=0;i<tamanho_vetor;i++){
        printf("%d\n",v[i]);
    }

    printf("Digite o nome do arquivo para salvar a ordenacao:\n");
    scanf(" %[^\n]", nome);

    if ((a = fopen(nome, "a")) != NULL) {
        printf("Arquivo criado!\n");
    } else {
        printf("Houve um erro ao tentar criar o arquivo!\n");
        fclose(a);
        exit(1);
    }
    
    for (int j=0; j<tamanho_vetor;j++){
    fprintf(a, "%d\n", v[j]);
    }
    fclose(a);
return;
}

void escreveArquivo(FILE* a, char *entrada, int tamanho_vetor){
    int i;
    
    a = fopen(entrada, "a+");
    for (i=0;i<tamanho_vetor+1; i++){
        if (i==0) fprintf(a, "%d\n", tamanho_vetor);
        else fprintf(a, "%d\n", rand() % 500000);        
    }
    fclose(a);
}

void salvaArquivo(FILE* b, char *saida, int tamanho_vetor, int *v){
    int i;
    b=fopen(saida, "a+");
    for (i=0; i<tamanho_vetor+1; i++){
        if(i!=0) fprintf(b, "%d\n",v[i]);
    }
    fclose(b);
}
