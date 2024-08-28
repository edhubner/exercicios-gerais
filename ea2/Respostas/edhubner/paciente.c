#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

struct Paciente {
    char *nome;            // salva o nome do paciente
    Data *dataNasc;        // salva a data de nascimento do paciente
    char *cartaoSus;       // salva o cartão do SUS do paciente
    char genero;           // salva o gênero do paciente
    Lesao **lesoes;        // salva as lesões do paciente
    int qtdLesoes;         // salva a quantidade de lesões do paciente
    int qtdLesoesAlocadas; // controla a quantidade de lesões alocadas
};

/*
Função que cria uma estrutura Paciente (alocando memória para o que for necessário), lê os valores da entrada padrão
de acordo com a descrição, e retorna o ponteiro para a estrutura criada.
*/
Paciente *lePaciente() {
    //faltou os /n nos scanfs
    Paciente* p = (Paciente*) malloc(sizeof(Paciente));

    p->nome = (char*) malloc(TAM_NOME * sizeof(char));
    scanf("%[^\n]\n", p->nome);

    p->dataNasc = leData();

    p->cartaoSus = (char*) malloc(TAM_SUS * sizeof(char));
    scanf("%[^\n]\n", p->cartaoSus);

    scanf("%c\n", &p->genero);

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
    //certo
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
    // certoooooo!!
    // if (p == NULL || l == NULL)
    //    exit('P');

    if (p->qtdLesoes == p->qtdLesoesAlocadas) {
        p->qtdLesoesAlocadas++;
        p->lesoes = (Lesao**) realloc(p->lesoes, p->qtdLesoesAlocadas * sizeof(Lesao*));
    }

    p->lesoes[p->qtdLesoes] = l;
    p->qtdLesoes++;

}

/*
Função que calcula a idade do paciente em relação a uma data de referência informada.
*/
int calculaIdadePaciente(Paciente *p, Data *ref) {
    // certo
    return calculaDiffAnosData(p->dataNasc, ref);
}

/*
Função que retorna a quantidade de cirurgias associadas a este paciente de acordo com as regras
descritas na descrição.
*/
int getQtdCirurgiasPaciente(Paciente *p) {
    // certo
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
    // certo
    return p->cartaoSus;
}

/*
Função que retorna a data de nascimento do paciente.
*/
Data *getDataNascPaciente(Paciente *p) {
    // certo
    return p->dataNasc;
}

/*
Função que retorna a quantidade de lesões do paciente
*/
int getQtdLesoesPaciente(Paciente *p) {
    // certo
    return p->qtdLesoes;
}

/*
Função que imprime o nome do paciente, seguido do IDs das lesões associadas a ele.
Ela verifica se existe lesão. Se não existir, nada é impresso.
Essa impressão segue o padrão da descrição.
*/
void imprimeIdLesoesPaciente(Paciente *p) {
    // Teria que ter verificado se existia lesao paciente!!!
    if (p->qtdLesoes > 0) {
        printf("- %s - ", p->nome);
        for (int i = 0; i < p->qtdLesoes; i++) {
            printf("%s ", getIdLesao(p->lesoes[i]));
        }
        printf("\n");
    }
}