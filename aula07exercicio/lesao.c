#include <stdio.h>
#include "lesao.h"

tLesao LerLesao()
{
    tLesao les;
    scanf("%[^\n]\n", les.cartaoSUS);
    scanf("%[^\n]\n", les.id);
    scanf("%[^\n]\n", les.diag);
    scanf("%[^\n]\n", les.regiao);
    scanf("%d\n", &les.malig);

    return les;
}

void PrintLesao(tLesao les){
    printf("LESAO\nles.cartaoSUS: %s\n", les.cartaoSUS);
    printf("les.id: %s\n", les.id);
    printf("les.diag: %s\n", les.diag);
    printf("les.regiao: %s\n", les.regiao);
    printf("les.malig: %d\n-\n", les.malig);
}
