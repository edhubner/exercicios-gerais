#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

/*
Função que cria uma estrutura Paciente (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
Paciente *lePaciente() {
    Paciente* p = (Paciente*) malloc(sizeof(Paciente));

    p->nome = (char*) malloc(TAM_NOME * sizeof(char));
    scanf("%[^\n]\n", p->nome);

    p->dataNasc = leData();

    p->cartaoSus = (char*) malloc(TAM_SUS * sizeof(char));
    scanf("%[^\n]\n", p->cartaoSus);

    scanf("%c", &p->genero);

    p->lesoes = (Lesao**) malloc(sizeof(Lesao*));

    p->qtdLesoes = 0;

    p->qtdLesoesAlocadas = 1;

    return p;
}

/*
Função que libera toda a memória alocada para a estrutura Paciente.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaPaciente(Paciente *p) {
    if (p->nome != NULL)
        free(p->nome);

    liberaData(p->dataNasc);

    if (p->cartaoSus != NULL)
        free(p->cartaoSus);

    for (int i = 0; i < p->qtdLesoes; i++) {
        if (p->lesoes[i] != NULL)
            liberaLesao(p->lesoes[i]);
    }

    if (p->lesoes != NULL)
        free(p->lesoes);

    if (p != NULL)
        free(p);
}

/*
Função que recebe um paciente e uma lesão e adiciona a lesão ao paciente no grupo de lesões que ele possui.
Se for necessário mais memória para alocar uma nova lesão, essa função deve realocar a memória necessária.
*/
void adicionaLesaoPaciente(Paciente *p, Lesao *l) {
    if (p->qtdLesoes == p->qtdLesoesAlocadas) {
        p->qtdLesoesAlocadas++;
        p->lesoes = (Lesao**) realloc(p->lesoes, p->qtdLesoesAlocadas * sizeof(Lesao*));
    }

    p->qtdLesoes++;
    p->lesoes[p->qtdLesoesAlocadas - 1] = l;
}

/*
Função que calcula a idade do paciente em relação a uma data de referência informada.
*/
int calculaIdadePaciente(Paciente *p, Data *ref) {
    return calculaDiffAnosData(p->dataNasc, ref);
}

/*
Função que retorna a quantidade de cirurgias associadas a este paciente de acordo com as regras
descritas na descrição.
*/
int getQtdCirurgiasPaciente(Paciente *p) {
    int qtd = 0;
    for (int i = 0; i < p->qtdLesoes; i++) {
        if (precisaCirurgiaLesao(p->lesoes[i]))
            qtd++;
    }
    return qtd;
}

/*
Função que retorna o cartão do sus do paciente.
*/
char *getCartaoSusPaciente(Paciente *p) {
    return p->cartaoSus;
}

/*
Função que retorna a data de nascimento do paciente.
*/
Data *getDataNascPaciente(Paciente *p) {
    return p->dataNasc;
}

/*
Função que retorna a quantidade de lesões do paciente
*/
int getQtdLesoesPaciente(Paciente *p) {
    return p->qtdLesoes;
}

/*
Função que imprime o nome do paciente, seguido do IDs das lesões associadas a ele.
Ela verifica se existe lesão. Se não existir, nada é impresso.
Essa impressão segue o padrão da descrição.

- SON GOKU - L1 L3

*/
void imprimeIdLesoesPaciente(Paciente *p) {
    printf("- %s - ", p->nome);
    for (int i = 0; i < p->qtdLesoes; i++) {
        printf("%s ", getIdLesao(p->lesoes[i]));
    }
    printf("\n");
}