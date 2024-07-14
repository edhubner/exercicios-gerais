#include <stdio.h>
#include "times.h"

tTime LerTime() {
    tTime time;
    scanf("%s %s", time.nome, time.conf);
    return time;
}

void ImprimeTime (tTime time) {
    printf("Time: %s Conf: %s\n", time.nome, time.conf);
}