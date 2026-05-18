#ifndef VETOR_H
#define VETOR_H

typedef struct {
    int *dados;
    int tamanho;
} VetorTAD;

// Funções de Gerenciamento e Utilidade
VetorTAD* criar_vetor(int tamanho);
void free_vetor(VetorTAD *v);

void preencher_aleatorio_desordenado(VetorTAD *v);
void preencher_aleatorio_ordenado(VetorTAD *v);
void copiar_vetor(VetorTAD *origem, VetorTAD *destino);
int obter_valor_em(VetorTAD *v, int indice);

// Funções de Busca (Questões 1 e 2)
int busca_sequencial(VetorTAD *v, int alvo);
int busca_binaria(VetorTAD *v, int alvo);

// Algoritmos de Ordenação (Questão 3)
void bubble_sort(VetorTAD *v);
void insertion_sort(VetorTAD *v);
void selection_sort(VetorTAD *v);
void quick_sort(VetorTAD *v, int esq, int dir);
void merge_sort(VetorTAD *v, int esq, int dir);

#endif