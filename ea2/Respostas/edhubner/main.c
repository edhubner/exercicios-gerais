#include <stdio.h>
#include "data.h"

int main(void) {
    Data* d1 = criaData(15,9,2020);
    Data* d2 = leData();
    printf("Anos: %d\n", calculaDiffAnosData(d2, d1));
    liberaData(d1);
    liberaData(d2);
    return 0;
}