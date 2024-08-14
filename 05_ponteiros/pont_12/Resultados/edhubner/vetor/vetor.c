#include <stdio.h>
#include "vetor.h"

/**
 * Lê um vetor da entrada padrão.
 * 
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor) {
    scanf("%d", &vetor->tamanhoUtilizado);
    for (int i = 0; i < vetor->tamanhoUtilizado; i++) {
        scanf("%d", &vetor->elementos[i]);
    }
}

/**
 * Aplica uma operação em um vetor.
 * 
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
*/
int AplicarOperacaoVetor(Vetor *vetor, Operation op) {
    // Verifica se o vetor esta vazio ou se tem apenas 1 elemento
    if (vetor->tamanhoUtilizado <= 0)
        return 0;
    else if (vetor->tamanhoUtilizado == 1)
        return vetor->elementos[0];
    
    int resultado = op(vetor->elementos[0], vetor->elementos[1]);

    for (int i = 2; i < vetor->tamanhoUtilizado; i++) {
        resultado = op(resultado, vetor->elementos[i]);
    }
    return resultado;
}

void PrintVetor(Vetor* v) {
    printf("[");
    for (int i = 0; i < v->tamanhoUtilizado; i++) {
        printf("%d ", v->elementos[i]);
    }
    printf("]\n");
}