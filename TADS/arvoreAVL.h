#ifndef AVL_H
#define AVL_H

typedef struct NoAVL {
    int chave;
    char conteudo;
    int altura;
    struct NoAVL *esq;
    struct NoAVL *dir;
} NoAVL;

NoAVL* criarNoAVL(int valor, char cont);
NoAVL* inserirAVL(NoAVL* no, int valor, char cont);
NoAVL* buscarAVL(NoAVL* raiz, int valor);
void liberarAVL(NoAVL* raiz);

#endif