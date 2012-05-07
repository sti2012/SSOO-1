//ejemplo5_1_2.c
#include <stdio.h>

float  multiplicar(float num1,float num2){
    return num1*num2;
}

int main (){
    float A = 8,B = 2, resultado;
    resultado=multiplicar(A,B);
    printf("La multiplicación es %f \n",resultado);
}
