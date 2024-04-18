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

// Retorna o indice do paciente em que a lesao foi cadastrada. Retorna -1 se nao tiver encontrado paciente.
int IncluirLesaoPaciente(tBanco *banco, tLesao les)
{
    for (int i = 0; i < (*banco).qtddPacs; i++)
    {
        if (strcmp((*banco).pacs[i].cartaoSUS, les.cartaoSUS) == 0)
        {
            (*banco).pacs[i].lesoes[(*banco).pacs[i].qtddLesoes] = les;
            (*banco).pacs[i].qtddLesoes++;
        }
        return i;
    }
    return -1;
}