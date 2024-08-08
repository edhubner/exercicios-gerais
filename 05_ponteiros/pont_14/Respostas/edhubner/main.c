#include <stdio.h>
#include "botao.h"

void Botao2 () {
    printf("Acao do Botao 2\n");
}


int main () {
    void (*fpBotao2) (void) = Botao2;
    Botao b = CriarBotao("Testes", 17, "ABCDEF", 1, fpBotao2);
    DesenhaBotao(b, 2);
    SetarTexto(&b, "novoTeXto");
    SetarCor(&b, "FFF");
    SetarTamFonte(&b, 5);
    SetarTipo(&b, 2);
    DesenhaBotao(b, 3);
    return 0;
}