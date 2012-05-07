//ejemplo5_6_2.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dobleMaximo.h"

int main (){
    srand(time(NULL));
    float resultado, dato1=rand()% 11, dato2=rand()% 11;
    resultado = calculo(dato1, dato2);
    printf("El resultado es %f", resultado);
    system("pause");
    return 0;
}
