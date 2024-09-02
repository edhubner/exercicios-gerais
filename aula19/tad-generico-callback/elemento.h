

#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_

typedef struct Elemento Elemento;
typedef void (*func_ptr_exibeNaTela)(void *widget);
typedef void (*func_ptr_executaClick)(void *widget);

Elemento *criaElemento(void *widget, func_ptr_exibeNaTela exibeNaTela, func_ptr_executaClick executaClick);
void exibeNaTelaElemento(Elemento *e);
void executaClickElemento(Elemento *e);
void desalocaElemento(Elemento *e);

#endif