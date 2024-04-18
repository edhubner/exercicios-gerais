#ifndef _LESAO_H
#define _LESAO_H

#include "constantes.h"

typedef struct {
    char id[TAM_ID_LESAO];
    char diag[TAM_DIAG_LESAO];
    char regiao[TAM_REGIAO_LESAO];
    int malig;
    char cartaoSUS[TAM_CARTAO_SUS];
} tLesao;

tLesao LerLesao();
void PrintLesao(tLesao les);

#endif