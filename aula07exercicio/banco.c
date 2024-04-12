#include "banco.h"

tBanco CriaBanco()
{
    tBanco banco;
    banco.qtddPacs = 0;
    return banco;
}

void IncluirPacienteBanco (tBanco *banco, tPaciente pac)
{
    (*banco).pacs[(*banco).qtddPacs] = pac;
    (*banco).qtddPacs++;
}