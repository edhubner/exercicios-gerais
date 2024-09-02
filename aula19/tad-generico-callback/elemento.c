
#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

struct Elemento {
    void *widget;
    func_ptr_exibeNaTela exibeNaTela;
    func_ptr_executaClick executaClick;
};

Elemento *criaElemento(void *widget, func_ptr_exibeNaTela exibeNaTela, func_ptr_executaClick executaClick) {
    Elemento *e = (Elemento *)malloc(sizeof(Elemento));
    e->widget = widget;
    e->executaClick = executaClick;
    e->exibeNaTela = exibeNaTela;
    return e;
}

void exibeNaTelaElemento(Elemento *e) {
    e->exibeNaTela(e->widget);
}

void executaClickElemento(Elemento *e) {
    e->executaClick(e->widget);
}

void desalocaElemento(Elemento *e) {    
    free(e);
}