#include <stdio.h>
#include "botao.h"
#include "tela.h"

void AcaoBotao1() {
    printf("Excluindo......\n");
}

void AcaoBotao2() {
    printf("Copiando arquivos .... \n");
}

int main () {
    void (*fpBotao1) (void) = AcaoBotao1;
    void (*fpBotao2) (void) = AcaoBotao2;

    Tela t = CriarTela(200, 100);

    Botao b = CriarBotao("Excluir arquivos", 17, "ABCDEF", 1, fpBotao1);
    RegistraBotaoTela(&t, b);

    b = CriarBotao("Copiar arquivos", 5, "EEE", 3, fpBotao2);
    RegistraBotaoTela(&t, b);

    OuvidorEventosTela(t);

    return 0;
}