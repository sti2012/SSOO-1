//ejercicio6_6.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 20

float evaluar (float polinomio [], int grado, float x);

int main (){
    float polinomio[TAM], resultado;
    int grado, i;
    float x;

    printf("Introduzca el grado del polinomio: ");
    scanf("%d", &grado);
    i = grado;
    while (i>=0){
        printf("Introduzca el valor del coeficiente %d: ", i);
        scanf("%f", &polinomio[i]);
        i--;
    }
    printf("Introduzca el valor de x: ");
    scanf("%f", &x);
    printf("El valor del polinomio para x=%f es de:\n%f\n", x,
           evaluar (polinomio, grado, x));
    system("pause");
}

float evaluar (float polinomio [], int grado, float x){

    float resultado=0;
    while (grado>=0){
        resultado = polinomio[grado]*(pow (x,grado)) + resultado;
        grado--;
    }
    return resultado;
}
