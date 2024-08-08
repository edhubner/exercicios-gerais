#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "botao.h"

/**
 * @brief Define o texto exibido no botão especificado se o novo texto for menor do que o tamanho máximo permitido.
 * se o novo texto for maior do que o tamanho máximo permitido, o programa é encerrado.
 * 
 * @param b Ponteiro para o botão que terá o texto definido.
 * @param novoTexto Novo texto a ser exibido no botão.
 */
void SetarTexto(Botao *b, char *novoTexto) {
    if (strlen(novoTexto) < MAX_TAM_TEXTO)
        strcpy(b->texto, novoTexto);
    else
        exit(1);
}

/**
 * @brief Define o tamanho da fonte do texto exibido no botão especificado se o novo tamanho for maior do que zero.
 * se o novo tamanho for menor ou igual a zero, o programa é encerrado.
 * 
 * @param b Ponteiro para o botão que terá o tamanho da fonte definido.
 * @param novoTamFonte Novo tamanho da fonte a ser definido.
 */
void SetarTamFonte(Botao *b, int novoTamFonte) {
    if (novoTamFonte > 0)
        b->tamFonte = novoTamFonte;
    else
        exit(2);
}

/**
 * @brief Define a cor do botão especificado.
 * 
 * @param b Ponteiro para o botão que terá a cor definida.
 * @param novaCor Nova cor a ser definida em formato hexadecimal.
 */
void SetarCor(Botao *b, char *novaCor) {
    strcpy(b->corHex, novaCor);
}

/**
 * @brief Define o tipo de evento que o botão especificado pode receber se o novo tipo for válido.
 * 
 * @param b Ponteiro para o botão que terá o tipo de evento definido.
 * @param novoTipo Novo tipo de evento a ser definido.
 */
void SetarTipo(Botao *b, int novoTipo) {
    if (novoTipo == CLICK || novoTipo == HOVER || novoTipo == LONGO_CLICK)
        b->tipo = novoTipo;    
}

/**
 * @brief Cria um novo botão com as características especificadas.
 * 
 * @param texto Texto a ser exibido no botão.
 * @param tamFonte Tamanho da fonte do texto exibido no botão.
 * @param cor Cor do botão em formato hexadecimal.
 * @param tipo Tipo de evento que o botão pode receber.
 * @param executa Função que será executada quando o botão for clicado.
 * @return Botao Retorna o botão criado.
 */
Botao CriarBotao(char *texto, int tamFonte, char *cor, int tipo, void (*executa)(void)) {
    Botao b;

    strcpy(b.texto, texto);
    b.tamFonte = tamFonte;
    strcpy(b.corHex, cor);
    b.tipo = tipo;
    b.executa = executa;

    return b;
}

/**
 * @brief Executa a função associada ao botão especificado de acordo com o tipo de evento que o botão pode receber.
 * Se o tipo de evento for inválido, o programa é encerrado.
 * 
 * @param b Botão que terá sua função executada.
 */
void ExecutaBotao(Botao b) {
    b.executa();
}

/**
 * @brief Desenha o botão especificado na posição especificada na tela.
 * 
 * @param b Botão a ser desenhado.
 * @param idx Índice do botão na tela em que será desenhado.
 */
void DesenhaBotao(Botao b, int idx) {
    printf("-------------\n- Botao [%d]:\n(%s | %s | %d | %d)\n-------------\n", idx, b.texto, b.corHex, b.tamFonte, b.tipo);
}