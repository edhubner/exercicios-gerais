
#include <stdio.h>
#include <stdlib.h>
#include "tela.h"


struct Tela {
    int altura;
    int largura;
    Elemento *elemento;    
};

Tela* criarTela (int altura, int largura) {
    Tela *t = (Tela *)malloc(sizeof(Tela));
    t->altura = altura;
    t->largura = largura;             
    t->elemento = NULL;
    return t;
}

void registraElementoTela(Tela *t, void *widget, func_ptr_exibeNaTela exibeNaTela, func_ptr_executaClick executaClick) {
    Elemento *e = criaElemento(widget, exibeNaTela, executaClick);
    t->elemento = e;    
}

void desenhaTela (Tela *t) {
    printf("##################\n");    
    exibeNaTelaElemento(t->elemento);
    printf("##################\n");
}

void ouvidorClickTela(Tela *t) {
    int click;
    printf("- Digite o numero do elemento selecionado: ");
    scanf("%d", &click);
    if (click != 0){
        printf("AVISO: elemento nao reconhecido\n");
        exit(0);
    }
    executaClickElemento(t->elemento);
}

void desalocaTela(Tela *t) {    
    desalocaElemento(t->elemento);    
    free(t);
}