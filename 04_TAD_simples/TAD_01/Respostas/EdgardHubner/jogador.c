#include <stdio.h>
#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;

    while (1)
    {
        printf("Jogador %d\nDigite uma posicao (x e y):", jogador.id);
        jogada = LeJogada();
        
        if(!EhPosicaoValidaTabuleiro(jogada.x, jogada.y))
            printf("\nPosicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", jogada.x, jogada.y);
        else if(!EstaLivrePosicaoTabuleiro(tabuleiro, jogada.x, jogada.y))
            printf("\nPosicao invalida (OCUPADA - [%d,%d] )!\n", jogada.x, jogada.y);
        else
        {
            ImprimeJogada(jogada);
            break;
        }
    }

    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    return tabuleiro;
}

/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    char peca;
    int cont = 0;

    if (jogador.id == ID_JOGADOR_1)
        peca = tabuleiro.peca1;
    else
        peca = tabuleiro.peca2;

    // Verifica se há vencendor nas linhas
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO - 1; j++)
        {
            if ((tabuleiro.posicoes[i][j] == peca) && 
                (tabuleiro.posicoes[i][j + 1]) == peca)
                cont++;
        }
        if (cont == TAM_TABULEIRO - 1)
            return 1;
        else
            cont = 0;
    }

    // Verifica se há vencendor nas colunas
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO - 1; j++)
        {
            if ((tabuleiro.posicoes[j][i] == peca) && 
                (tabuleiro.posicoes[j + 1][i]) == peca)
                cont++;
        }
        if (cont == TAM_TABULEIRO - 1)
            return 1;
        else
            cont = 0;
    }

    // Verifica se há vencendor na diagonal principal
    for (int i = 0; i < TAM_TABULEIRO - 1; i++)
    {
        if ((tabuleiro.posicoes[i][i] == peca) &&
            (tabuleiro.posicoes[i + 1][i + 1]) == peca)
            cont++;
    }
    if (cont == TAM_TABULEIRO - 1)
        return 1;
    else
        cont = 0;

    // Verifica se há vencendor na diagonal secundaria
    for (int i = 0; i < TAM_TABULEIRO - 1; i++)
    {
        if ((tabuleiro.posicoes[i][TAM_TABULEIRO - i - 1] == peca) &&
            (tabuleiro.posicoes[i + 1][TAM_TABULEIRO - i - 2]) == peca)
            cont++;
    }
    if (cont == TAM_TABULEIRO - 1)
        return 1;
    else
        cont = 0;

    return 0;
}