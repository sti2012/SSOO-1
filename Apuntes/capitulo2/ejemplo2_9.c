//ejemplo2_9.c
#include <stdio.h>

int main (){
    int entero = 1000;
    char enteroChar;
    float real = 47.5F;
    double realLargo = 1E200;

    printf("entero: %i, real: %f\n",entero,real);
    //asignación cuyo resultado será impredecible
    enteroChar = entero;
    printf("real: %i, enteroChar: %i\n",entero,enteroChar);
    //el valor del dato double supera el rango del float
    real = realLargo;
    printf("real: %f, realLargo: %f\n",real,realLargo);
    system ("pause");
}

