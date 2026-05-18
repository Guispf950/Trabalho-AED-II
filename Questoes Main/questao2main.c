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
    
    // Adiciona 10% de pacotes repetidos para simular a retransmissão
    int num_repetidos = len * 0.10; 
    if (num_repetidos == 0) num_repetidos = 1;  
    
    int total_pacotes = len + num_repetidos;
    
    // Vetor dinâmico de chaves
    int* chaves = (int*)malloc(total_pacotes * sizeof(int));
    if (!chaves) {
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }
    
    // Preenche com as chaves em ordem
    for (int i = 0; i < len; i++) {
        chaves[i] = i;
    }
    
    // Embaralha as chaves
    srand(time(NULL));
    embaralhar(chaves, len);
    
    // Adiciona os valores duplicados no final do vetor
    for (int i = 0; i < num_repetidos; i++) {
        int indice_aleatorio = rand_grande() % len;
        chaves[len + i] = chaves[indice_aleatorio]; //Selecionamos uma posicao aleatoria do vetor original(sem valores repetidos) 
                                                    // e repetimos esse valor no final do vetor
    }
    
    // Insercao na BST
    for (int i = 0; i < total_pacotes; i++) {
        int chave = chaves[i];
        char dado = mensagemTexto[chave]; //dado recebe o caractere correspondente a chave. Ou seja, o caractere da "mensagemTexto" na posicao da chave
        arvore = inserirBST(arvore, chave, dado);
    }
    
    // Escreve os dados (caracteres) no arquivo utilizando o caminhamento Em-ordem
    FILE* out = fopen("arquivo_montado.txt", "w");
    if (!out) {
        printf("Erro de I/O.\n");
        free(chaves);
        return 1;
    }
    
    imprimeEmOrdemArquivo(arvore, out);
    fclose(out);
    
    printf("Arquivo gerado: arquivo_montado.txt\n");
    
    liberarBST(arvore);
    free(chaves); 
    return 0;
}