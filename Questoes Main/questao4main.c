#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvoreBinaria.h"
#include "arvoreAVL.h"
#include "utils.h"


int main() {
    int N = 1000000;
    int* valores = (int*)malloc(N * sizeof(int));
    
    // Insere 1 milhao de numeros aleatorios no vetor que sera utilizado para criar as arvores
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        valores[i] = rand_grande(); 
    }

    printf("--- QUESTAO 4: ARVORE AVL vs ARVORE BINARIA DE PESQUISA ---\n\n");

    NoBST* ultima_bst = NULL;
    NoAVL* ultima_avl = NULL;
    double inicio, fim;

    // Cria 10 arvores de cada tipo (AVL e BST)
    for (int rodada = 1; rodada <= 10; rodada++) {
        // Embaralha o array em cada rodada
        embaralhar(valores, N);
        
        printf("--- RODADA %d ---\n", rodada);

        //Cria a BST e mede o tempo
        NoBST* bst = NULL;
        inicio = obter_tempo_atual();
        for (int i = 0; i < N; i++) {
            bst = inserirBST(bst, valores[i], 'X');
        }
        fim = obter_tempo_atual();
        double tempo_bst = fim - inicio;
        int alt_bst = alturaBST(bst);
        printf("BST -> Tempo Criacao: %.6f s | Altura: %d\n", tempo_bst, alt_bst);

        //Cria a AVL e mede o tempo
        NoAVL* avl = NULL;
        inicio = obter_tempo_atual();
        for (int i = 0; i < N; i++) {
            avl = inserirAVL(avl, valores[i], 'X');
        }
        fim = obter_tempo_atual();
        double tempo_avl = fim - inicio;
        int alt_avl;
        if (avl != NULL) alt_avl = avl->altura;
            else alt_avl = 0;
        printf("AVL -> Tempo Criacao: %.6f s | Altura: %d\n\n", tempo_avl, alt_avl);

        // Limpa a memoria e deixa só a ultima AVL e BST para realizar as buscas
        if (rodada < 10) {
            liberarBST(bst);
            liberarAVL(avl);
        } else {
            ultima_bst = bst;
            ultima_avl = avl;
        }
    }

    // Buscas nas arvores
    printf("=== TESTE DE BUSCA (30 Consultas na Arvore da Rodada 10) ===\n");
    int chaves_busca[30];
    
    // 15 chaves que existem na arvore
    for (int i = 0; i < 15; i++) {
        chaves_busca[i] = valores[rand() % N]; 
    }
    // 15 chaves que podem ou não existir na arvore  
    for (int i = 15; i < 30; i++) {
        chaves_busca[i] = rand_grande(); 
    }

    double tempo_busca_bst_total = 0.0;
    double tempo_busca_avl_total = 0.0;

    printf("\n%-10s | %-15s | %-15s | %-15s\n", "Busca No", "Chave", "Tempo BST (s)", "Tempo AVL (s)");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < 30; i++) {
        int alvo = chaves_busca[i];
        double tempo_bst_atual, tempo_avl_atual;

        //Busca na BST e mede o tempo
        inicio = obter_tempo_atual();
        buscarBST(ultima_bst, alvo);
        fim = obter_tempo_atual();
        tempo_bst_atual = fim - inicio;
        tempo_busca_bst_total += tempo_bst_atual;

        //Busca na AVL e mede o tempo
        inicio = obter_tempo_atual();
        buscarAVL(ultima_avl, alvo);
        fim = obter_tempo_atual();
        tempo_avl_atual = fim - inicio;
        tempo_busca_avl_total += tempo_avl_atual;

        // Imprime a linha da tabela individual
        printf("Busca %-4d | %-15d | %.9f     | %.9f\n", i + 1, alvo, tempo_bst_atual, tempo_avl_atual);
    }

    printf("--------------------------------------------------------------\n");
    printf("MEDIAS     |                 | %.9f     | %.9f\n", tempo_busca_bst_total / 30.0, tempo_busca_avl_total / 30.0);

    liberarBST(ultima_bst);
    liberarAVL(ultima_avl);
    free(valores);

    return 0;
}