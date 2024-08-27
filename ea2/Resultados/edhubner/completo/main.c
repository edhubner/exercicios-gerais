#include <stdio.h>
#include "gerenciador.h"

int main(void) {
    Gerenciador* g = criaGerenciador();
    preencheBancoPacientesGerenciador(g);
    imprimeRelatorioGerenciador(g);
    liberaGerenciador(g);
    return 0;
}