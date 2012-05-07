//ejemplo5_1_1.c
#include <stdio.h>

int main (){
    float A = 8,B = 2, resultado;
    resultado=multiplicar(A,B);
    printf("La multiplicación es %f \n",resultado);
}

float  multiplicar(float num1,float num2){
    return num1*num2;
}
