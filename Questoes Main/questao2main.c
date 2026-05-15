#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvoreBinaria.h" 
#include "utils.h"

int main() {
    NoBST* arvore = NULL;
    
    char mensagemTexto[] = "TRABALHO DE AED2 - Questão 2 - PACOTES DE TEXTO PARA TESTE DE ARVORE BINARIA DE BUSCA";
    int len = strlen(mensagemTexto);
    
    // Adiciona ~10% de pacotes repetidos para simular retransmissão
    int num_repetidos = len * 0.10; 
    if (num_repetidos == 0) num_repetidos = 1; 
    
    int total_pacotes = len + num_repetidos;
    
    // Alocação dinâmica do vetor de chaves
    int* chaves = (int*)malloc(total_pacotes * sizeof(int));
    if (!chaves) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }
    
    // Preenche com as chaves em ordem
    for (int i = 0; i < len; i++) {
        chaves[i] = i;
    }
    
    // Inicializa a semente randômica e embaralha as chaves
    srand(time(NULL));
    embaralhar(chaves, len);
    
    // Adiciona as duplicatas no final do vetor
    for (int i = 0; i < num_repetidos; i++) {
        int indice_aleatorio = rand() % len;
        chaves[len + i] = chaves[indice_aleatorio];
    }
    
    // Insercao na BST
    for (int i = 0; i < total_pacotes; i++) {
        int chave = chaves[i];
        char dado = mensagemTexto[chave];
        arvore = inserirBST(arvore, chave, dado);
    }
    
    // Gravacao em disco com caminhamento In-Order
    FILE* out = fopen("arquivo_montado.txt", "w");
    if (!out) {
        printf("Erro de I/O.\n");
        free(chaves);
        return 1;
    }
    
    imprimeEmOrdemArquivo(arvore, out);
    fclose(out);
    
    printf("Arquivo gerado: arquivo_montado.txt\n");
    
    // Limpeza de memoria
    liberarBST(arvore);
    free(chaves); 
    return 0;
}