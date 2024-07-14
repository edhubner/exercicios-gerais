#ifndef _TIMES_H
#define _TIMES_H

#include "constantes.h"

typedef struct {
    char nome[TAM_TIME];
    char conf[TAM_CONF];
} tTime;

tTime LerTime();

void ImprimeTime (tTime time);

#endif