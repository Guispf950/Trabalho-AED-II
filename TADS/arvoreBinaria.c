#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

NoBST* criarNoBST(int valor, char cont) {
    NoBST* novo = (NoBST*)malloc(sizeof(NoBST));
    if (novo) {
        novo->chave = valor;
        novo->conteudo = cont;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}


NoBST* inserirBST(NoBST* raiz, int valor, char cont) {
    // Se a árvore estiver vazia, o novo nó é a raiz
    if (raiz == NULL) {
        return criarNoBST(valor, cont);
    }

    NoBST* atual = raiz;
    NoBST* pai = NULL;

    // Desce na árvore até encontrar uma folha (NULL) ou achar o mesmo valor
    while (atual != NULL) {
        pai = atual; // Guarda o ponteiro do nó acima
        
        if (valor == atual->chave) {
            // Se a chave já existe ignoramos o dado duplicado
            return raiz; 
        } else if (valor < atual->chave) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    // Cria o nó após achar a posição correta
    NoBST* novo = criarNoBST(valor, cont);

    // O ponteiro do nó pai aponta para esse novo nó 
    if (valor < pai->chave) {
        pai->esq = novo;
    } else {
        pai->dir = novo;
    }

    return raiz;
}


NoBST* buscarBST(NoBST* raiz, int valor) {
    NoBST* atual = raiz;
    
    while (atual != NULL) {
        if (valor == atual->chave) {
            return atual; // Encontrou
        } else if (valor < atual->chave) {
            atual = atual->esq; 
        } else {
            atual = atual->dir; 
        }
    }
    
    return NULL; // Chegou numa folha e não encontrou
}

void liberarBST(NoBST* raiz) {
    if (raiz != NULL) {
        liberarBST(raiz->esq);
        liberarBST(raiz->dir);
        free(raiz);
    }
}

void imprimirPreFixado(NoBST* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        imprimirPreFixado(raiz->esq);
        imprimirPreFixado(raiz->dir);
    }
}

void imprimirCentral(NoBST* raiz) {
    if (raiz != NULL) {
        imprimirCentral(raiz->esq);
        printf("%d ", raiz->chave);
        imprimirCentral(raiz->dir);
    }
}

void imprimirPosFixado(NoBST* raiz) {
    if (raiz != NULL) {
        imprimirPosFixado(raiz->esq);
        imprimirPosFixado(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

void imprimeEmOrdemArquivo(NoBST* raiz, FILE* arquivo) {
    if (raiz != NULL) {
        imprimeEmOrdemArquivo(raiz->esq, arquivo);
        fputc(raiz->conteudo, arquivo); 
        imprimeEmOrdemArquivo(raiz->dir, arquivo);
    }
}

int alturaBST(NoBST* raiz) {
    if (raiz == NULL) return 0;
    int altEsq = alturaBST(raiz->esq);
    int altDir = alturaBST(raiz->dir);
    if(altEsq > altDir){
        return altEsq + 1;
    } else{
        return altDir + 1;
    }
}