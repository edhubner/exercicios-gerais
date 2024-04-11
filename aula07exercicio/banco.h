#ifndef _BANCO_H
#define _BANCO_H

#include "paciente.h"
#include "constantes.h"

typedef struct{
    tPaciente pacs[];
    int qtdPacs;
}tBanco;

void incluirPacienteBanco (tBanco banco, Paciente pac);

#endif