#include <stdio.h>
#include "botao.h"
#include "tela.h"

void AcaoBotao1() {
    printf("- Botao de SALVAR dados ativado!\n");
}

void AcaoBotao2() {
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void AcaoBotao3() {
    printf("- Botao de OPCOES ativado!\n");
}

int main () {
    void (*fpBotao1) (void) = AcaoBotao1;
    void (*fpBotao2) (void) = AcaoBotao2;
    void (*fpBotao3) (void) = AcaoBotao3;

    Tela t = CriarTela(200, 100);

    Botao b = CriarBotao("Salvar", 12, "FFF", 1, fpBotao1);
    RegistraBotaoTela(&t, b);

    b = CriarBotao("Excluir", 18, "000", 1, fpBotao2);
    RegistraBotaoTela(&t, b);

    b = CriarBotao("Opcoes", 10, "FF0000", 2, fpBotao3);
    RegistraBotaoTela(&t, b);

    OuvidorEventosTela(t);

    return 0;
}