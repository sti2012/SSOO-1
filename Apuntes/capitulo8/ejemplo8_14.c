//ejemplo8_14.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    float num1,num2;
    char operador;

    if (argc!=4){
        printf("Error en la l�nea de comandos\n\n");
        printf("Formato que debe usar:\t %s <n�mero> <operador> "
               "<n�mero>\n\n",argv[0]);
        exit(0);
    }
    num1=atof(argv[1]);
    operador = argv[2][0];//el tercer par�metro es la operaci�n
    num2=atof(argv[3]);

    switch (operador){
    case '+' :{
        float suma = num1+num2;
        printf("Resultado: %f\n", suma);
        break;
    }
    case '-' :{
        float resta = num1-num2;
        printf("Resultado: %f\n", resta);
        break;
    }
    //empleamos "�" para la multiplicaci�n y no "*" porque este segundo car�cter
    // suele tener un significado especial en las consolas
    case '�' :{
        float multiplicacion = num1*num2;
        printf("Resultado: %f\n", multiplicacion);
        break;
    }
    case '/' :{
        float division = num1/num2;
        printf("Resultado: %f\n", division);
        break;
    }
    default :
        printf("Operador desconocido %c\n",operador);
    }
    system("pause");
    return 0;
}
