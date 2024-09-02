#ifndef _TELA_H
#define _TELA_H

#include "elemento.h"

#define MAX_ELEMENTOS 10
typedef struct Tela Tela;
Tela *criarTela(int altura, int largura);
void registraElementoTela(Tela *t, void *widget, func_ptr_exibeNaTela exibeNaTela, func_ptr_executaClick executaClick);
void desenhaTela(Tela *t);
void ouvidorClickTela(Tela *t);
void desalocaTela(Tela *t);

#endif