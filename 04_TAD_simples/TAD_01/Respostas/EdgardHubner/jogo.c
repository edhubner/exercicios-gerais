#include <stdio.h>
#include "jogador.h"
#include "tabuleiro.h"

typedef struct{
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;
    
} tJogo;

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo()
{
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    return jogo;
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo)
{
    int win = 0;
    if (VenceuJogador(jogo.jogador1, jogo.tabuleiro))
        win = 1;
    else if (VenceuJogador(jogo.jogador2, jogo.tabuleiro))
        win = 2;
    else
        win = 0;

    if (!TemPosicaoLivreTabuleiro(jogo.tabuleiro) ||  win)
    {
        if (win)
            printf("JOGADOR %d Venceu!\n", win);
        else
            printf("Empate!\n");
        
        return 1;
    }
    return 0;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    char op;
    printf("Jogar novamente? (s,n)\n");
    scanf("\n%c", &op);

    if (op == 'n' || op == 'N')
        return 0;
    else
        return 1;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo)
{
    tJogador jTemp = jogo.jogador1;

    while (1)
    {
        jogo.tabuleiro = JogaJogador(jTemp, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if (jTemp.id == jogo.jogador1.id)
            jTemp = jogo.jogador2;
        else
            jTemp = jogo.jogador1;

        if (AcabouJogo(jogo))
        {
            if (ContinuaJogo())
            {
                jogo.tabuleiro = CriaTabuleiro();
                jTemp = jogo.jogador1;
            }
            else
                break;
        }
    }
}