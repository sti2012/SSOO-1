//Módulo que implementa las operaciones con vectores
//vector.c

#include <stdio.h>
#include "vector.h"

void productoEscalar(float x1, float x2, float x3,
                     float y1, float y2, float y3){
    float resultado;
    resultado =(x1*y1)+(x2*y2)+(x3*y3);
    printf("El producto escalar es: %f \n", resultado);
}

void productoVectorial(float x1, float x2, float x3,
                       float y1, float y2, float y3){
    float z1, z2, z3;
    z1 =(x2*y3)-(x3*y2);
    z2 =-((x1*y3)-(x3*y1));
    z3 =(x1*y2)-(x2*y1);
    printf("El producto vectorial es: (%f, %f, %f)\n", z1, z2, z3);
}

void sumaVectorial(float x1, float x2, float x3,
                   float y1, float y2, float y3){
    float z1, z2, z3;
    z1 = x1 + y1;
    z2 = x2 + y2;
    z3 = x3 + y3;
    printf("La suma de los vectores es: (%f, %f, %f)\n", z1, z2, z3);
}

void restaVectorial (float x1, float x2, float x3,
                     float y1, float y2, float y3){
    float z1, z2, z3;
    z1 = x1 - y1;
    z2 = x2 - y2;
    z3 = x3 - y3;
    printf("La resta de los vectores es: (%f, %f, %f)\n", z1, z2, z3);
}
