#include "vetor.h"
#include <stdlib.h>
#include <string.h>
#include <utils.h>

//GERENCIAMENTO DO TAD 

VetorTAD* criar_vetor(int tamanho) {
    VetorTAD *v = (VetorTAD*) malloc(sizeof(VetorTAD));
    v->dados = (int*) malloc(tamanho * sizeof(int));
    v->tamanho = tamanho;
    return v;
}

void free_vetor(VetorTAD *v) {
    if (v != NULL) {
        free(v->dados);
        free(v);
    }
}


void preencher_aleatorio_desordenado(VetorTAD *v) {
    for (int i = 0; i < v->tamanho; i++) {
        v->dados[i] = rand_grande();
    }
}

void preencher_aleatorio_ordenado(VetorTAD *v) {
    int valor_atual = 0;
    for (int i = 0; i < v->tamanho; i++) {
        v->dados[i] = valor_atual;
        valor_atual += (rand_grande() % 10) + 1;
    }
}

void copiar_vetor(VetorTAD *origem, VetorTAD *destino) {
    memcpy(destino->dados, origem->dados, origem->tamanho * sizeof(int));
}

int obter_valor_em(VetorTAD *v, int indice) {
    if (indice >= 0 && indice < v->tamanho) {
        return v->dados[indice];
    }
    return -1;
}

//BUSCAS

int busca_sequencial(VetorTAD *v, int alvo) {
    for (int i = 0; i < v->tamanho; i++) {
        if (v->dados[i] == alvo) return i;
    }
    return -1;
}

int busca_binaria(VetorTAD *v, int alvo) {
    int esq = 0, dir = v->tamanho - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (v->dados[meio] == alvo) return meio;
        else if (v->dados[meio] < alvo) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

//ORDENAÇÃO (AUXILIARES)

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//ORDENAÇÃO (ALGORITMOS)

void bubble_sort(VetorTAD *v) {
    for (int i = 0; i < v->tamanho - 1; i++) {
        for (int j = 0; j < v->tamanho - i - 1; j++) {
            if (v->dados[j] > v->dados[j + 1]) 
                trocar(&v->dados[j], &v->dados[j + 1]);
        }
    }
}

void insertion_sort(VetorTAD *v) {
    for (int i = 1; i < v->tamanho; i++) {
        int chave = v->dados[i];
        int j = i - 1;
        while (j >= 0 && v->dados[j] > chave) {
            v->dados[j + 1] = v->dados[j];
            j--;
        }
        v->dados[j + 1] = chave;
    }
}

void selection_sort(VetorTAD *v) {
    for (int i = 0; i < v->tamanho - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < v->tamanho; j++) {
            if (v->dados[j] < v->dados[min_idx]) 
                min_idx = j;
        }
        trocar(&v->dados[min_idx], &v->dados[i]);
    }
}

void quick_sort(VetorTAD *v, int esq, int dir) {
    if (esq < dir) {
        int pivo = v->dados[(esq + dir) / 2];
        int i = esq, j = dir;
        while (i <= j) {
            while (v->dados[i] < pivo) i++;
            while (v->dados[j] > pivo) j--;
            if (i <= j) {
                trocar(&v->dados[i], &v->dados[j]);
                i++; j--;
            }
        }
        quick_sort(v, esq, j);
        quick_sort(v, i, dir);
    }
}

void intercalar(VetorTAD *v, int esq, int meio, int dir) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = v->dados[esq + i];
    for (int j = 0; j < n2; j++) R[j] = v->dados[meio + 1 + j];
    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) v->dados[k++] = L[i++];
        else v->dados[k++] = R[j++];
    }
    while (i < n1) v->dados[k++] = L[i++];
    while (j < n2) v->dados[k++] = R[j++];
    free(L); free(R);
}

void merge_sort(VetorTAD *v, int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        merge_sort(v, esq, meio);
        merge_sort(v, meio + 1, dir);
        intercalar(v, esq, meio, dir);
    }
}