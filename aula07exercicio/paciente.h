#ifndef _PACIENTE_H
#define _PACIENTE_H

#include "constantes.h"
#include "lesao.h"

typedef struct {
    char nome[TAM_NOME];
    char dataNasc[TAM_DATA_NASC];
    char cartaoSUS[TAM_CARTAO_SUS];
    char genero;
    tLesao lesoes[TAM_QTDD_LESOES];
    int qtddLesoes;
} tPaciente;

tPaciente LerPaciente();
void PrintPaciente(tPaciente paciente);

#endif


