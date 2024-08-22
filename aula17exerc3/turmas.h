#ifndef _TURMAS_H
#define _TURMAS_H

typedef struct {
    int id;
    int* notas;
} tTurma;

tTurma* CriaTurma(int id);

void LeNotasTurma(tTurma* t);

void FreeTurma(tTurma* t);

float CalculaMediaTurma (tTurma* t);

float CalculaStdTurma (tTurma* t);

#endif