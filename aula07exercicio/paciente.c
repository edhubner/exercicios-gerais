#include <stdio.h>
#include "paciente.h"

tPaciente LerPaciente()
{
    tPaciente paciente;
    scanf("%[^\n]\n", paciente.nome);
    scanf("%[^\n]\n", paciente.dataNasc);
    scanf("%[^\n]\n", paciente.cartaoSUS);
    scanf("%c\n", &paciente.genero);
    paciente.qtddLesoes = 0;
    return paciente;
}

void PrintPaciente(tPaciente paciente)
{
    printf("PACIENTE\npaciente.dataNasc: %s\n", paciente.dataNasc);
    printf("paciente.cartaoSUS: %s\n", paciente.cartaoSUS);
    printf("paciente.genero: %c\n", paciente.genero);
    printf("paciente.nome: %s\n", paciente.nome);
    printf("paciente.qttdLesoes: %d\n----------\n", paciente.qtddLesoes);
}
