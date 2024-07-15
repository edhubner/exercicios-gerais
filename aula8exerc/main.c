#include <stdio.h>
#include "campeonato.h"

int main () {
    tCampeonato nba = LerCampeonato();
    ExibeEstatisticas(nba);

    return 0;
}