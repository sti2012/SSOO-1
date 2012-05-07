//ejemplo2_6.c
#include "stdio.h"

int main (){
    char caracter = 'a'; //variable tipo car�cter
    char caracter2 = 98; //inicializado mediante un n�mero
    int entero = -5; //variable tipo int
    int octal = 075; //expresada en base octal
    int hexadecimal = 0x7fffffff; //expresada en hexadecimal
    /*el entero anterior en binario ser�a un cero seguido de
    31 1s, es por tanto el mayor entero (int) representable en C*/
    const int constante = 8;
    //constante = 10; error de compilaci�n puesto que se est�
    //modificando una variable constante
    long enteroLargo = 5L; //variable tipo long
    unsigned short enteroCortoSinSigno = 5;//variable de tipo usigned short
    float real = 5.0F; //variable de tipo float
    double realLargo = 5.5; //variable de tipo double

    printf("Car�cter%c\n", caracter);
    printf("Valor entero del car�cter %d\n", caracter);
    printf("Valor entero del segundo car�cter %d\n", caracter2);
    printf("Su car�cter correspondiente %c\n", caracter2);
    printf("Entero %d\n", entero);
    printf("Entero expresado en octal %d\n", octal);
    printf("Entero m�s largo %d\n", hexadecimal);
    printf("Entero largo %ld\n", enteroLargo);
    printf("Entero corto sin signo %d\n", enteroCortoSinSigno);
    printf("Real %f\n", real);
    printf("Real largo %f\n", realLargo);
    system ("pause");
}

