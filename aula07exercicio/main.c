#include <stdio.h>
#include "banco.h"
#include "lesao.h"
#include "paciente.h"

int main(void)
{
    char op;
    tBanco bancoPacientes = CriaBanco();

    while(1)
    {
        scanf("%c\n", &op);
        if (op == 'P')
        {
            tPaciente paciente = LerPaciente();
            IncluirPacienteBanco(&bancoPacientes, paciente);
        }
        else if (op == 'L')
        {
            tLesao les = LerLesao();
            int pacIndex = IncluirLesaoPaciente(&bancoPacientes, les);
            //if (pacIndex == -1)
                //printf("-- ERRO: Paciente nao encontrado ao tentar cadastrar lesao.\n");
        }
        else if (op == 'F')
        {
            ExibeCadastros(bancoPacientes);
            break;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}
