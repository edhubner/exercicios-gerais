#include <stdio.h>
#include <string.h>
#include "campeonato.h"
#include "partidas.h"
#include "times.h"
#include "constantes.h"

tCampeonato LerCampeonato() {
    int flag = 1;
    char op;

    tCampeonato nba;
    nba.qtddPartidas = 0;
    nba.qtddTimes = 0;

    while(flag) {
        scanf("%c", &op);
        if (op == 'F') {
            nba.times[nba.qtddTimes] = LerTime();
            nba.qtddTimes++;
        }
        else if (op == 'P') {
            nba.partidas[nba.qtddPartidas] = LerPartida();
            nba.qtddPartidas++;
        }
        else if (op == 'E') {
            flag = 0;
            break;
        }
    }
    return nba;
}

void ExibeEstatisticas(tCampeonato nba) {
    int vitorias;
    int derrotas;
    int vitCasa;
    float aprov;
    int vitLeste = 0;
    int derLeste = 0;
    int vitOeste = 0;
    int derOeste = 0;
    
    for (int i = 0; i < nba.qtddTimes; i++) {
        vitorias = 0;
        derrotas = 0;
        vitCasa = 0;
        aprov = 0.0;

        for (int j = 0; j < nba.qtddPartidas; j++) {
            if (!strcmp(nba.times[i].nome, nba.partidas[j].perdedor)) {
                derrotas++;

                if(nba.times[i].conf[0] == 'L')
                    derLeste++;
                else
                    derOeste++;
            }
            else if (!strcmp(nba.times[i].nome, nba.partidas[j].vencedor)) {
                vitorias++;
                if (nba.partidas[j].foiVitoriaEmCasa)
                    vitCasa++;
                
                if(nba.times[i].conf[0] == 'L')
                    vitLeste++;
                else
                    vitOeste++;
            }
        }

        aprov = (float) vitorias * 100 / (vitorias + derrotas);
        printf("%s [C", nba.times[i].nome);
        printf("%c] %d %d %.2f %d %d\n", nba.times[i].conf[0], vitorias, derrotas, aprov, vitCasa, vitorias - vitCasa);
    }
    // Problema div 0!SS
    printf("LESTE %d %d %.2f\n", vitLeste, derLeste, ((float) vitLeste * 100 / (vitLeste + derLeste)));
    printf("OESTE %d %d %.2f\n", vitOeste, derOeste, ((float) vitOeste * 100 / (vitOeste + derOeste)));
}