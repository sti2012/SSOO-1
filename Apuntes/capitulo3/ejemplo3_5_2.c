//ejemplo3_5_2.c
#include <stdio.h>

int main (){
    float num1,num2;
    char operador;

    printf("Introduzca la expresi�n ");
    //lectura de un real, un car�cter y un real
    //son los dos datos a operar (reales) y la operaci�n (car�cter)
    scanf("%f%c%f",&num1,&operador,&num2);
    switch (operador){
    case '+' :{
        float suma = num1+num2;
        printf("%f\n", suma);
        break;
    }
    case '-' :{
        float resta = num1-num2;
        printf("%f\n", resta);
        break;
    }
    case '*' :{
        float multiplicacion = num1*num2;
        printf("%f\n", multiplicacion);
        break;
    }
    case '/' :{
        float division = num1/num2;
        printf("%f\n", division);
        break;
    }
    default :
        printf("Operador desconocido %c\n",operador);
    }
    system("pause");
}
