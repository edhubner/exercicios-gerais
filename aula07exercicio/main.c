#include <stdio.h>
#include "lesao.h"
#include "paciente.h"
#include "banco.h"

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
            PrintPaciente(bancoPacientes.pacs[bancoPacientes.qtddPacs - 1]); //quebra da opacidade do TAD
            printf("---- QTDD DE PACS NO BANCO: %d\n", bancoPacientes.qtddPacs); //quebra da opacidade do TAD
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