//ejemplo6_3.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUMERO_DATOS 10

int main (){
    float datos[NUMERO_DATOS];
    float media= 0.0;
    float *punteroDatos;
    int   j;
    //inicializamos el puntero
    //esta sentencia es equivalente a "punteroDatos = datos;"
    punteroDatos = &datos [0];

    for (j = 0; j < NUMERO_DATOS; j++){
        printf("Introduzca el dato número %d: ", j+1);
        scanf("%f", punteroDatos);
        punteroDatos ++;
    }

    for (j = NUMERO_DATOS; j >0; j--){
        //el puntero quedó situado una posición más allá del último dato
        punteroDatos--;
        printf("El cuadrado de %f es %f\n",
               *punteroDatos, pow (*punteroDatos,2));
    }
    system("pause");
}
