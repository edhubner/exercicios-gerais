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
            //PrintPaciente(bancoPacientes.pacs[bancoPacientes.qtddPacs - 1]); //quebra da opacidade do TAD
            //printf("---- QTDD DE PACS NO BANCO: %d\n", bancoPacientes.qtddPacs); //quebra da opacidade do TAD
        }
        else if (op == 'L')
        {
            tLesao les = LerLesao();
            int pacIndex = IncluirLesaoPaciente(&bancoPacientes, les);
            if (pacIndex == -1)
            {
                printf("-- ERRO: Paciente nao encontrado ao tentar cadastrar lesao.\n");
                return -1;
            }
            //printf("\t\t ----- LESAO NO BANCO\n");
            //PrintLesao(bancoPacientes.pacs[pacIndex].lesoes[bancoPacientes.pacs[pacIndex].qtddLesoes - 1]);
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
