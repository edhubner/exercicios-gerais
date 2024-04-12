#ifndef _BANCO_H
#define _BANCO_H

#include "paciente.h"
#include "constantes.h"

typedef struct{
    tPaciente pacs[TAM_BANCO_PACIENTES];
    int qtddPacs;
}tBanco;

tBanco CriaBanco();
void IncluirPacienteBanco (tBanco *banco, tPaciente pac);

#endif