//Módulo que implementa las operaciones con vectores
//vector.c
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

float productoEscalar(float vector1[], float vector2[]){
    float resultado;
    resultado =(vector1[0]*vector2[0])+
               (vector1[1]*vector2[1])+(vector1[2]*vector2[2]);
    return resultado;
}

float* productoVectorial(float vector1[], float vector2[]){
    float* resultado = (float *)malloc(3*sizeof(float));
    resultado[0] =(vector1[1]*vector2[2])-(vector1[2]*vector2[1]);
    resultado[1] =-((vector1[0]*vector2[2])-(vector1[2]*vector2[0]));
    resultado[2] =(vector1[0]*vector2[1])-(vector1[1]*vector2[0]);
    return resultado;
}

float* sumaVectorial(float vector1[], float vector2[]){
    float* resultado = (float *)malloc(3*sizeof(float));
    resultado[0] = vector1[0] + vector2[0];
    resultado[1] = vector1[1] + vector2[1];
    resultado[2] = vector1[2] + vector2[2];
    return resultado;
}

float* restaVectorial (float vector1[], float vector2[]){
    float* resultado = (float *)malloc(3*sizeof(float));
    resultado[0] = vector1[0] - vector2[0];
    resultado[1] = vector1[1] - vector2[1];
    resultado[2] = vector1[2] - vector2[2];
    return resultado;
}