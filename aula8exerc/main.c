#include <stdio.h>
#include "times.h"
#include "partidas.h"

int main () {
    tTime time = LerTime();
    ImprimeTime(time);

    tPartida partida = LerPartida();
    ImprimePartida(partida);

    return 0;
}