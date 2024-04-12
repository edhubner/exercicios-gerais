#include <stdio.h>
#include "lesao.h"
#include "paciente.h"

int main(void)
{
    char op;
    tPaciente bancoPacientes[TAM_BANCO_PACIENTES];
    int qtddPacBanco = 0;

    while(1)
    {
        scanf("%c\n", &op);
        if (op == 'P')
        {
            tPaciente paciente = LerPaciente();
            bancoPacientes[qtddPacBanco] = paciente;
            qtddPacBanco++;
            PrintPaciente(paciente);
        }
        else if (op == 'L')
        {
            tLesao les = LerLesao();
            PrintLesao(les);
        }
        else if (op == 'F')
        {
            //ExibeCadastros();
            break;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}