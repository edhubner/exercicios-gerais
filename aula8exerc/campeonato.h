#ifndef _CAMPEONATO_H
#define _CAMPEONATO_H

#include "partidas.h"
#include "times.h"
#include "constantes.h"

typedef struct {
    tTime times[MAX_TIMES];
    tPartida partidas[MAX_PARTIDAS];
    int qtddTimes;
    int qtddPartidas;
} tCampeonato;

tCampeonato LerCampeonato();

void ExibeEstatisticas(tCampeonato nba);

#endif