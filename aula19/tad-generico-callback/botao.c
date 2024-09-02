
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "botao.h"


struct Botao {
    char texto[MAX_TAM_TEXTO];
    int tamFonte;
    char corHex[7];    
};

void setarTexto(Botao *b, char *novoTexto) {
    if (strlen(novoTexto) > MAX_TAM_TEXTO) {
        printf("-ERRO: texto do botao e maior do que o permitido\n");
        exit(1);
    }
    strcpy(b->texto, novoTexto);
}

void setarTamFonte(Botao *b, int novoTamFonte) {
    if (novoTamFonte <= 0) {
        printf("-ERRO: o tamanho da fonte deve ser maior do que zero\n");
        exit(1);
    }
    b->tamFonte = novoTamFonte;
}

void setarCor(Botao *b, char *novaCor) {
    strcpy(b->corHex, novaCor);
}

Botao* criarBotao(char *texto, int tamFonte, char *cor) {
    Botao *b = (Botao *)malloc(sizeof(Botao));
    setarTexto(b, texto);
    setarCor(b, cor);
    setarTamFonte(b, tamFonte);    
    return b;
}

void exibeBotao(void *widget) {
    Botao *b = (Botao *)widget;
    printf("-------------\n");
    printf("- Botao:\n");
    printf("(%s | %s | %d)\n", b->texto, b->corHex, b->tamFonte);
    printf("-------------\n");
}

void executaClickBotao(void *widget) {
    Botao *b = (Botao *)widget;
    printf("- Botao clicado: %s\n", b->texto);
}

void desalocaBotao(Botao *b) {
    free(b);
}