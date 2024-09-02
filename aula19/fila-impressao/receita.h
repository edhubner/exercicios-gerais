

#ifndef _RECEITA_H
#define _RECEITA_H

typedef struct _Receita Receita;

Receita *criaReceita(char nomeMedicamento[50], int qtd);
void desalocaReceita(void *rec);
void imprimeNaTelaReceita(void *dado);
void imprimeEmArquivoReceita(void *dado, char *path);

#endif