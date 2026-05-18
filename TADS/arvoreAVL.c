#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"


int altura(NoAVL *N) {
    if (N == NULL) return 0;
    return N->altura;
}

int maior(int a, int b) {
    if(a > b) return a;
    else return b;

}

NoAVL* rotacaoDireita(NoAVL *y) {
    NoAVL *x = y->esq;
    NoAVL *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = maior(altura(y->esq), altura(y->dir)) + 1;
    x->altura = maior(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

NoAVL* rotacaoEsquerda(NoAVL *x) {
    NoAVL *y = x->dir;
    NoAVL *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = maior(altura(x->esq), altura(x->dir)) + 1;
    y->altura = maior(altura(y->esq), altura(y->dir)) + 1;

    return y;
}

int obterBalanceamento(NoAVL *N) {
    if (N == NULL) return 0;
    return altura(N->esq) - altura(N->dir);
}

NoAVL* criarNoAVL(int valor, char cont) {
    NoAVL* novo = (NoAVL*)malloc(sizeof(NoAVL));
    if (novo) {
        novo->chave = valor;
        novo->conteudo = cont;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->altura = 1; 
    }
    return novo;
}

NoAVL* inserirAVL(NoAVL* no, int valor, char cont) {
    if (no == NULL) return criarNoAVL(valor, cont);

    if (valor < no->chave)
        no->esq = inserirAVL(no->esq, valor, cont);
    else if (valor > no->chave)
        no->dir = inserirAVL(no->dir, valor, cont);
    else
        return no; 

    no->altura = 1 + maior(altura(no->esq), altura(no->dir));

    int balanco = obterBalanceamento(no);

    if (balanco > 1 && valor < no->esq->chave)
        return rotacaoDireita(no);

    if (balanco < -1 && valor > no->dir->chave)
        return rotacaoEsquerda(no);

    if (balanco > 1 && valor > no->esq->chave) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    if (balanco < -1 && valor < no->dir->chave) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no;
}

NoAVL* buscarAVL(NoAVL* raiz, int valor) {
    NoAVL* atual = raiz;
    
    while (atual != NULL) {
        if (valor == atual->chave) {
            return atual; // Encontrou
        } else if (valor < atual->chave) {
            atual = atual->esq; 
        } else {
            atual = atual->dir; 
        }
    }
    
    return NULL; // Não encontrou
}
void liberarAVL(NoAVL* raiz) {
    if (raiz != NULL) {
        liberarAVL(raiz->esq);
        liberarAVL(raiz->dir);
        free(raiz);
    }
}