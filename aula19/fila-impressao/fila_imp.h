

#ifndef _FILA_IMP_H
#define _FILA_IMP_H

#include "documento.h"

typedef struct _FilaImp FilaImp;
FilaImp *criaFilaImp();
void desalocaFilaImp(FilaImp *f);
void insereDocumentoFilaImp(FilaImp *f, void *dado, func_ptr_imprimeNaTela imprimeNaTela, func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                            func_ptr_desaloca desaloca);
int quantidadeDocumentosNaFilaImp(FilaImp *f);
void imprimeFilaImp(FilaImp *f, char *path);

#endif