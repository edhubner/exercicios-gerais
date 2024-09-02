
#include "receita.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct _Receita
{
    // Tem mais, isso é apenas para demostração
    char nomeMedicamento[50];
    int qtd;
};

Receita *criaReceita(char nomeMedicamento[50], int qtd)
{

    Receita *rec = (Receita *)malloc(sizeof(Receita));

    strcpy(rec->nomeMedicamento, nomeMedicamento);
    rec->qtd = qtd;

    return rec;
}

void desalocaReceita(void *rec)
{
    free(rec);
}

void imprimeNaTelaReceita(void *dado)
{
    Receita *r = (Receita *)dado;
    printf("Simulando impressao na tela:\n");
    printf("Nome do medicamento: %s\n", r->nomeMedicamento);
    printf("Quantidade: %d\n", r->qtd);
    printf("--------------------\n\n");
}

void imprimeEmArquivoReceita(void *dado, char *path)
{
    Receita *r = (Receita *)dado;
    printf("Simulando impressao em Arquivo:\n");
    printf("Path: %s\n", path);
    printf("Nome do medicamento: %s\n", r->nomeMedicamento);
    printf("Quantidade: %d\n", r->qtd);
    printf("--------------------\n\n");
}