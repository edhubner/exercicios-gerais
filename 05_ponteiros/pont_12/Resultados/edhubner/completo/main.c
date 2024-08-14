#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int Soma (int a, int b) {
    return a + b;
}

int Produto (int a, int b) {
    return a * b;
}

int main (void) {
    Vetor* v = (Vetor*) malloc(sizeof(Vetor));
    Operation op;

    LeVetor(v);
    //PrintVetor(v);

    op = Soma;    
    printf("Soma: %d\n", AplicarOperacaoVetor(v, op));
    op = Produto;
    printf("Produto: %d\n", AplicarOperacaoVetor(v, op));

    free(v);

    return 0;
}