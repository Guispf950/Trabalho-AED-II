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
    if (raiz == NULL) {
        return criarNoBST(valor, cont);
    }
    if (valor < raiz->chave) {
        raiz->esq = inserirBST(raiz->esq, valor, cont);
    } else if (valor > raiz->chave) {
        raiz->dir = inserirBST(raiz->dir, valor, cont);
    }
    return raiz;
}

NoBST* buscarBST(NoBST* raiz, int valor) {
    if (raiz == NULL || raiz->chave == valor) {
        return raiz;
    }
    if (valor < raiz->chave) {
        return buscarBST(raiz->esq, valor);
    }
    return buscarBST(raiz->dir, valor);
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
