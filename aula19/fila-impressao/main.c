

#include <stdio.h>
#include "receita.h"
#include "documento.h"
#include "fila_imp.h"

int main()
{

    // Aqui o exemplo tem apenas receitas. Mas a ideia é que funcione com qualquer tipo de documento do trabalho
    Receita *r1 = criaReceita("Dipirona", 2);
    Receita *r2 = criaReceita("Paracetamol", 3);
    Receita *r3 = criaReceita("Rivotril", 100);

    // Aqui é o exemplo de como a fila de impressão deve funcionar
    FilaImp *fila = criaFilaImp();

    // Agora a gente insere os elementos na fila de impressão. Neste exemplo tem só receita,
    // mas poderia ser qualquer um, uma vez que a fila é genérica
    insereDocumentoFilaImp(fila, r1, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);
    insereDocumentoFilaImp(fila, r2, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);
    insereDocumentoFilaImp(fila, r3, imprimeNaTelaReceita, imprimeEmArquivoReceita, desalocaReceita);

    // Quando o usuário quiser, ele pode imprimir a fila toda
    imprimeFilaImp(fila, "/home/impressoes");

    // Desalocando a fila de impressão
    desalocaFilaImp(fila);

    return 0;
}