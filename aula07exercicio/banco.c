#include <stdio.h>
#include <string.h>
#include "banco.h"
#include "lesao.h"
#include "paciente.h"

tBanco CriaBanco()
{
    tBanco banco;
    banco.qtddPacs = 0;
    return banco;
}

void IncluirPacienteBanco(tBanco *banco, tPaciente pac)
{
    (*banco).pacs[(*banco).qtddPacs] = pac;
    (*banco).qtddPacs++;
}

// PROBLEMA NA ATUALIZACAO DA QTDD DE LESOES DO PACIENTE                                                            //////////////////////////////////
// Retorna o indice do paciente em que a lesao foi cadastrada. Retorna -1 se nao tiver encontrado paciente.
int IncluirLesaoPaciente(tBanco *banco, tLesao les)
{
    for (int i = 0; i < (*banco).qtddPacs; i++)
    {
        if (strcmp((*banco).pacs[i].cartaoSUS, les.cartaoSUS) == 0)
        {
            (*banco).pacs[i].lesoes[(*banco).pacs[i].qtddLesoes] = les;
            (*banco).pacs[i].qtddLesoes++;
            return i;
        }
    }
    return -1;
}

int MediaIdadePacs(tBanco banco)
{
    //PENDENTE                                                                                                      //////////////////////////////////
    return 9999;
}

int TotalDeLes(tBanco banco)
{
    int totalLes = 0;

    for (int i = 0; i < banco.qtddPacs; i++)
    {
        totalLes += banco.pacs[i].qtddLesoes;
        //PrintPaciente(banco.pacs[i]); // APGAR                                                                      //////////////////////////////////
        //printf("\t\t ---> LESAO: %d\n", banco.pacs[i].qtddLesoes); // APAGAR                                        //////////////////////////////////
    }

    return totalLes;
}

int TotalCirurgias(tBanco banco)
{
    int totalCirurgias = 0;

    for (int i = 0; i < banco.qtddPacs; i++)
    {
        for (int j = 0; j < banco.pacs[i].qtddLesoes; j++)
        {
            if (banco.pacs[i].lesoes[j].malig > 50)
                totalCirurgias ++;
        }
    }

    return totalCirurgias;
}

void ExibeCadastros(tBanco banco)
{
    printf("\n\n\n\nTOTAL DE PACIENTES: %d\n", banco.qtddPacs); //retirar os /n                                 //////////////////////////////////
    printf("MEDIA IDADE (ANOS): %d\n", MediaIdadePacs(banco));
    printf("TOTAL LESOES: %d\n", TotalDeLes(banco));
    printf("TOTAL CIRURGIAS: %d\n", TotalCirurgias(banco));
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < banco.qtddPacs; i++)
    {
        for (int j = 0; j < banco.pacs[i].qtddLesoes; j++)
        {
            printf("- %s - %s\n", banco.pacs[i].nome, banco.pacs[i].lesoes[j].id);
        }
    }

}