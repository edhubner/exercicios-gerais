

#ifndef _BOTAO_H
#define _BOTAO_H

#define MAX_TAM_TEXTO 30
typedef struct Botao Botao;

Botao *criarBotao(char *texto, int tamFonte, char *cor);
void exibeBotao(void *widget);
void executaClickBotao(void *widget);
void desalocaBotao(Botao *b);

#endif