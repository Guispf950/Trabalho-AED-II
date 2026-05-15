#include <stdlib.h>
#include "utils.h"
#include <time.h> 

void embaralhar(int *vetor, int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

// Pega o tempo do computador com precisao extrema (nanossegundos)
double obter_tempo_atual() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    // Converte tudo para segundos e junta as duas partes do relogio
    return ts.tv_sec + (ts.tv_nsec / 1e9);
}


