#ifndef BST_H
#define BST_H

typedef struct NoBST {
    int chave;
    char conteudo;
    struct NoBST *esq;
    struct NoBST *dir;
} NoBST;

NoBST* criarNoBST(int valor, char cont);
NoBST* inserirBST(NoBST* raiz, int valor, char cont);
NoBST* buscarBST(NoBST* raiz, int valor);
void liberarBST(NoBST* raiz);

void imprimirPreFixado(NoBST* raiz);
void imprimirCentral(NoBST* raiz);
void imprimirPosFixado(NoBST* raiz);

void imprimeEmOrdemArquivo(NoBST* raiz, FILE* arquivo);

#endif