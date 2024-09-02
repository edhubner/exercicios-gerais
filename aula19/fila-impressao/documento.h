

#ifndef _DOCUMENTO_H
#define _DOCUMENTO_H

typedef struct _Documento Documento;
typedef void (*func_ptr_imprimeNaTela)(void *dado);
typedef void (*func_ptr_imprimeEmArquivo)(void *dado, char *path);
typedef void (*func_ptr_desaloca)(void *dado);

Documento *criaDocumento(void *dado, func_ptr_imprimeNaTela imprimeNaTela, func_ptr_imprimeEmArquivo ImprimeEmArquivo,
                         func_ptr_desaloca desaloca);
void desalocaDocumento(Documento *doc);
void imprimeNaTelaDocumento(Documento *doc);
void imprimeEmArquivoDocumento(Documento *doc, char *path);

#endif