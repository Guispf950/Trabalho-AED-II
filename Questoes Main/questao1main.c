#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

int main() {
    NoBST* arvore = NULL;
    
    int valores[20] = {50, 30, 70, 20, 40, 60, 80, 15, 25, 35, 45, 55, 65, 75, 85, 10, 5, 90, 95, 100};
    int i;

    for (i = 0; i < 20; i++) {
        arvore = inserirBST(arvore, valores[i], 'X'); 
    }

    printf("Caminhamento Pre-fixado:\n");
    imprimirPreFixado(arvore);
    printf("\n\n");

    printf("Caminhamento Central (Em ordem):\n");
    imprimirCentral(arvore);
    printf("\n\n");

    printf("Caminhamento Pos-fixado:\n");
    imprimirPosFixado(arvore);
    printf("\n\n");

    liberarBST(arvore);

    return 0;
}