#ifndef _PARTIDAS_H
#define _PARTIDAS_H

#include "constantes.h"

typedef struct {
    char vencedor[TAM_TIME];
    char perdedor[TAM_TIME];
    int foiVitoriaEmCasa;
} tPartida;

tPartida LerPartida();

void ImprimePartida(tPartida partida);

#endif