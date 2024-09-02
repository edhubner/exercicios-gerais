

#include <stdlib.h>
#include "fila_imp.h"

struct _FilaImp
{
    Documento **docs;
    int qntd;
};

FilaImp *criaFilaImp()
{
    FilaImp *f = (FilaImp *)malloc(sizeof(FilaImp));
    f->docs = NULL;
    f->qntd = 0;
    return f;
}

void desalocaFilaImp(FilaImp *f)
{
    for (int i = 0; i < f->qntd; i++)
    {
        desalocaDocumento(f->docs[i]);
    }
    if (f->docs != NULL)
    {
        free(f->docs);
    }
    free(f);
}

void insereDocumentoFilaImp(FilaImp *f, void *dado, func_ptr_imprimeNaTela imprimeNaTela, func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                            func_ptr_desaloca desaloca)
{

    Documento *d = criaDocumento(dado, imprimeNaTela, ImprimeEmArquivo, desaloca);

    f->docs = (Documento **)realloc(f->docs, sizeof(Documento *) * (f->qntd + 1));
    f->docs[f->qntd] = d;
    f->qntd++;
}

int quantidadeDocumentosNaFilaImp(FilaImp *f)
{
    return f->qntd;
}

/**
 * Função que imprime toda a fila de impressão
 * Obviamente, se não houver elementos na fila, a função não deve fazer nada.
 */
void imprimeFilaImp(FilaImp *f, char *path)
{
    for (int i = 0; i < f->qntd; i++)
    {
        imprimeNaTelaDocumento(f->docs[i]);
        imprimeEmArquivoDocumento(f->docs[i], path);
    }
}
