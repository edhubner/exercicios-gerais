#include <stdio.h>
#include <string.h>
#include "partidas.h"

tPartida LerPartida() {
    tPartida partida;
    char timeFora[TAM_TIME];
    char timeCasa[TAM_TIME];
    int ptsFora;
    int ptsCasa;

    scanf("%s @ %s %d %d", timeFora, timeCasa, &ptsFora, &ptsCasa);

    if (ptsFora > ptsCasa) {
        strcpy(partida.vencedor, timeFora);
        strcpy(partida.perdedor, timeCasa);
        partida.foiVitoriaEmCasa = 0;
    }
    else {
        strcpy(partida.vencedor, timeCasa);
        strcpy(partida.perdedor, timeFora);
        partida.foiVitoriaEmCasa = 1;
    }

    return partida;
}

void ImprimePartida(tPartida partida) {
    printf("Vencedor: %s\nPerdedor: %s\nEm Casa? %d\n", partida.vencedor, partida.perdedor, partida.foiVitoriaEmCasa);
}
