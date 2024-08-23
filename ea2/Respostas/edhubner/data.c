#include <stdio.h>
#include <stdlib.h>
#include "data.h"

/*
Função que cria a estrutura Data (alocando memória), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
Data *leData() {
    Data* data = (Data*) malloc(sizeof(Data));
    scanf("%d/%d/%d", &data->dia, &data->mes, &data->ano);
    return data;
}

/*
Função que cria uma estrutura Data (alocando memória), inicializa os campos da estrutura
com os valores passados como parâmetro, e retorna o ponteiro para a estrutura criada.
*/
Data *criaData(int dia, int mes, int ano) {
    Data* data = (Data*) malloc(sizeof(Data));
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}

/*
Função que libera a memória alocada para a estrutura Data.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaData(Data *d) {
    if (d != NULL) {
        free(d);
    }
}

/*
Função que compara duas datas e retorna um valor inteiro que indica a diferença em anos.
Essa diferença deve ser calculada como nós calculamos a idade de uma pessoa. Ou seja, uma pessoa
que nasceu em 10/10/2000 no dia 15/09/2020 tem 19 anos.
*/
int calculaDiffAnosData(Data *d, Data *atual) {
    int anos = atual->ano - d->ano;

    if (atual->mes < d->mes) {
        anos--;
    }
    else if (atual->mes == d->mes) {
        if (atual->dia < d->dia)
            anos--;
    }

    return anos;
}

/*
Função que imprime a data no formato dd/mm/aaaa.
Não é necessário incluir zeros à esquerda.
*/
void imprimeData(Data *d) {
    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
}