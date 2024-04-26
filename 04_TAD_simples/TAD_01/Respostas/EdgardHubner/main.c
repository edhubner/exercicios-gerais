#include <stdio.h>
#include "jogada.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogo.h"

int main (void)
{
    char op;
    tTabuleiro tab = CriaTabuleiro();
    tJogador j1 = CriaJogador(ID_JOGADOR_1);
    tJogador j2 = CriaJogador(ID_JOGADOR_2);
    int win = 0;

    tJogador temp = j1;                                                                       // teste

    //tJogada jogada;

    while (1)
    {
        //jogada = LeJogada();
        //ImprimeJogada(jogada);

        tab = JogaJogador(temp, tab);
        //tab = MarcaPosicaoTabuleiro(tab, temp, jogada.x, jogada.y);                     // quebra do TAD OPACO
        ImprimeTabuleiro(tab);

        if (temp.id == j1.id)                                                                  // teste
            temp = j2;
        else
            temp = j1;

        if (VenceuJogador(j1, tab))
            win = 1;
        else if (VenceuJogador(j2, tab))
            win = 2;
        else
            win = 0;

        if (!TemPosicaoLivreTabuleiro(tab) ||  win)
        {
            if (win)
                printf("Jogador %d venceu!!!!\n", win);
            else
                printf("Empate!\n");

            printf("Jogar novamente? (s,n)\n");
            scanf("\n%c", &op);

            if (op == 'n' || op == 'N')
                break;
            else
            {
                tab = CriaTabuleiro();
                temp = j1;
            }
        }
    }

    return 0;
}