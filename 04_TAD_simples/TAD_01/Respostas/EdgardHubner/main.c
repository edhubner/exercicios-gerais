#include <stdio.h>
#include "jogada.h"
#include "tabuleiro.h"
#include "jogador.h"
#include "jogo.h"

int main (void)
{
    tJogo jogo = CriaJogo();
    ComecaJogo(jogo);
    return 0;
}