#include <stdio.h>
#include "aluno.h"

int main (void)
{
    int qtddAlunos = 0;
    int qtddAprovados = 0;
    tAluno alTemp;
    scanf("%d", &qtddAlunos);
    tAluno alunos[qtddAlunos];

    for (int i = 0; i < qtddAlunos; i++)
    {
        alTemp = LeAluno();
        if (VerificaAprovacao(alTemp))
        {
            alunos[qtddAprovados] = alTemp;
            qtddAprovados++;
        }
    }

    for (int i = 0; i < qtddAprovados - 1; i++)
    {
        for (int j = i + 1; j < qtddAprovados; j++)
        {
            if (ComparaMatricula(alunos[i], alunos[j]) == 1)
            {
                alTemp = alunos[j];
                alunos[j] = alunos[i];
                alunos[i] = alTemp;
            }
        }
    }

    for (int i = 0; i < qtddAprovados; i++)
        ImprimeAluno(alunos[i]);

    return 0;
}