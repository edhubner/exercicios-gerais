#include <stdio.h>
#include <math.h>

int main (void){
    float xAlvo, yAlvo, rAlvo;
    float xTiro, yTiro, rTiro;

    scanf("%f %f %f", &xAlvo, &yAlvo, &rAlvo);
    scanf("%f %f %f", &xTiro, &yTiro, &rTiro);

    if (sqrt(pow(xAlvo - xTiro, 2) + pow(yAlvo - yTiro, 2)) <= (rAlvo + rTiro)){
        printf("ACERTOU");
    }
    else {
        printf("ERROU");
    }
    
    return 0;
}