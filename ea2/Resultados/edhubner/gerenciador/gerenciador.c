#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciador.h"

/*
Função que cria uma estrutura Gerenciador (alocando toda memória necessária), inicializa o que for necessário
e retorna o ponteiro para a estrutura criada.
*/
Gerenciador *criaGerenciador() {
    // certo
    Gerenciador* g = (Gerenciador*) malloc(sizeof(Gerenciador));
    g->bancoPacientes = (Paciente**) malloc(sizeof(Paciente*));
    g->tamBanco = 0;
    g->tamBancoAlocado = 1;
    return g;
}

/*
Função que adiciona um paciente ao banco de pacientes do gerenciador.
Se for necessário mais memória para alocar um novo paciente, essa função deve realocar a memória necessária.
*/
void adicionaPacienteBancoGerenciador(Gerenciador *g, Paciente *p) {
    //certo
    //if (g == NULL || p == NULL)
    //    exit('G');

    if (g->tamBanco == g->tamBancoAlocado) {
        g->tamBancoAlocado++;
        g->bancoPacientes = (Paciente**) realloc(g->bancoPacientes, g->tamBancoAlocado * sizeof(Paciente*));
    }
    g->tamBanco++;
    g->bancoPacientes[g->tamBancoAlocado - 1] = p;
}

/*
Função que busca e retorna um paciente (se existir) no banco de pacientes do gerenciador a partir do cartão do SUS.
Se não encontrar o paciente, retorna NULL.
*/
Paciente *getPacientePeloSUSBancoGerenciador(Gerenciador *g, char *sus) {
    // certo
    Paciente* p = NULL;

    for (int i = 0; i < g->tamBanco; i++) {
        if (strcmp(sus, getCartaoSusPaciente(g->bancoPacientes[i])) == 0) {
            p = g->bancoPacientes[i];
            break;
        }
    }
    return p;
}

/*
Função que le os dados de pacientes e lesões a partir da entrada padrão e preenche o banco de
pacientes do gerenciador. Essa leitura seguem as regras descritas na descrição.
Perceba que o banco salva apenas os pacientes, as lesões são salvas nos pacientes.
*/
void preencheBancoPacientesGerenciador(Gerenciador *ger) {
    // Acrescentou \n ao final dos Scanfs E acrescentei if (p != NULL) 
    char op = 'a';
    char* cSus;
    Paciente* p;
    Lesao* l;

    while (op != 'F') {
        scanf("%c\n", &op);
        if (op == 'P') {
            p = lePaciente();
            adicionaPacienteBancoGerenciador(ger, p);
        }
        else if (op == 'L') {
            cSus = (char*) malloc(TAM_SUS * sizeof(char));
            scanf("%[^\n]\n", cSus);
            l = leLesao();
            p = getPacientePeloSUSBancoGerenciador(ger, cSus);
            if (p != NULL)
                adicionaLesaoPaciente(p, l);
        }
        else if (op == 'F') {
            break;
        }
    }
}

/*
Função que libera a memória alocada para a estrutura Gerenciador.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaGerenciador(Gerenciador *g) {
    //
    for (int i = 0; i < g->tamBancoAlocado; i++) {
        if (g->bancoPacientes[i] != NULL)
            liberaPaciente(g->bancoPacientes[i]);
    }

    if (g->bancoPacientes != NULL)
        free(g->bancoPacientes);

    if (g != NULL)
        free(g);
}

/*
Função que calcula a média de idade dos pacientes do banco de pacientes do gerenciador.
Para isso, é necessário calcular a idade de cada paciente em relação a data de referência.
*/
int calculaMediaIdadePacientesBancoGerenciador(Gerenciador *g) {
    //
    int soma = 0;
    Data* dataAtual = criaData(DIA_BASE, MES_BASE, ANO_BASE);

    for (int i = 0; i < g->tamBanco; i++)
        soma += calculaIdadePaciente(g->bancoPacientes[i], dataAtual);
    
    return soma / g->tamBanco;
}

/*
Função que imprime os pacientes do banco de pacientes do gerenciador de acordo com a descrição.
*/
void imprimePacientesBancoGerenciador(Gerenciador *g) {
    //
    for (int i = 0; i < g->tamBanco; i++) {
        imprimeIdLesoesPaciente(g->bancoPacientes[i]);
    }
}

/*
Função que calcula a quantidade total de lesões dos pacientes do banco de pacientes do gerenciador.
Se não houver pacientes ou lesões associadas, retorna 0.
*/
int calculaQtdLesoesPacientesBancoGerenciador(Gerenciador *g) {
    //
    int totalLesoes = 0;

    for (int i = 0; i < g->tamBanco; i++) {
        totalLesoes += getQtdLesoesPaciente(g->bancoPacientes[i]);
    }

    return totalLesoes;
}

/*
Função que calcula a quantidade total de cirurgias necessárias para os pacientes do banco de pacientes do gerenciador.
Se não houver pacientes ou lesões que necessitam de cirurgia, retorna 0.
*/
int calculaQtdCirurgiaPacientesBancoGerenciador(Gerenciador *g) {
    //
    int totalCirurgias = 0;

    for (int i = 0; i < g->tamBanco; i++){
        totalCirurgias += getQtdCirurgiasPaciente(g->bancoPacientes[i]);
    }

    return totalCirurgias;
}

/*
Função que imprime o relatório do gerenciador de acordo com a descrição da atividade.
*/
void imprimeRelatorioGerenciador(Gerenciador *g) {
    //
    printf("TOTAL PACIENTES: %d\n", g->tamBanco);
    printf("MEDIA IDADE (ANOS): %d\n", calculaMediaIdadePacientesBancoGerenciador(g));
    printf("TOTAL LESOES: %d\n", calculaQtdLesoesPacientesBancoGerenciador(g));
    printf("TOTAL CIRURGIAS: %d\n", calculaQtdCirurgiaPacientesBancoGerenciador(g));
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < g->tamBanco; i++) {
        imprimeIdLesoesPaciente(g->bancoPacientes[i]);
    }
}