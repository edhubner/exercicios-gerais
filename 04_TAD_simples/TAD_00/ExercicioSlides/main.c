#include <stdio.h>

int N;
char tipo;
float raio, comp, larg, base, altura;

scanf("%d\n", &N);
for (int i = 0; i < N; i++){
    scanf("%c ", &tipo);
    if (tipo == 'C'){
        scanf("%f\n", &raio);
    }
}