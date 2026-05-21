#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "arvoreBinaria.h"
#include "vetor.h"
#include "utils.h"

int main() {
    int N = 1000000;
    
    printf("--- QUESTAO 3: VETOR vs ARVORE BINARIA DE PESQUISA ---\n");
    printf("Gerando %d elementos...\n", N);

    VetorTAD* v = criar_vetor(N);
    preencher_aleatorio_desordenado(v);

    NoBST* arvore = NULL;
    printf("Inserindo dados na Arvore...\n");

    for (int i = 0; i < N; i++) {
        arvore = inserirBST(arvore, v->dados[i], 'X'); // Como a arvore tem 2 campos (chave e conteudo),
                                                // o campo conteudo é preenchido com 'X' apenas para utilizar a
                                                // o mesmo TAD, já que o foco é comparar os valores inteiros (chaves)
    }

    printf("Ordenando o Vetor com QuickSort...\n"); //Ordena para realizar a busca binária depois
    quick_sort(v, 0, v->tamanho - 1);

    printf("\n=== ANALISE DE MEMORIA ===\n");
    printf("Vetor: ~%llu MB alocados.\n", (unsigned long long)(N * sizeof(int)) / (1024 * 1024));
    printf("Arvore: ~%llu MB alocados.\n", (unsigned long long)(N * sizeof(NoBST)) / (1024 * 1024));

    int chaves_busca[30];
    
    srand(time(NULL)); 
    
    for (int i = 0; i < 15; i++) {
        chaves_busca[i] = v->dados[rand_grande() % N]; 
    }
    for (int i = 15; i < 30; i++) {
        chaves_busca[i] = rand_grande(); 
    }

    
    double inicio, fim;
    double tempo_total_vetor = 0.0;
    double tempo_total_arvore = 0.0;

   printf("\n=== RESULTADOS DE DESEMPENHO (30 Buscas) ===\n");
    printf("%-10s | %-15s | %-15s | %-15s\n", "Busca No", "Chave", "Tempo Vetor (s)", "Tempo Arvore (s)");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < 30; i++) {
        int alvo = chaves_busca[i];
        double tempo_vetor_atual, tempo_arvore_atual;

        //Cronometrando Vetor
        inicio = obter_tempo_atual();
        busca_binaria(v, alvo);
        fim = obter_tempo_atual();
        tempo_vetor_atual = fim - inicio;
        tempo_total_vetor += tempo_vetor_atual;

        //Cronometrando Arvore
        inicio = obter_tempo_atual();
        buscarBST(arvore, alvo);
        fim = obter_tempo_atual();
        tempo_arvore_atual = fim - inicio;
        tempo_total_arvore += tempo_arvore_atual;

        // Imprime a linha da tabela com 9 casas decimais (%.9f) para manter a precisao
        printf("Busca %-4d | %-15d | %.9f     | %.9f\n", i + 1, alvo, tempo_vetor_atual, tempo_arvore_atual);
    }

    printf("--------------------------------------------------------------\n");
    printf("MEDIAS     |                 | %.9f     | %.9f\n", tempo_total_vetor / 30.0, tempo_total_arvore / 30.0);

    free_vetor(v);
    liberarBST(arvore);

    return 0;

}
