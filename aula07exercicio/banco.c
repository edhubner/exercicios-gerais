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

typedef struct{
    int dia;
    int mes;
    int ano;
} tData;

void IncluirPacienteBanco(tBanco *banco, tPaciente pac)
{
    (*banco).pacs[(*banco).qtddPacs] = pac;
    (*banco).qtddPacs++;
}

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

tData StringToDate(char *sDate)
{
    tData data;
    sscanf(sDate, "%d/%d/%d", &data.dia, &data.mes, &data.ano);
    return data;
}

int CalculaIdadePac(tPaciente pac)
{
    tData d1 = StringToDate(DATA_ATUAL);
    tData d2 = StringToDate(pac.dataNasc);
    
    if ((d1.mes > d2.mes) || (d1.mes == d2.mes && d1.dia >= d2.dia))
    {
        return d1.ano - d2.ano;
    }
    else
    {
        if ((d1.ano - d2.ano) == 0)
            return 0;
        else
            return d1.ano - d2.ano - 1;
    }
}

int MediaIdadePacs(tBanco banco)
{
    int media = 0;

    for (int i = 0; i < banco.qtddPacs; i++)
    {
        media += CalculaIdadePac(banco.pacs[i]);
    }

    if (banco.qtddPacs > 0)
        media /= banco.qtddPacs;
    else
        media = 0;

    return media;
}

int TotalDeLes(tBanco banco)
{
    int totalLes = 0;

    for (int i = 0; i < banco.qtddPacs; i++)
    {
        totalLes += banco.pacs[i].qtddLesoes;
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
    printf("TOTAL PACIENTES: %d\n", banco.qtddPacs);
    printf("MEDIA IDADE (ANOS): %d\n", MediaIdadePacs(banco));
    printf("TOTAL LESOES: %d\n", TotalDeLes(banco));
    printf("TOTAL CIRURGIAS: %d\n", TotalCirurgias(banco));
    printf("LISTA DE PACIENTES:");
    for (int i = 0; i < banco.qtddPacs; i++)
    {
                for (int j = 0; j < banco.pacs[i].qtddLesoes; j++)
        {
            printf("\n");
            printf("- %s - %s", banco.pacs[i].nome, banco.pacs[i].lesoes[j].id);
        }
    }

}