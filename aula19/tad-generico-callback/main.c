#include <stdio.h>
#include "tela.h"
#include "botao.h"

int main()
{

    Tela *t = criarTela(800, 600);
    Botao *btnSalvar = criarBotao("Salvar", 12, "00FF00");

    registraElementoTela(t, btnSalvar, exibeBotao, executaClickBotao);

    desenhaTela(t);

    ouvidorClickTela(t);

    desalocaTela(t);

    return 0;
}