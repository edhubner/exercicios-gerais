#include <stdio.h>
#include "jogada.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogo.h"

int main (void)
{
    int temp = 1;                                                                       // teste
    char op;
    tTabuleiro tab = CriaTabuleiro();
    tJogada jogada;

    while (1)
    {
        jogada = LeJogada();
        //ImprimeJogada(jogada);

        tab = MarcaPosicaoTabuleiro(tab, temp, jogada.x, jogada.y);                     // quebra do TAD OPACO
        ImprimeTabuleiro(tab);

        printf("Jogar novamente? (s,n)\n");
        scanf("\n%c", &op);

        if (op == 'n' || op == 'N')
            break;

        if (temp == 1)                                                                  // teste
            temp = 2;
        else
            temp = 1;        
    }

    return 0;
}