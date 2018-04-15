#ifndef ES_H
#define ES_H

void lerArquivo(FILE* a, int *v);
void cria_arquivo(FILE *a, char *entrada);
void printa_vetor(int *v, int tamanho_vetor, FILE* a);
void escreveArquivo(FILE* a, char *entrada, int tamanho_vetor);
void salvaArquivo(FILE*b, char *saida, int tamanho_vetor, int *v);


#endif /* ES_H */
