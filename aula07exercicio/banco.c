#include "banco.h"

void incluirPacienteBanco (tBanco banco, tPaciente pac)
{
    banco.pacs[banco.qtddPacs] = pac;
    banco.qtddPacs++;
}