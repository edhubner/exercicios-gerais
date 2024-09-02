
#include <stdlib.h>
#include "documento.h"

// Esse é o documento genérico, que pode alocar qualquer um dos tipos de documentos (receita, biopsia, etc)
struct _Documento
{
    void *dado;
    func_ptr_imprimeNaTela imprimeNaTela;
    func_ptr_imprimeEmArquivo ImprimeEmArquivo;
    func_ptr_desaloca desaloca;
};

Documento *criaDocumento(void *dado, func_ptr_imprimeNaTela imprimeNaTela, func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                         func_ptr_desaloca desaloca)
{
    Documento *d = (Documento *)malloc(sizeof(Documento));
    d->dado = dado;
    d->imprimeNaTela = imprimeNaTela;
    d->ImprimeEmArquivo = ImprimeEmArquivo;
    d->desaloca = desaloca;
    return d;
}

void desalocaDocumento(Documento *d)
{
    d->desaloca(d->dado);
    free(d);
}

void imprimeNaTelaDocumento(Documento *d)
{
    d->imprimeNaTela(d->dado);
}

void imprimeEmArquivoDocumento(Documento *d, char *path)
{
    d->ImprimeEmArquivo(d->dado, path);
}