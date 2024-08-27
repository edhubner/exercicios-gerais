#include <stdlib.h>
#include <stdio.h>
#include "lesao.h"

/*
Função que cria uma estrutura Lesao (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
Lesao *leLesao() {
    // Incluiu o /n na leitura do inteiro
    Lesao* l = (Lesao*) malloc(sizeof(Lesao));
    l->id = (char*) malloc(TAM_ID * sizeof(char));
    l->diag = (char*) malloc(TAM_DIAG * sizeof(char));
    l->regiao = (char*) malloc(TAM_REG * sizeof(char));

    scanf("%[^\n]\n", l->id);
    scanf("%[^\n]\n", l->diag);
    scanf("%[^\n]\n", l->regiao);
    scanf("%d\n", &l->malignidade);

    return l;
}

/*
Função que libera a memória alocada para a estrutura Lesao.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaLesao(Lesao *l) {
    //certo
    if (l->id != NULL)
        free(l->id);

    if (l->diag != NULL)    
        free(l->diag);

    if (l->regiao != NULL)
        free(l->regiao);
    
    if (l != NULL)
        free(l);
}

/*
Função que retorna o Id da lesão passada como parâmetro.
*/
char *getIdLesao(Lesao *l) {
    //certo
    return l->id;
}

/*
Função que calcula se a lesão passada como parâmetro precisa de cirurgia de acordo com a regra
informada na descrição.
*/
int precisaCirurgiaLesao(Lesao *l) {
    // certo
    if (l->malignidade > 50)
        return 1;
    return 0;
}