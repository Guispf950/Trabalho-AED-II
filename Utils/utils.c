#include <stdlib.h>
#include "utils.h"
#include <time.h> 

void embaralhar(int *vetor, int tamanho) {
    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand_grande() % (i + 1);
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

// Pega o tempo do computador (nanossegundos)
double obter_tempo_atual() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    // Converte para segundos 
    return ts.tv_sec + (ts.tv_nsec / 1e9);
}


int rand_grande() {
    return (rand() * 32768) + rand();
}